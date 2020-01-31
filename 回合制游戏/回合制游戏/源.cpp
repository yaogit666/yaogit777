#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int HP, nA, bA;
	cin >> HP >> nA >> bA;
	int count1 = HP / nA;
	if (HP%nA != 0)
		count1 += 1;
	int count2 = (HP / bA) * 2;
	if (HP%bA != 0)
	{
		if (HP%bA <= nA)
			count2 += 1;
		else
			count2 += 2;
	}
	int count = min(count1, count2);
	cout << count << endl;
	return 0;
}