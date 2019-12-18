#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<queue>
using namespace std;

class Task{
	private:
		int x;
		int y;
	public:
		Task ()
		{
			x= 0;
			y = 0;
		}
		Task(int x_, int y_)
			:x(x_),
			y(y_)
		{}
		int Run()
		{
			return x+y;
		}
		~Task()
		{}
};

class ThreadPool{
	private:
		int num;
		queue<Task> q;
		pthread_mutex_t lock;
		pthread_cond_t cond;
	public:
		void LockQueue()
		{
			pthread_mutex_lock(&lock);
		}
		void UnlockQueue()
		{
			pthread_mutex_unlock(&lock);
		}
		bool IsQueueEmpty()
		{
			return q.size() ==0 ? true : false;
		}
		void PthreadWait()
		{
			pthread_cond_wait(&cond, &lock);
		}
		void PopTask(Task &t)
		{
			t = q.front();
			q.pop();
		}
		void  Push(Task &t)
		{
			q.push(t);
		}
		void NotifyThreaad()
		{
			pthread_cond_signal(&cond);
		}
	public:
		ThreadPool(int num_ = 6)
			:num(num_)
		{
			pthread_mutex_init(&lock, nullptr);
			pthread_cond_init(&cond, nullptr);
		}
		static void *HandlerTask(void* arg)
		{
			pthread_detach(pthread_self());
			ThreadPool *tp = (ThreadPool*) arg;
			for(;;)
			{
				tp->LockQueue();
				if(tp->IsQueueEmpty())
				{
					tp->PthreadWait();
				}
				Task t;
				tp->PopTask(t);
				tp->UnlockQueue();
				int result = t.Run();
				cout << "Thread: " <<pthread_self()<<", result: " <<result<<endl;
			}
		}
		void Init()
		{
			pthread_t tid;
			int i = 0;
			for(; i < num ; i++)
			{
				pthread_create(&tid, nullptr, HandlerTask, (void*) this); 
			}
		}
		void Add(Task &t)
		{
			LockQueue();
			Push(t);
			UnlockQueue();
			NotifyThreaad();
		}
		~ThreadPool()
		{
			pthread_mutex_destroy(&lock);
			pthread_cond_destroy(&cond);
		}
};



int main()
{
	ThreadPool *tp = new ThreadPool(5);
	tp ->Init();
	int count = 0;
	for(;;)
	{
		int x = count+1;
		int y = count+2;
		count++;
		Task t(x,y);
		tp->Add(t);
		sleep(1);
	}
	return 0;
}
