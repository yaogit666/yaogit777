class Solution {
public:
	int father[210];
	//�������Ƚڵ㣬���ڵ��¼���������Լ������ʾ���ҵ�������
	int findFather(int x)
	{
		while (x != father[x])
		{
			x = father[x];
		}
		return x;
	}
	//�ϲ��ڵ㣺���ù�ͬ����
	void Union(int a, int b)
	{
		int fa = findFather(a);
		int fb = findFather(b);
		if (fa != fb)
		{
			father[fa] = fb;
		}
	}
	//�ʼ��ʱ��ÿ���ڵ�ʱ��ɢ�ģ������Լ�������
	void init()
	{
		for (int i = 0; i < 210; i++)
		{
			father[i] = i;
		}
	}
	//������
	int findCircleNum(vector<vector<int>>& M) {
		init();
		//��N��ѧ���������ж�
		for (int i = 0; i < M.size(); i++)
		{
			for (int j = i + 1; j < M.size(); j++)
			{
				if (M[i][j] == 1)
				{
					Union(i, j);
				}
			}
		}
		//һ�α����ҵ��������Ƚڵ㣬��Ϊ����Ȧ�ĸ���
		int res = 0;
		for (int i = 0; i < M.size(); i++)
		{
			if (i == father[i])
			{
				res++;
			}
		}
		return res;
	}
};
