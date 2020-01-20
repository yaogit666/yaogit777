#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		vector<int> v1;
		vector<int> v2;
		stack<int> s;
		int k;
		cin >> k;
		v1.resize(k);
		for (int i = 0; i < k; i++)
		{
			cin >> v1[i];
		}
		for (int i = 0; i < k-1; i++)
		{
			for (int j = i; j < k-1; j++)
			{
				if (v1[i] == v1[j + 1])
				{
					v1[i] = -1;
				}
			} 
		}
		for (int i = 0; i < k; i++)
		{
			s.push(v1[i]);
		}
		for (int i = 0; i < k; i++)
		{
			int data = s.top();
			s.pop();
			if(data != -1)
				v2.push_back(data);
		}
		for (int i = 0; i < v2.size(); i++)
		{
			cout << v2[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}