#pragma once
#include<stdio.h>
#include<assert.h>

typedef int SData;

// 节点结构 
typedef struct SListNode
{
	SData data;
	struct SListNode* pNext;
}Node;


// 给一个链表结构 
typedef struct SList
{
	Node* pHead;
}SList;




// 链表的初始化 
void SListInit(SList* p);
//创造一个新结点
SData* MakeNewNode(SData d);

// 在链表中尾插值为d的节点 
void SListPushBack(SList* p, SData d);

// 删除链表最后一个节点 
void SListPopBack(SList* p);

// 在链表第一个元素前插入值为d的节点 
void SListPushFront(SList* p, SData d);

// 删除链表中第一个节点 
void SListPopFront(SList* p);

// 在链表pos位置后插入置为d的节点 
void SListInsertAfter(SList* p, SData pos, SData d);

// 删除链表中值为data的节点 
void SListErase(SList* p, SData d);

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* p, SData d);

// 销毁链表 
void SListDestroy(SList* p);

// 获取链表中有效节点的个数 
int SListSize(SList* p);

// 检测链表是否为空 
int SListEmpty(SList* p);
// 获取链表的第一个节点 
Node* SListFront(SList* p);

// 获取链表的第二个节点 
Node* SListBack(SList* p);


void SListRemoveAll(SList* p, SData d);

void printSList(SList* p);