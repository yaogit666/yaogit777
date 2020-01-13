#include"Seqlist.h"



void SeqListInit(PSeqlist pc)//初始化
{
	assert(pc);
	pc->size = 0;
	pc->capacity = 10;
	pc->array = (DataType*)malloc(sizeof(DataType) * 10);
	if (pc->array == NULL)
	{
		perror("InitContact::malloc()");
		return;
	}
}

void SeqListDestroy(PSeqlist pc)//释放空间
{
	assert(pc);
	free(pc->array);
	pc->array = NULL;
	pc->size = 0;	
	pc->capacity = 0;
}

void SeqListPushBack(PSeqlist pc, DataType data)// 尾插 ;
{
	assert(pc);
	pc->array[pc->size] = data;
	pc->size++;
}

void SeqListPopBack(PSeqlist pc)// 尾删 
{
	assert(pc);
	pc->size--;
}

void SeqListPushFront(PSeqlist pc, DataType data)// 头插 
{
	assert(pc);
	int i = 0;
	for (i = pc->size ; i > 0; i--)
	{
		pc->array[i] = pc->array[i - 1];
	}
	pc->array[i] = data;
	pc->size++;
}
void SeqListPopFront(PSeqlist pc)// 头删 
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size ; i++)
	{
		pc->array[i - 1] = pc->array[i];
	}
	pc->size--;
}

void SeqListInsert(PSeqlist pc, int pos, DataType datda)// 任意位置插入 
{
	assert(pc);
	int  i = 0;
	for (i = pos; i < pc->size; i++)
	{
		pc->array[i + 1] = pc->array[i];
	}
	pc->array[pos] = datda;
	pc->size++;
}

void SeqListErase(PSeqlist pc, int pos)// 任意位置删除 
{
	assert(pc);
	int  i = 0;
	for (i = pos; i < pc->size; i++)
	{
		pc->array[i] = pc->array[i + 1];
	}
	pc->size--;
}

int SeqListFind(PSeqlist pc, DataType data)// 检测data是否在顺序表中 
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (pc->array[i] == data)
		{
			return 1;
		}
	}
	return -1;
}

void SeqListRemove(PSeqlist pc, DataType data)// 移除顺序表中第一个值为data的元素 
{
	assert(pc);
	int i = 0;
	int j = 0;
	while (i < pc->size && pc->array[i] != data)
	{
		i++;
	}
	for (j = i; j < pc->size; j++)
	{
		pc->array[j] = pc->array[j + 1];
	}
	pc->size--;
}
void SeqListRemoveAll(PSeqlist pc, DataType data)// 移除顺序表中所有值为data的元素
{
	assert(pc);
	int i = 0, j = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (pc->array[i] == data)
			j++;
		else
			pc->array[i - j] = pc->array[i];
		
	}
	pc->size -= j;
}
int SeqListSize(PSeqlist pc)// 获取顺序表有效元素个数 
{
	return pc->size;
}
int SeqListCapacity(PSeqlist pc)// 获取顺序表的容量
{
	return (pc->capacity) - (pc->size);
}

int SeqListEmpty(PSeqlist pc)// 检测顺序表是否为空
{
	assert(pc);
	if (pc->size == 0)
	{
		return -1;
	}

}
DataType SeqListFront(PSeqlist pc)// 获取顺序表中第一个元素 
{
	assert(pc);
	int i = 0;
	i = pc->array[0];
	return i;
}

DataType SeqListBack(PSeqlist pc)// 获取顺序表中最后一个元素 
{
	assert(pc);
	int i = 0;
	i = pc->array[pc->size];
	return i;
}
void PrintSeqList(PSeqlist pc)//打印
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->array[i]);
	}
	printf("\n");
}