//СQ�õ�һ�����������: 1, 12, 123, ...12345678910, 1234567891011...��
//	����СQ�����ܷ�3����������ʺܸ���Ȥ��
//	СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3����
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