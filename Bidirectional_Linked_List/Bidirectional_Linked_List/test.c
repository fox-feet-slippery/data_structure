#define _CRT_SECURE_NO_WARNINGS 1
#include"BList.h"

void createBlist()
{
	BLTNode* node = BLTInit();
	BLTPrint(node);

	BLTPushBack(node, 1);
	BLTPushBack(node, 2);
	BLTPushBack(node, 3);
	BLTPushBack(node, 4);
	BLTPrint(node);

	BLTPopBack(node);
	BLTPrint(node);
	BLTPopBack(node);
	BLTPrint(node);
	BLTPopBack(node);
	BLTPrint(node);
	BLTPopBack(node);
	BLTPrint(node);

	BLTPushFront(node, 1);
	BLTPushFront(node, 2);
	BLTPushFront(node, 3);
	BLTPushFront(node, 4);
	BLTPrint(node);

	BLTPopFront(node);
	BLTPrint(node);
	BLTPopFront(node);
	BLTPrint(node);
	BLTPopFront(node);
	BLTPrint(node);
	BLTPopFront(node);
	BLTPrint(node);
	printf("------------------------------------------------------------------------------------\n");

	BLTPushBack(node, 1);
	BLTPushBack(node, 2);
	BLTPushBack(node, 3);
	BLTPushBack(node, 4);
	BLTPrint(node);

	
	BLTNode* pos1 = BLTFind(node, 1);
	/*if (pos == NULL)
	{
		printf("not find!\n");
	}
	else
	{
		printf("%d\n", pos->data);
	}*/
	BLTInsert(pos1, 9);
	BLTPrint(node);

	BLTNode* pos3 = BLTFind(node, 4);
	BLTInsert(pos3, 9);
	BLTPrint(node);

	BLTNode* pos2 = BLTFind(node, 1);
	BLTInsert(pos2, 9);
	BLTPrint(node);

	BLTErase(pos1);
	BLTPrint(node);

	BLTErase(pos1);
	BLTPrint(node);

	BLTErase(pos1);
	BLTPrint(node);
}

int main()
{
	createBlist();
	

	return 0;
}