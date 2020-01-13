#include"stack.h"

int main()
{
	stack S;
	StackInit(&S);
	Stackadd(&S, 1);
	Stackadd(&S, 2);
	Stackadd(&S, 3);
	Printf(&S);
	Stackback(&S);
	Printf(&S);
	int ret = Stackhead(&S);
	printf("%d ", ret);
	system("pause");
	return 0;
}
