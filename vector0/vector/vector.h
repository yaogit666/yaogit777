#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}

		vector(const vector<T> & v)
		{
			_start = new T[v.size()];
			memcpy(_start, v._start, sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}

		vector<T> &operator = (vector<T> v)
		{
			swap(v);
			return *this;
		}

		void swap(vector<T> v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_end_of_storage, v._end_of_storage);
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage;
			}
		}
		
		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			if (n < size())
			{
				_finish = _start + n;
				return;
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}

		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T)*sz);
				delete[] _start;

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}


		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				int newcapacity = capacity() == 0 ?  2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void insert(iterator &pos, const T& x)
		{
			if (_finish == _end_of_storage)
			{
				int n = pos - _start;
				int newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}
			
			iterator end = _finish - 1;
			if (end > pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
		}

		void erase(iterator pos)
		{
			assert(pos > _start && pos < _finish);
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			--_finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}
	private:
		

		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}


void test_vector1()
{
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);


	for (int i  = 0; i < v.size();i++)
	{
		cout << v[i];
	}
	cout << endl;
}


