#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

using namespace std;

void *thread_routine(void* arg)
{
	string str = (char*)arg;
	while(1)
	{
		cout << str << "run"<< "pid: "<< getpid()<<endl;
		sleep(1);
	}
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_routine, (void*)"thread 1");
	pthread_create(&tid, NULL, thread_routine, (void*)"thread 2");
	pthread_create(&tid, NULL, thread_routine, (void*)"thread 3");
	pthread_create(&tid, NULL, thread_routine, (void*)"thread 4");
	while(1)
	{
		cout << "main thread run" << "pid: " <<getpid()<<endl;
		sleep(2);
	}
	return 0;
}
