#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<queue>
#include<time.h>
#include<stdlib.h>

using namespace std;

class BlockQueue
{
	private:
		queue<int> q;
		int cap;
		pthread_mutex_t lock;
		pthread_cond_t c_cond;
		pthread_cond_t p_cond;
	private:
		void LockQueue()
		{
			pthread_mutex_lock(&lock);
		}
		void UnlockQueue()
		{
			pthread_mutex_unlock(&lock);
		}
		bool QueueIsFull()
		{
			return q.size() == cap;
		}
		bool QueueIsEmpty()
		{
			return q.size() == 0;
		}
		void SignalConsumer()
		{
			cout << "signal c" <<endl; 
			pthread_cond_signal(&c_cond);
		}
		void SignalProducter()
		{
			cout << "signal p" <<endl;
			pthread_cond_signal(&p_cond);
		}
		void ProducterWait()
		{
			cout << "producter is wait ..." <<endl;
			pthread_cond_wait(&p_cond, &lock);
		}
		void ConsumerWait()
		{
			cout <<"consumer is wait ..." <<endl;
			pthread_cond_wait(&c_cond, &lock);
		}
	public:
		BlockQueue(int cap_ = 4)
			:cap(cap_)
		{
			pthread_mutex_init(&lock, nullptr);
			pthread_cond_init(&c_cond,nullptr);
			pthread_cond_init(&p_cond,nullptr);
		}
		//producter
		void PushData(int data)
		{
			LockQueue();
			if(QueueIsFull())
			{
				cout << "queue is full" <<endl;
				SignalConsumer();
				ProducterWait();
			}
			q.push(data);
			UnlockQueue();
		}
		//Consumer
		void PopData(int &out)
		{
			LockQueue();
			if(QueueIsEmpty())
			{
				cout << "queue is empty" <<endl;
				SignalProducter();
				ConsumerWait();
			}
			out = q.front();
			q.pop();
			UnlockQueue();
		}
		~BlockQueue()
		{
			pthread_mutex_destroy(&lock);
			pthread_cond_destroy(&c_cond);
			pthread_cond_destroy(&p_cond);
		}
};

void* consumer(void *arg)
{
	int data;
	BlockQueue *q = (BlockQueue *)arg;
	while(1)
	{
		q -> PopData(data);
		cout << "consumer data: "<<data<<endl;
	}
}
void* producter(void *arg)
{
	BlockQueue *q = (BlockQueue *)arg;
	while(1)
	{
		int data = rand()%100 +1;
		q -> PushData(data);
	    cout << "producter data is: "<<data<<endl;
		sleep(1);
	}
}

int main()
{
	srand((unsigned long)time(nullptr));
	BlockQueue *q = new BlockQueue();
	pthread_t c,p;
	pthread_create(&c, nullptr, consumer, (void*)q);
	pthread_create(&p, nullptr, producter, (void*)q);

	pthread_join(p,nullptr);
	pthread_join(c,nullptr);
}
