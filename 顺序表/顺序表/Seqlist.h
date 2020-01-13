#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define DataType int
#include<stdio.h>
#include<assert.h>

typedef struct Seqlist
{
	DataType* array; // 保存顺序表中有效元素个数 
	int capacity;// 空间总大小 
	int size; // 有效元素个数 
}Seqlist, *PSeqlist;

void SeqListInit(PSeqlist pc);//初始化
void SeqListDestroy(PSeqlist pc);//释放空间
void SeqListPushBack(PSeqlist pc, DataType data);// 尾插 
void SeqListPopBack(PSeqlist pc);// 尾删 
void SeqListPushFront(PSeqlist pc, DataType data);// 头插 
void SeqListPopFront(PSeqlist pc);// 头删 
void SeqListInsert(PSeqlist pc, int pos, DataType datda);// 任意位置插入 
void SeqListErase(PSeqlist pc, int pos);// 任意位置删除 
int SeqListFind(PSeqlist pc, DataType data);// 检测data是否在顺序表中 
void SeqListRemove(PSeqlist pc, DataType data);// 移除顺序表中第一个值为data的元素 
void SeqListRemoveAll(PSeqlist pc, DataType data);// 移除顺序表中所有值为data的元素
int SeqListSize(PSeqlist pc);// 获取顺序表有效元素个数
int SeqListCapacity(PSeqlist pc);// 获取顺序表的容量
int SeqListEmpty(PSeqlist pc);// 检测顺序表是否为空
DataType SeqListFront(PSeqlist pc);// 获取顺序表中第一个元素 
DataType SeqListBack(PSeqlist pc);// 获取顺序表中最后一个元素 
void PrintSeqList(PSeqlist pc);//打印