#include"stack.h";

//ջ�ĳ�ʼ��
void StackInit(stack* p)
{
	assert(p);
	p->capacity = 4;
	p->size = 0;
	p->array = (int*)malloc(4 * sizeof(int));
	if (NULL == p->array)
	{
		perror("StackInit::macoll");
		return;
	}
}

//��ջ
void Stackadd(stack* p, int d)
{
	assert(p);
	p->array[p->size] = d;
	p->size++;
	Addcapacity(p);
}

//����
void Addcapacity(stack* p)
{
	assert(p);
	if (p->size == p->capacity)
	{
		int* Newarray = (int*)malloc(sizeof(p->array)*2);
		memcpy(Newarray, p->array, sizeof(p->size)*4);
		free(p->array);
		p->array = Newarray;
		printf("���ݳɹ�\n");
	}
}

//��ջ

void Stackback(stack* p)
{
	assert(p);
	p->size--;
}

int Stackhead(stack* p)
{
	assert(p);
	return p->array[p->size - 1];
}

void Printf(stack* p)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		printf("%d ", p->array[i]);
	}
	printf("\n");
}