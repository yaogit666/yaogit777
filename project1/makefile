.PHONY:all
all:HttpServer testCgi

testCgi:testCgi.cc
	g++ -o $@ $^ 
HttpServer:HttpServer.c
	g++ -o $@ $^ -lpthread -std=c++11

.PHONY:clean
clean:
	rm -f HttpServer testCgi
