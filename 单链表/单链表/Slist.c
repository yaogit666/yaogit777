#include"Slist.h"


void SListInit(SList* p)// 链表的初始化 
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


//创造一个新结点
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

// 在链表中尾插值为data的节点 
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

// 删除链表最后一个节点 
void SListPopBack(SList* p)
{
	assert(p);
	if (NULL == p->pHead)
	{
		printf("没得删");
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

// 在链表第一个元素前插入值为d的节点 
void SListPushFront(SList* p, SData d)
{
	assert(p);
	Node* NewData = MakeNewNode(d);
	NewData->pNext = p->pHead;
	p->pHead = NewData;
}

// 删除链表中第一个节点 
void SListPopFront(SList* p)
{
	assert(p);
	Node* cur = NULL;
	cur = p->pHead;
	p->pHead = cur->pNext;
	free(cur);
	cur = NULL;
}

// 在链表pos位置后插入置为d的节点 
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

// 删除链表中值为data的节点 
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

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
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


// 销毁链表 
void SListDestroy(SList* p)
{
	assert(p);
	free(p->pHead);
	p->pHead = NULL;
}

// 获取链表中有效节点的个数 
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

// 检测链表是否为空 
int SListEmpty(SList* p)
{
	assert(p);
	if (p->pHead)
	{
		return 1;
	}
	return -1;
}

// 获取链表的第一个节点 
Node* SListFront(SList* p)
{
	assert(p);
	return p->pHead->data;
}

// 获取链表的第二个节点 
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
