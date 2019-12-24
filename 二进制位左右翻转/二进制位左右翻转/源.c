#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	int n = 0;
	int sum = 0;
	for (i = 0; i < 32; i++)
	{
	    
		n = ((value >> i ) & 1) * pow(2, 31 - i);
		sum += n;
	}
	return sum;
}
int main()
{
	int value = 25;
	int ret = reverse_bit(value);
	printf("%u", ret);
	system("pause");
	return 0;
}