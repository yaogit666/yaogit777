#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>

using namespace std;

namespace bit
{
	class string
	{
	public:
		typedef char* Iterator;
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				assert(str);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(new char[s._capacity + 1]),
			_capacity(s._capacity),
			_size(s._size)
		{
			strcpy(_str, s._str);
		}
		~string()
		{
			if (_str)
			{
				delete [] _str;
				_str = nullptr;
			}
		}
		string & operator= (const string& s)
		{
			if (this != &s)
			{
				char* pStr = new char[s._capacity + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		Iterator Begin()
		{
			return _str;
		}
		Iterator End()
		{
			return _str + _size;
		}
		void Reserve(size_t NewCapacity)
		{
			if (NewCapacity > _capacity)
			{
				char *pStr = new char[NewCapacity];
				strcpy(pStr, _str);
				delete[] _str;
				_str = pStr;
				_capacity = NewCapacity;
			}
		}
		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string & operator +=(char c)
		{
			PushBack(c);
			return *this;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(string& s)
		{
			swap(_size, s._size);
			swap(_capacity, s._capacity);
			swap(_str, s._str);
		}
	private:
		friend ostream& operator << (ostream& _this, const bit :: string& s);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

ostream& bit :: operator<<(ostream& _this, const bit::string& s)
{
	cout << s._str;
	return _this;
}




int main()
{
	bit::string s1("hello ");
	s1.PushBack('b');
	s1.PushBack('i');
	s1 += 't';
	cout << s1 << endl;
	

	return 0;
}

