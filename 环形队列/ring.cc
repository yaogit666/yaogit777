#include<iostream>
#include<unistd.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

class RingQueue{
	private:
		vector<int> buf;
		int cap;
		sem_t sem_blank;
		sem_t sem_data;

		int c_step;
		int p_step;
	private:
		void P(sem_t &s)
		{
			sem_wait(&s);
		}
		void V(sem_t &s)
		{
			sem_post(&s);
		}
	public:
		RingQueue(int cap_ = 1024)
			:cap(cap_),
			buf(cap_)
		{
			c_step = p_step = 0;
			sem_init(&sem_blank, 0, cap);
			sem_init(&sem_data, 0, 0);
		}
		void PopData(int &data)
		{
			P(sem_data);
			data = buf[c_step];
			c_step ++;
			c_step %= cap;	
			V(sem_blank);
		}
		void PushData(const int &data)
		{
			P(sem_blank);
			buf[p_step] = data;
			p_step ++;
			p_step %= cap;	
			V(sem_data);
		}
		~RingQueue()
		{
			sem_destroy(&sem_blank);
			sem_destroy(&sem_data);
		}
};

void *ConsumerRun(void *arg)
{
	int data;
	RingQueue *q = (RingQueue*)arg;
	while(1)
	{
		q->PopData(data);
		cout << "consumer data is: " <<data <<endl;
	}
}

void *ProducterRun(void *arg)
{
	RingQueue *q = (RingQueue*)arg;
	while(1)
	{
		int data = rand()%100 +1;
		usleep(1000000);
		q->PushData(data);	
		cout << "porducter data is: " <<data <<endl;
	}
}


int main()
{
	srand((unsigned long)time(NULL));
	RingQueue *q = new RingQueue(8);

	pthread_t c;
	pthread_t p;

	pthread_create(&c, nullptr, ConsumerRun, (void*)q);
	pthread_create(&p, nullptr, ProducterRun, (void*)q);

	pthread_join(c,nullptr);
	pthread_join(p,nullptr);

	delete q;

	return 0;
}
