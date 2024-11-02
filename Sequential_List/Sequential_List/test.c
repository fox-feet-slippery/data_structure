#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

int main()
{
	SL sl;
	SLInit(&sl);
	/*SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	printf("\n");

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	printf("\n");*/

	/*SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPrint(&sl);
	printf("\n");

	SLPopFront(&sl);
	SLPrint(&sl);
	printf("\n");
	SLPopFront(&sl);
	SLPrint(&sl);
	printf("\n");
	SLPopFront(&sl);
	SLPrint(&sl);
	printf("\n");
	SLPopFront(&sl);
	SLPrint(&sl);
	printf("\n");*/

	/*SLPushBack(&sl, 1);
	SLPrint(&sl);
	printf("\n");
	SLPushBack(&sl, 2);
	SLPrint(&sl);
	printf("\n");
	SLPushBack(&sl, 3);
	SLPrint(&sl);
	printf("\n");
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	printf("\n");
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	printf("\n");

	SLInsert(&sl, 0, 9);
	SLPrint(&sl);
	printf("\n");
	SLInsert(&sl, 5, 9);
	SLPrint(&sl);
	printf("\n");
	SLInsert(&sl, 2, 9);
	SLPrint(&sl);
	printf("\n");


	SLPrint(&sl);
	printf("\n");*/

	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 2);
	//SLPushFront(&sl, 3);
	//SLPushFront(&sl, 4);
	//SLPrint(&sl);
	//printf("\n");

	//SLPopFront(&sl);
	//SLPrint(&sl);
	//printf("\n");
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//printf("\n");
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//printf("\n");
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//printf("\n");
	//SLPrint(&sl);

	//SLPushFront(&sl, 1);
	//SLPushFront(&sl, 2);
	//SLPushFront(&sl, 3);
	//SLPushFront(&sl, 4);
	//printf("\n");
	//SLPrint(&sl);

	//SLInsert(&sl, 3, 9);
	//printf("\n");
	//SLPrint(&sl);

	//SLInsert(&sl, 4, 9);
	//printf("\n");
	//SLPrint(&sl);

	//SLInsert(&sl, 0, 9);
	//printf("\n");
	//SLPrint(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	printf("\n");

	SLErase(&sl, 0);
	SLPrint(&sl);
	printf("\n");

	SLErase(&sl, sl._size - 1);
	SLPrint(&sl);
	printf("\n");

	SLDestroy(&sl);


	return 0;
}




















