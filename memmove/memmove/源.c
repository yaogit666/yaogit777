#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dst, const void* src, size_t count)
{
	void* d = dst;
	assert(dst != NULL);
	assert(src != NULL);
	if(dst <= src || (char*)dst >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			((char*)dst)++;
			((char*)src)++;
		}
	}
	else
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			((char*)dst)--;
			((char*)src)--;	
		}
	}
	return d;
}
int main()
{
	char arr[20] = { "123456789" };
	char* ret = my_memmove(arr , arr+2, 4);
	printf("%s", ret);
	system("pause");
	return 0;
}