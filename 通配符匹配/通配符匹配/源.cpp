class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, iStar = -1, jStar = -1, m = s.size(), n = p.size();
		while (i < m) {
			if (j < n && (s[i] == p[j] || p[j] == '?')) {
				++i, ++j;//i��j���˲��
			}
			else if (j < n && p[j] == '*') {//��¼���֮������ƥ�䲻�ɹ�ʱ�� i��j��Ҫ���ݵ���λ��
				iStar = i;//��¼�Ǻ�
				jStar = j++;//��¼�Ǻ� ����j�Ƶ���һλ ׼���¸�ѭ��s[i]��p[j]��ƥ��
			}
			else if (iStar >= 0) {//�����ַ���ƥ����û���Ǻų��� ����istar>0 ˵��������*ƥ����ַ��������� ��ʱ����
				i = ++iStar;//i���ݵ�istar+1 ��Ϊ�ϴδ�s��istar��ʼ��*�ĳ���ƥ���Ѿ���֤���ǲ��ɹ��ģ���Ȼ��������˷�֧�� ������Ҫ��istar+1�ٿ�ʼ�� ͬʱinc istar ���»���λ��
				j = jStar + 1;//j���ݵ�jstar+1 ����ʹ��p��*��Ĳ��ֿ�ʼ��s��istar�����istar����һ���Ѿ�inc���ˣ�λ�ü�֮���ַ���ƥ�� 
			}
			else return false;
		}
		while (j < n && p[j] == '*') ++j;//ȥ�������Ǻ�
		return j == n;
	}
};