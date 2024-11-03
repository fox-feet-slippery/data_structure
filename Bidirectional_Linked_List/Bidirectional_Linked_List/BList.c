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
	node->_data = -1;
	node->_next = node->_prev = node;
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
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}
void BLTDestroy(BLTNode* phead)
{
	assert(phead);
	if (phead->_next == phead)
	{
		free(phead);
		phead = NULL;
		return;
	}
	BLTNode* pcur = phead->_next;
	while (pcur != phead)
	{
		BLTNode* del = pcur;
		pcur = pcur->_next;
		free(del);
		del = NULL;
	}
	free(phead);
	phead = NULL;
}
void BLTPrint(BLTNode* phead)
{
	assert(phead);
	if (phead->_next == phead)
	{
		printf("NULL\n");
		return;
	}
	BLTNode* pcur = phead ->_next;
	while (pcur != phead)
	{
		printf("%d->",pcur->_data);
		pcur = pcur->_next;
	}
	printf("NULL\n");
}
bool BLTEmpty(BLTNode* phead)
{
	assert(phead);
	if (phead->_next == phead)
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
	BLTNode* prev = phead->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = phead;
	phead->_prev = newnode;
}
void BLTPopBack(BLTNode* phead)
{
	assert(phead);
	BLTNode* del = phead->_prev;
	phead->_prev = del->_prev;
	del->_prev->_next = phead;
	free(del);
	del = NULL;
}
void BLTPushFront(BLTNode* phead, BLTDataType x)
{
	assert(phead);
	BLTNode* newnode = BLTBuyNode(x);
	newnode->_next = phead->_next;
	phead->_next->_prev = newnode;
	phead->_next = newnode;
	phead->_prev = phead;
}
void BLTPopFront(BLTNode* phead)
{
	assert(phead);
	BLTNode* del = phead->_next;
	phead->_next = del->_next;
	del->_next->_prev = phead;
	free(del);
	del = NULL;
}

//在pos位置之后插⼊数据
void BLTInsert(BLTNode* pos, BLTDataType x)
{
	assert(pos);
	BLTNode* newnode = BLTBuyNode(x);
	newnode->_next = pos->_next;
	pos->_next->_prev = newnode;
	pos->_next = newnode;
	newnode->_prev = pos;
}
void BLTErase(BLTNode* pos)
{
	assert(pos);
	BLTNode* del = pos->_next;
	pos->_next = del->_next;
	del->_next->_prev = pos;
	free(del);
	del = NULL;
}
BLTNode* BLTFind(BLTNode* phead, BLTDataType x)
{
	assert(phead);
	
	BLTNode* pcur = phead->_next;
	while (pcur != phead)
	{
		if (pcur->_data == x)
		{
			return pcur;
		}
		pcur = pcur->_next;
	}
	return NULL;
}
