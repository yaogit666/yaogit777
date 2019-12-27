//小Q得到一个神奇的数列: 1, 12, 123, ...12345678910, 1234567891011...。
//	并且小Q对于能否被3整除这个性质很感兴趣。
//	小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除
#include<iostream>
using namespace std;
int main()
{
	int l, r;
	while (cin >> l >> r)
	{
		int count = 0;
		for (int i = l; i <= r; i++)
		{
			if (i % 3 != 1)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}