#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define DataType int
#include<stdio.h>
#include<assert.h>

typedef struct Seqlist
{
	DataType* array; // ����˳�������ЧԪ�ظ��� 
	int capacity;// �ռ��ܴ�С 
	int size; // ��ЧԪ�ظ��� 
}Seqlist, *PSeqlist;

void SeqListInit(PSeqlist pc);//��ʼ��
void SeqListDestroy(PSeqlist pc);//�ͷſռ�
void SeqListPushBack(PSeqlist pc, DataType data);// β�� 
void SeqListPopBack(PSeqlist pc);// βɾ 
void SeqListPushFront(PSeqlist pc, DataType data);// ͷ�� 
void SeqListPopFront(PSeqlist pc);// ͷɾ 
void SeqListInsert(PSeqlist pc, int pos, DataType datda);// ����λ�ò��� 
void SeqListErase(PSeqlist pc, int pos);// ����λ��ɾ�� 
int SeqListFind(PSeqlist pc, DataType data);// ���data�Ƿ���˳����� 
void SeqListRemove(PSeqlist pc, DataType data);// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqlist pc, DataType data);// �Ƴ�˳���������ֵΪdata��Ԫ��
int SeqListSize(PSeqlist pc);// ��ȡ˳�����ЧԪ�ظ���
int SeqListCapacity(PSeqlist pc);// ��ȡ˳��������
int SeqListEmpty(PSeqlist pc);// ���˳����Ƿ�Ϊ��
DataType SeqListFront(PSeqlist pc);// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListBack(PSeqlist pc);// ��ȡ˳��������һ��Ԫ�� 
void PrintSeqList(PSeqlist pc);//��ӡ