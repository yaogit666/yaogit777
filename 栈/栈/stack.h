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

void StackInit(stack* P);//栈的初始化
void Stackadd(stack* p, int d);//入栈
void Addcapacity(stack* p);//增容
void Printf(stack* p);
void Stackback(stack* p);//出栈
int Stackhead(stack* p);//栈顶