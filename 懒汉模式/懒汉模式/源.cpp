template <typename T>
class Singleton
{
	volatile static T* data;
	static std::mutex lock;
public:
	static T* GetInstance()
	{
		if (data == NULL)
		{
			lock.lock();
			if (data == NULL)
				data = new T();
			lock.unlock();
		}
		return data;
	}
};