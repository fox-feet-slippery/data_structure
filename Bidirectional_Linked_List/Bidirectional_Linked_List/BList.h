#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int BLTDataType;
typedef struct BListNode
{
	struct BListNode* next; //指针保存下⼀个结点的地址
	struct BListNode* prev; //指针保存前⼀个结点的地址
	BLTDataType data;
}BLTNode;


// void LTInit(LTNode * *pphead);
BLTNode* BLTInit();
void BLTDestroy(BLTNode* phead);
void BLTPrint(BLTNode* phead);
bool BLTEmpty(BLTNode* phead);
void BLTPushBack(BLTNode* phead, BLTDataType x);
void BLTPopBack(BLTNode* phead);
void BLTPushFront(BLTNode* phead, BLTDataType x);
void BLTPopFront(BLTNode* phead);
//在pos位置之后插⼊数据
void BLTInsert(BLTNode* pos, BLTDataType x);
void BLTErase(BLTNode* pos);
BLTNode* BLTFind(BLTNode* phead, BLTDataType x);
