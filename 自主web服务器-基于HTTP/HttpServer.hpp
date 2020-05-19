#pragma once

#include<iostream>
#include<pthread.h>
#include"Protocol.hpp"
#include"Util.hpp"

using namespace std;

class Sock{
	private:
		int sock;
		int port;
	public:
		Sock(const int &_port)
			:sock(-1),
			port(_port)
		{

		}
		void Socket()
		{
			sock = socket(AF_INET, SOCK_STREAM, 0);
			if(sock < 0)
			{
				cerr << "socket error" <<endl;
				exit(2);
			}

			int opt = 1;
			setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		}

		void Bind()
		{

			struct sockaddr_in local;

			local.sin_family = AF_INET;
			local.sin_port = htons(port);
			local.sin_addr.s_addr = htonl(INADDR_ANY);

			if(bind(sock, (struct sockaddr*)&local, sizeof(local))<0)
			{
				cerr << "bind error" <<endl;
				exit(3);
			}

		}

		void Listen()
		{
			if(listen(sock, 10) < 0)
			{
				cerr << "listen error" <<endl;
				exit(4);
			}
		}

		int Accept()
		{
			struct sockaddr_in peer;
			socklen_t len = sizeof(peer);
			int fd = accept(sock, (struct sockaddr*)&peer, &len);
			if(fd < 0)
			{
				cerr << "accept error" <<endl;
				return -1;
			}
			cout << "new link..." <<endl;
			return fd;
		}


		~Sock()
		{
			if(sock >= 0)
			{
				close(sock);
			}
		}
};

#define DEFAULT_PORT 8080
class HttpServer{
	private:
		Sock sock;
	public:
		HttpServer(int port = DEFAULT_PORT)
			:sock(port)
		{

		}
		void InitHttpServer()
		{
			sock.Socket();
			sock.Bind();
			sock.Listen();
		}
		void Start()
		{
			for(;;)
			{
				int sock_ = sock.Accept();
				if(sock_ >0)
				{
					int *p = new int(sock_);
					pthread_t tid;
					pthread_create(&tid, nullptr, Entry::HandlerRequest, p);
				}
			}
		}
};
