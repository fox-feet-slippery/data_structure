#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void createSList()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	SLTPrint(node1);
	printf("\n");

	SLTPushBack(&node1, 5);
	SLTPrint(node1);
	printf("\n");

	SLTPushFront(&node1, 0);
	SLTPrint(node1);
	printf("\n");

	SLTPopBack(&node1);
	SLTPrint(node1);
	printf("\n");

	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");

	SLTInsert(&node1, node3, 9);
	SLTPrint(node1);
	printf("\n");

	SLTErase(&node1, node2->next);
	SLTPrint(node1);
	printf("\n");

	/*SLTInsertAfter(node3, 9);
	SLTPrint(node1);
	printf("\n");

	SLTInsertAfter(node4, 9);
	SLTPrint(node1);
	printf("\n");*/

	/*SLTInsert(&node1, node1, 9);
	SLTPrint(node1);
	printf("\n");*/

	SLTInsertAfter(node3, 9);
	SLTPrint(node1);
	printf("\n");

	SLTEraseAfter(node3);
	SLTPrint(node1);
	printf("\n");

	SListDestroy(&node1);
}

void test01()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	SLTPrint(node1);
	printf("\n");

	SLTPopBack(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopBack(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopBack(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopBack(&node1);
	SLTPrint(node1);
	printf("\n");
}

void test02()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	SLTPrint(node1);
	printf("\n");

	SLTPushFront(&node1, 0);
	SLTPrint(node1);
	printf("\n");

	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");
	SLTPopFront(&node1);
	SLTPrint(node1);
	printf("\n");
}

void test03()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	SLTPrint(node1);
	printf("\n");

	/*SLTNode* node = SLTFind(node1, 6);
	printf("node-> = %d\n", node->data);*/

	/*SLTErase(&node1, node1);
	SLTPrint(node1);
	printf("\n");
	SLTErase(&node1, node1);
	SLTPrint(node1);
	printf("\n");
	SLTErase(&node1, node1);
	SLTPrint(node1);
	printf("\n");
	SLTErase(&node1, node1);
	SLTPrint(node1);
	printf("\n");*/
	/*SLTErase(&node1, node4);
	SLTPrint(node1);
	printf("\n");*/
	/*SLTInsertAfter(node4, 5);
	SLTPrint(node1);
	printf("\n");
	SLTInsertAfter(node1, 0);
	SLTPrint(node1);
	printf("\n");*/

	/*SLTEraseAfter(node4);
	SLTPrint(node1);
	printf("\n");*/

	SListDestroy(&node1);

}

int main()
{
	//createSList();

	//test01();
	//test02();

	test03();



	return 0;
}