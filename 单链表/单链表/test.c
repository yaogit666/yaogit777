#include"Slist.h"

int main()
{
	SList S;
	SListInit(&S);
	SListPushBack(&S, 1);
	SListPushBack(&S, 2);
	SListPushBack(&S, 1);
	SListPushBack(&S, 1);
	SListPushBack(&S, 3);
	printSList(&S);
	//SListPopBack(&S);
	//printSList(&S);
	//SListPushFront(&S, 1);
	//SListPushFront(&S, 2);
	//SListPushFront(&S, 3);
	//printSList(&S);
	//SListPopFront(&S);
	//SListInsertAfter(&S, 2, 4);
	//SData ret = SListFind(&S, 2);
	//
	//printf("%p", ret);
	//SListErase(&S, 2);
	//printSList(&S);
	//int ret = SListSize(&S);
	//printf("%d", ret);
	//int ret1 = SListFront(&S);
	//int ret2 = SListBack(&S);
	//printf("%d %d", ret1, ret2);
	SListRemoveAll(&S, 1);
	printSList(&S);
	system("pause");
	return 0;
}