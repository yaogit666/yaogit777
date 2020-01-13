#include"Seqlist.h"

void test()
{
	int input = 0;
	Seqlist S;
	SeqListInit(&S);
	/*SeqListPushBack(&S, 1);
	SeqListPopBack(&S);
	PrintSeqList(&S);*/
	SeqListPushFront(&S, 1);
	SeqListPushFront(&S, 2);
	SeqListPushFront(&S, 2);
	SeqListPushFront(&S, 3);
	SeqListPushFront(&S, 2);
	PrintSeqList(&S);
	/*SeqListPopFront(&S);*/

	//SeqListInsert(&S, 2, 4);
	//PrintSeqList(&S);
	//SeqListErase(&S, 2);
	//PrintSeqList(&S);
	/*SeqListFind(&S,1);*/
	/*
	SeqListRemove(&S, 2);*/
	
	//SeqListSize(&S);
	//SeqListCapacity(&S);
	//SeqListEmpty(&S);
	//SeqListFront(&S);
	//SeqListBack(&S);
	//PrintSeqList(&S);
	//SeqListDestroy(&S);
	/*SeqListRemove(&S, 2);
	PrintSeqList(&S);*/
	SeqListRemoveAll(&S, 2);
	PrintSeqList(&S);
}

int main()
{
	test();
	system("pause");
	return 0;
}