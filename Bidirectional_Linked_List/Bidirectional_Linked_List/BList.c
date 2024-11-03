#define _CRT_SECURE_NO_WARNINGS 1
#include"BList.h"

// void LTInit(LTNode * *pphead);
BLTNode* BLTInit()
{
	BLTNode* node = (BLTNode*)malloc(sizeof(BLTNode));
	if (node == NULL)
	{
		perror("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}
	node->data = -1;
	node->next = node->prev = node;
	return node;
}

BLTNode* BLTBuyNode(BLTDataType x)
{
	BLTNode* newnode = (BLTNode*)malloc(sizeof(BLTNode));
	if (newnode == NULL)
	{
		perror("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void BLTDestroy(BLTNode* phead)
{

}
void BLTPrint(BLTNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		printf("NULL\n");
		return;
	}
	BLTNode* pcur = phead -> next;
	while (pcur != phead)
	{
		printf("%d->",pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
bool BLTEmpty(BLTNode* phead)
{
	assert(phead);
	if (phead->next == phead)
	{
		printf("NULL\n");
		return true;
	}
	else
		return false;
}
void BLTPushBack(BLTNode* phead, BLTDataType x)
{
	assert(phead);
	BLTNode* newnode = BLTBuyNode(x);
	BLTNode* prev = phead->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = phead;
	phead->prev = newnode;
}
void BLTPopBack(BLTNode* phead)
{
	assert(phead);
	BLTNode* del = phead->prev;
	phead->prev = del->prev;
	del->prev->next = phead;
	free(del);
	del = NULL;
}
void BLTPushFront(BLTNode* phead, BLTDataType x)
{
	assert(phead);
	BLTNode* newnode = BLTBuyNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	phead->prev = phead;
}
void BLTPopFront(BLTNode* phead)
{
	assert(phead);
	BLTNode* del = phead->next;
	phead->next = del->next;
	del->next->prev = phead;
	free(del);
	del = NULL;
}

//在pos位置之后插⼊数据
void BLTInsert(BLTNode* pos, BLTDataType x)
{
	assert(pos);
	BLTNode* newnode = BLTBuyNode(x);
	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}
void BLTErase(BLTNode* pos)
{
	assert(pos);
	BLTNode* del = pos->next;
	pos->next = del->next;
	del->next->prev = pos;
	free(del);
	del = NULL;
}
BLTNode* BLTFind(BLTNode* phead, BLTDataType x)
{
	assert(phead);
	
	BLTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}