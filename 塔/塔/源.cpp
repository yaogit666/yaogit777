//小易有一些立方体，每个立方体的边长为1，他用这些立方体搭了一些塔。
//现在小易定义：这些塔的不稳定值为它们之中最高的塔与最低的塔的高度差。
//小易想让这些塔尽量稳定，所以他进行了如下操作：每次从某座塔上取下一块立方体，并把它放到另一座塔上。
//注意，小易不会把立方体放到它原本的那座塔上，因为他认为这样毫无意义。
//现在小易想要知道，他进行了不超过k次操作之后，不稳定值最小是多少。
//输入描述:
//第一行两个数n, k(1 <= n <= 100, 0 <= k <= 1000)表示塔的数量以及最多操作的次数。
//第二行n个数，ai(1 <= ai <= 104)表示第i座塔的初始高度。
//输出描述 :
//第一行两个数s, m，表示最小的不稳定值和操作次数(m <= k)
//接下来m行，每行两个数x, y表示从第x座塔上取下一块立方体放到第y座塔上。
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