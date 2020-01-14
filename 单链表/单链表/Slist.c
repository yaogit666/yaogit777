#include"Slist.h"


void SListInit(SList* p)// ����ĳ�ʼ�� 
{
	assert(p);
	p->pHead = NULL;
}

void printSList(SList* p)
{
	Node* cur = NULL;
	assert(p);
	cur = p->pHead;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->pNext;
	}
	printf("\n");
}


//����һ���½��
SData* MakeNewNode(SData d)
{
	Node* NewData = (Node*)malloc(sizeof(Node) * 10);
	if (NULL == NewData)
	{
		perror("NewDaTa::malloc");
		return;
	}
	NewData->data = d;
	NewData->pNext = NULL;
	return NewData;
}

// ��������β��ֵΪdata�Ľڵ� 
void SListPushBack(SList* p, SData d)
{
	assert(p);
	Node* cur = NULL;
	cur = p->pHead;
	Node* NewData = MakeNewNode(d);
	if (NULL == cur)
	{
		p->pHead = NewData;
		NewData->pNext = NULL;
		return;
	}
	while (cur->pNext)
	{
		cur = cur->pNext;
	}
	cur->pNext = NewData;
	NewData->data = d;
	NewData->pNext = NULL;
}

// ɾ���������һ���ڵ� 
void SListPopBack(SList* p)
{
	assert(p);
	if (NULL == p->pHead)
	{
		printf("û��ɾ");
		return;
	}
	else
	{
		Node* cur = NULL;
		cur = p->pHead;
		while (cur->pNext->pNext)
		{
			cur = cur->pNext;
		}
		free(cur->pNext);
		cur->pNext = NULL;
	}
}

// �������һ��Ԫ��ǰ����ֵΪd�Ľڵ� 
void SListPushFront(SList* p, SData d)
{
	assert(p);
	Node* NewData = MakeNewNode(d);
	NewData->pNext = p->pHead;
	p->pHead = NewData;
}

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* p)
{
	assert(p);
	Node* cur = NULL;
	cur = p->pHead;
	p->pHead = cur->pNext;
	free(cur);
	cur = NULL;
}

// ������posλ�ú������Ϊd�Ľڵ� 
void SListInsertAfter(SList* p, SData pos, SData d)
{
	assert(p);
	Node* cur = NULL;
	cur = p->pHead;
	Node* NewData = MakeNewNode(d);
	int count = 1;
	while (count != pos)
	{
		cur = cur->pNext;
		count++;
	}
		NewData->pNext = cur->pNext;
		cur->pNext = NewData;
}

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* p, SData d)
{
	assert(p);
	Node* ret = SListFind(p, d);
	Node* p1 = NULL;
	p1 = p->pHead;
	if (p1->pNext == ret)
	{
		p1->pNext = p1->pNext->pNext;
	}
}

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* p, SData d)
{
	assert(p);
	Node* cur = NULL;
	cur = p->pHead;
	while (cur->data != d)
	{
		cur = cur->pNext;
		if (cur->pNext == NULL)
		{
			return NULL;
		}
	}
	return cur;
}


// �������� 
void SListDestroy(SList* p)
{
	assert(p);
	free(p->pHead);
	p->pHead = NULL;
}

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* p)
{
	assert(p);
	int count = 0;
	while (p->pHead)
	{
		p->pHead = p->pHead->pNext;
		count++;
	}
	return count;
}

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* p)
{
	assert(p);
	if (p->pHead)
	{
		return 1;
	}
	return -1;
}

// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* p)
{
	assert(p);
	return p->pHead->data;
}

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* p)
{
	assert(p);
	return p->pHead->pNext->data;
}


void SListRemoveAll(SList* p, SData d)
{
	assert(p);
	Node* pCur = p->pHead;
	Node* pPre = NULL;
	while (pCur->pNext)
	{
		if (pCur->pNext->data == d)
		{
			pPre = pCur->pNext;
			pCur->pNext = pPre->pNext;
			free(pPre);
		}
		else
		{
			pCur = pCur->pNext;
		}
	}
	if (p->pHead->data = d)
	{
		pPre = p->pHead->pNext;
		free(p->pHead);
		p->pHead = pPre;
	}
}
