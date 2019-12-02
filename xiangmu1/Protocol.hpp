#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<utility>
#include<unistd.h>
#include<stdlib.h>
#include<unordered_map>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<sys/sendfile.h>
#include<sys/wait.h>
#include"Util.hpp"
using namespace std;

#define WWW "./wwwroot"

class HttpRequest{
	private:
		string request_line;
		string request_header;
		string request_blank;
		string request_body;
	private:
		string method;
		string uri;
		string version;

		
		string path;
		string query_string;

		unordered_map<string,string> header_kv;

		bool cgi;
		int recource_size;

		string suffix;
	public:
		HttpRequest()
			:request_blank("\n"),
			path(WWW),
			recource_size(0),
			cgi(false)
		{
			
		}
		string &GetRequestHeader()
		{
			return request_header;
		}
		string &GetRequestLine()
		{
			return request_line;
		}
		string &GetRequestBody()
		{
			return request_body;
		}
		string GetPath()
		{
			return path;
		}
		string &GetMethod()
		{
			return method;
		}
		string &GetQueryString()
		{
			return query_string;
		}
		bool MethodIsLegal()
		{
			
			//GET || POST
			if(method != "GET" && method != "POST")
			{
				return false;
			}

			return true;
		}
		int GetRecourceSize()
		{
			return recource_size;
		}
		string GetSuffix()
		{
			return suffix;
		}
		void RequestLineParse()
		{
			stringstream ss(request_line);
			ss >> method >> uri >> version ;

			Util::StringToUpper(method);

			cout <<"method "<< method <<endl;
			cout <<"uri " <<uri<<endl;
			cout <<"version "<<version <<endl;

		}
		void RequestHeaderParse()
		{
			vector<string> v;
			Util::TransformToVector(request_header, v);

			auto it = v.begin();
			for(;it != v.end();it++)
			{
				string k;
				string v;
				Util::MakeKV(*it, k , v);
				header_kv.insert(make_pair(k,v));
				cout << "key: " << k<<endl;
				cout << "value: " << v <<endl;
			}
		}
		void UriParse()
		{
			if(method == "POST")
			{
				cgi = true;
				path += uri;
			}
			else
			{
				size_t pos = uri.find('?');
				if(string::npos == pos)
				{
					path += uri;
				}
				else
				{
					cgi = true;
					path += uri.substr(0,pos);
					query_string = uri.substr(pos+1);
				}
			}
			if(path[path.size()-1] == '/')
			{
				path += "index.html";
			}
			size_t pos = path.rfind(".");
			if(string::npos == pos)
			{
				suffix = "index.html";
			}
			else
			{
				suffix = path.substr(pos);
			}
			cout << " debug : suffix: " << suffix <<endl;
		}
		bool IsPathLegal()
		{
			struct stat st;
			if(stat(path.c_str(), &st) ==0)
			{
				if(S_ISDIR(st.st_mode))
				{
					path += "/index.html";
				}
				else
				{
					if((st.st_mode & S_IXUSR) || (st.st_mode & S_IXGRP) ||(st.st_mode & S_IXOTH))
					{
						cgi = true;
					}
				}
				recource_size = st.st_size;
				return true;
			}
			else
			{
				return false;
			}
		}
		bool IsNeedRecv()
		{
			return method == "POST";
		}
		int GetContentLength()
		{
			auto it = header_kv.find("Conten_Length");
			if(it == header_kv.end())
			{
				return -1;
			}
			return Util::StringToInt(it->second);
		}
		bool IsCgi()
		{
			return cgi;
		}

	    ~HttpRequest()
		{

		}

};

class HttpResponse{
	private:
		string response_line;
	    string response_header;
	    string response_blank;
		string response_body;	   
	private:
		int fd;
		int size;
	public:
		HttpResponse()
			:response_blank("\r\n"),
			fd(-1)
		{

		}
		void MakeResponseLine(int code)
		{
			response_line = "HTTP/1.1";
			response_line += " ";
			response_line += Util :: IntToString(code);
			response_line += " ";
			response_line += Util :: CodeToDec(code);
			response_line += "\r\n";
		}
		void MakeResponseHeader(vector<string> &v)
		{
			auto it = v.begin();
			for(;it != v.end();it++)
			{
				response_header += *it;
			    response_header += "\r\n";	
			}

		}
		void MakeResponse(HttpRequest *rq,int code, bool cgi)
		{
			MakeResponseLine(code);
			vector<string> v;
			if(cgi)
			{
				string ct = Util::SuffixToType("");
				v.push_back(ct);
				string cl = "Content_Length: ";
				cl += Util::IntToString(response_body.size());
				v.push_back(cl);
				MakeResponseHeader(v);
			}
			else
			{	
				string suffix = rq->GetSuffix();
				size = rq ->GetRecourceSize();

				string ct = Util :: SuffixToType(suffix);
				v.push_back(ct);
				string cl = "Content-Length: ";
				cl += Util::IntToString(size);
				v.push_back(cl);

				MakeResponseHeader(v);
				string path = rq->GetPath();
				cout << "debug: " << path << endl;
				fd = open(path.c_str(),O_RDONLY);
			}
		}
		string &GetResponseLine()
		{
			return response_line;
		}
		string &GetResponseHeader()
		{
			return response_header;
		}
		string &GetResponseBlank()
		{
			return response_blank;
		}
		string &GetResponseBody()
		{
			return response_body;	   
		}
		int GetFd()
		{
			return fd;
		}
		int GetCourceSize()
		{
			return size; 
		}
		~HttpResponse()
		{
			if(fd != -1)
			{
				close(fd);
			}
		}
};

