#include"Seqlist.h"



void SeqListInit(PSeqlist pc)//��ʼ��
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

void SeqListDestroy(PSeqlist pc)//�ͷſռ�
{
	assert(pc);
	free(pc->array);
	pc->array = NULL;
	pc->size = 0;	
	pc->capacity = 0;
}

void SeqListPushBack(PSeqlist pc, DataType data)// β�� ;
{
	assert(pc);
	pc->array[pc->size] = data;
	pc->size++;
}

void SeqListPopBack(PSeqlist pc)// βɾ 
{
	assert(pc);
	pc->size--;
}

void SeqListPushFront(PSeqlist pc, DataType data)// ͷ�� 
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
void SeqListPopFront(PSeqlist pc)// ͷɾ 
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size ; i++)
	{
		pc->array[i - 1] = pc->array[i];
	}
	pc->size--;
}

void SeqListInsert(PSeqlist pc, int pos, DataType datda)// ����λ�ò��� 
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

void SeqListErase(PSeqlist pc, int pos)// ����λ��ɾ�� 
{
	assert(pc);
	int  i = 0;
	for (i = pos; i < pc->size; i++)
	{
		pc->array[i] = pc->array[i + 1];
	}
	pc->size--;
}

int SeqListFind(PSeqlist pc, DataType data)// ���data�Ƿ���˳����� 
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

void SeqListRemove(PSeqlist pc, DataType data)// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
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
void SeqListRemoveAll(PSeqlist pc, DataType data)// �Ƴ�˳���������ֵΪdata��Ԫ��
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
int SeqListSize(PSeqlist pc)// ��ȡ˳�����ЧԪ�ظ��� 
{
	return pc->size;
}
int SeqListCapacity(PSeqlist pc)// ��ȡ˳��������
{
	return (pc->capacity) - (pc->size);
}

int SeqListEmpty(PSeqlist pc)// ���˳����Ƿ�Ϊ��
{
	assert(pc);
	if (pc->size == 0)
	{
		return -1;
	}

}
DataType SeqListFront(PSeqlist pc)// ��ȡ˳����е�һ��Ԫ�� 
{
	assert(pc);
	int i = 0;
	i = pc->array[0];
	return i;
}

DataType SeqListBack(PSeqlist pc)// ��ȡ˳��������һ��Ԫ�� 
{
	assert(pc);
	int i = 0;
	i = pc->array[pc->size];
	return i;
}
void PrintSeqList(PSeqlist pc)//��ӡ
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		printf("%d ", pc->array[i]);
	}
	printf("\n");
}