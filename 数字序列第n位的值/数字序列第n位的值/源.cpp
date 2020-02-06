#include<iostream>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	int tem = n;
	for (int i = 1; i <= n; ++i) {
		if (tem <= i) {
			cout << i << endl;
			break;
		}
		tem -= i;
	}
	return 0;
}