class Endpoint{
		private:
			int sock;
		public:
			Endpoint(int _sock)
				:sock(_sock)
			{

			}
		 	int RecvLine(string &line)//\n \n \r\n
			{
				char c = 'X';
				while(c != '\n')
				{
					ssize_t s = recv(sock, &c, 1, 0);
					if(s > 0)
					{
						if(c == '\r')//\r or \r\n
						{
							if(recv(sock, &c, 1, MSG_PEEK)>0)
							{
								if(c == '\n')//\r\n
								{
									recv(sock , &c, 1 ,0);
								}
								else//\r
								{
									c = '\n';
								}
                            
							}
							else
							{
								c = '\n';
							}
						}
						line.push_back(c);
					}
					else
					{
						c='\n';
						cout << "recv error: " << s <<endl;
						line.push_back(c);
					}

				}	
				return line.size();
			}
			void RecvRequestLine(HttpRequest *rq)
		    {
				RecvLine(rq -> GetRequestLine()); 
			}
			void RecvRequestHeader(HttpRequest *rq)
			{
				string &rh = rq -> GetRequestHeader();
				do{
					string line  = "";
					RecvLine(line);
					if(line == "\n")
					{
						break;
					}
					rh += line;

				}while(1);
			}
			void RecvRequestBody(HttpRequest *rq)
			{
				int lenth = rq -> GetContentLength();	
				string &body = rq -> GetRequestBody();
				char c;
				while(lenth --)
				{
					if(recv(sock, &c, 1, 0)>0)
					{
						body.push_back(c);
					}
				}	
				cout << "body: " << body <<endl	;
			}
			void SendResponse(HttpResponse *rsp, bool cgi)
			{
				string &response_line = rsp->GetResponseLine();
				string &response_header = rsp->GetResponseHeader();
				string &response_blank = rsp->GetResponseBlank();
				send(sock, response_line.c_str(), response_line.size(),0);
				send(sock, response_header.c_str(), response_header.size(),0);
				send(sock, response_blank.c_str(), response_blank.size(),0);
				if(cgi)
				{
					string &response_body = rsp->GetResponseBody();
					send(sock, response_body.c_str(),response_body.size(),0);					
				}
				else
				{
					int fd = rsp->GetFd();
			 	    int size = rsp -> GetCourceSize();

					sendfile(sock, fd, NULL, size);
				}

			}
			~Endpoint()
			{
				close(sock);
			}
};

class Entry{
	public:
		static int ProcessCgi(HttpRequest *rq, HttpResponse *rsp)
		{
			int code = 200;

			string path = rq->GetPath();
			string &body = rq->GetRequestBody();
			string &method = rq->GetMethod();
			string &query_string = rq->GetQueryString();
			int content_length = rq->GetContentLength();

			string cont_len_env = "CONTENT_LENGTH=";
			string method_env = "METHOD=";
			method_env += method;

			string query_string_env = "QUERY_STRING=";
			query_string_env += query_string;

			string &rsp_body = rsp->GetResponseBody();

			int input[2]={0};
			int output[2]={0};

			pipe(input);
			pipe(output);

			pid_t id = fork();
			if(id <0)
			{
				code = 404;
			}
			else if(id ==0)
			{
				close(input[1]);
				close(output[0]);

				dup2(input[0],0);
				dup2(output[1],1);

				putenv((char*)method_env.c_str());
				if(method == "POST")
				{
					cont_len_env += Util::IntToString(content_length);
					putenv((char*)cont_len_env.c_str());
				}
				else if(method == "GET")
				{
					putenv((char*)query_string_env.c_str());
				}
				else
				{
				}
				execl(path.c_str(),path.c_str(),nullptr);
				exit(1);
			}
			else
			{
				close(input[0]);
				close(output[1]);
				if(method == "POST")
				{
					auto it = body.begin();
					for(;it!=body.end();it++)
					{
						char c = *it;
						write(input[1], &c, 1);
					}
				}

				char c;
				while(read(output[0],&c,1)>0)
				{
					rsp_body.push_back(c);
				}
				waitpid(id,NULL,0);
			}
			return code;
		}

		static void* HandlerRequest(void* args)
		{
			int code = 200;
			int *p = (int *)args;
			int sock = *p;
			Endpoint *ep = new Endpoint(sock);
			HttpRequest *rq = new HttpRequest();
			HttpResponse *rsp = new HttpResponse();

			ep -> RecvRequestLine(rq);
			rq -> RequestLineParse();
			if(!rq->MethodIsLegal())
			{
				code = 404;
				goto end;
			}
			ep->RecvRequestHeader(rq);
			rq->RequestHeaderParse();
			if(rq->IsNeedRecv())
			{
				ep->RecvRequestBody(rq);
			}
			
			rq->UriParse();
			if(! rq->IsPathLegal())
			{
				code = 404;
				goto end;
		}
			if(rq->IsCgi())
			{
				code = ProcessCgi(rq,rsp);
				rsp->MakeResponse(rq,code,true);
				ep->SendResponse(rsp,true);
			}
			else
			{
				rsp -> MakeResponse(rq, code,false);
				ep -> SendResponse(rsp, false);
			}


end:
			delete rq;
			delete rsp;
			delete ep;
			delete p;

		}	
};
