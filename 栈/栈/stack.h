#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct stack
{
	int* array;
	int capacity;
	int size;
}stack;

void StackInit(stack* P);//ջ�ĳ�ʼ��
void Stackadd(stack* p, int d);//��ջ
void Addcapacity(stack* p);//����
void Printf(stack* p);
void Stackback(stack* p);//��ջ
int Stackhead(stack* p);//ջ��