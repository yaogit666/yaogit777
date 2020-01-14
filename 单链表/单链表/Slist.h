#pragma once
#include<stdio.h>
#include<assert.h>

typedef int SData;

// �ڵ�ṹ 
typedef struct SListNode
{
	SData data;
	struct SListNode* pNext;
}Node;


// ��һ������ṹ 
typedef struct SList
{
	Node* pHead;
}SList;




// ����ĳ�ʼ�� 
void SListInit(SList* p);
//����һ���½��
SData* MakeNewNode(SData d);

// ��������β��ֵΪd�Ľڵ� 
void SListPushBack(SList* p, SData d);

// ɾ���������һ���ڵ� 
void SListPopBack(SList* p);

// �������һ��Ԫ��ǰ����ֵΪd�Ľڵ� 
void SListPushFront(SList* p, SData d);

// ɾ�������е�һ���ڵ� 
void SListPopFront(SList* p);

// ������posλ�ú������Ϊd�Ľڵ� 
void SListInsertAfter(SList* p, SData pos, SData d);

// ɾ��������ֵΪdata�Ľڵ� 
void SListErase(SList* p, SData d);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
Node* SListFind(SList* p, SData d);

// �������� 
void SListDestroy(SList* p);

// ��ȡ��������Ч�ڵ�ĸ��� 
int SListSize(SList* p);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* p);
// ��ȡ����ĵ�һ���ڵ� 
Node* SListFront(SList* p);

// ��ȡ����ĵڶ����ڵ� 
Node* SListBack(SList* p);


void SListRemoveAll(SList* p, SData d);

void printSList(SList* p);