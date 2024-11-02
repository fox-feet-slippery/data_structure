#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h";

void SLTPrint(SLTNode* phead)
{
	if (phead == NULL)
	{
		printf("NULL");
		return;
	}
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL");
}

//头部插⼊删除/尾部插⼊删除
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* pcur = *pphead;
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) 
	{
		perror("Memory allocation failed!");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	while (pcur->next)
	{
		pcur = pcur->next;
	}
	pcur->next = newnode;
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) 
	{
		perror("Memory allocation failed!");
		return;
	}
	newnode->data = x;
	newnode->next = *pphead;
	*pphead = newnode;
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	SLTNode* pcur = *pphead;
	while (pcur->next->next)
	{
		pcur = pcur->next;
	}

	free(pcur->next);
	pcur->next = NULL;
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* node = (*pphead)->next;
	free(*pphead);
	*pphead = node;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	assert(pphead);
	assert(*pphead);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
		return;
	}

	SLTNode* pcur = *pphead;
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("Memory allocation failed!");
		return;
	}
	newnode->data = x;
	while (pcur->next != pos)
	{
		pcur = pcur->next;
	}
	pcur->next = newnode;
	newnode->next = pos;
}

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);
	assert(pphead);
	assert(*pphead);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
		return;
	}
	SLTNode* pcur = *pphead;
	while (pcur->next != pos)
	{
		pcur = pcur->next;
	}
	pcur->next = pos->next;
	free(pos);
	pos = NULL;
}

//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("Memory allocation failed!");
		return;
	}
	newnode->data = x;
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos之后的结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* node = pos->next;
	pos->next = node->next;
	free(node);
	node = NULL;
}

//销毁链表
void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* node = pcur;
		pcur = pcur->next;
		free(node);
		node = NULL;
	}
}