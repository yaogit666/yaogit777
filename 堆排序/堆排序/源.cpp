#include<iostream>
#include<vector>
using namespace std;

void heapDown(vector<int> &v, int i, int s)
{
	int parent = i;
	int child = parent * 2 + 1;
	while (child < s)
	{
		if (child + 1 < s && v[child] < v[child + 1])
		{
			child += 1;
		}

		if (v[parent] < v[child])
		{
			swap(v[parent], v[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void heapSort(vector<int> &v, int s)
{
	for (; s > 0; --s)
	{
		int i = (s - 2) / 2;
		for (; i >= 0; --i)
		{
			heapDown(v, i, s);
		}
		swap(v[0], v[s-1]);
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	vector<int> v;
	int n;
	while (cin >>n)
	{
		v.push_back(n);
		if(cin.get() == '\n')
			break;
	}
	int s = v.size();
	heapSort(v, s);
	for (int i = 0; i < s; i++)
	{
		cout << v[i];
	}
	cout << endl;
	system("pause");
	return 0;
}