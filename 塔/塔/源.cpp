//С����һЩ�����壬ÿ��������ı߳�Ϊ1��������Щ���������һЩ����
//����С�׶��壺��Щ���Ĳ��ȶ�ֵΪ����֮����ߵ�������͵����ĸ߶Ȳ
//С��������Щ�������ȶ������������������²�����ÿ�δ�ĳ������ȡ��һ�������壬�������ŵ���һ�����ϡ�
//ע�⣬С�ײ����������ŵ���ԭ�����������ϣ���Ϊ����Ϊ�����������塣
//����С����Ҫ֪�����������˲�����k�β���֮�󣬲��ȶ�ֵ��С�Ƕ��١�
//��������:
//��һ��������n, k(1 <= n <= 100, 0 <= k <= 1000)��ʾ���������Լ��������Ĵ�����
//�ڶ���n������ai(1 <= ai <= 104)��ʾ��i�����ĳ�ʼ�߶ȡ�
//������� :
//��һ��������s, m����ʾ��С�Ĳ��ȶ�ֵ�Ͳ�������(m <= k)
//������m�У�ÿ��������x, y��ʾ�ӵ�x������ȡ��һ��������ŵ���y�����ϡ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const pair<int, int> p1, const pair<int, int> p2)
{
	return p1.second < p2.second;
}
int main()
{
	int a, b;
	cin >> a >> b;
	vector<pair<int, int>>v1, v2;
	for (int i = 0; i < a; i++)
	{
		int x;
		cin >> x;
		v1.push_back(make_pair(i, x));
	}
	sort(v1.begin(), v1.end(), cmp);
	while (b--)
	{
		if (v1[a - 1].second > v1[0].second)
		{
			v1[a - 1].second--;
			v1[0].second++;
			v2.push_back(make_pair(a - 1, 0));
			sort(v1.begin(), v1.end(), cmp);
		}
		else
			break;
	}
	cout << v1[a - 1].second - v1[0].second << ' ' << b << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i].first << ' ' << v2[i].second << endl;
	}
	return 0;
}