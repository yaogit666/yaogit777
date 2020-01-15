#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dst,const void* src, size_t count)
{
	void* d = dst;
	assert(dst != NULL);
	assert(src != NULL);
	while (count)
	{
		*(char*)dst = *(char*)src;
		count--;
		((char*)dst)++;
		((char*)src)++;
	}
	return d;
}
int main()
{
	int src[10] = {1,2,3,4,5,6,7,8,9};
	int dst[10] = {0};
	my_memcpy(dst, src, 16);
	int i = 0;
	int sz = sizeof(dst) / sizeof(dst[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d", dst[i]);
	}
	system("pause");
	return 0;
}