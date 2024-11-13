#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_phead = pq->_ptail = NULL;
	pq->_size = 0;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* pcur = pq->_phead;
	while (pcur != NULL)
	{
		QNode* del = pcur;
		pcur = pcur->_next;
		free(del);
		del = NULL;
	}
	pcur = NULL;
	pq->_phead = pq->_ptail = NULL;
	pq->_size = 0;
}
// ⼊队列，队尾
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (node == NULL)
	{
		perror("Memory allocation failed!");
		exit(EXIT_FAILURE);
	}

	node->_val = x;
	node->_next = NULL;
	if (pq->_phead == NULL)
	{
		pq->_phead = pq->_ptail = node;
		pq->_size++;
		return;
	}
	
	pq->_ptail->_next = node;
	pq->_ptail = node;
	pq->_size++;
}
// 出队列，队头
void QueuePop(Queue* pq)
{
	assert(pq);
	QNode* del = pq->_phead;

	if (pq->_phead == pq->_ptail)
	{
		free(del);
		pq->_phead = pq->_ptail = NULL;
		pq->_size--;
		return;
	}

	pq->_phead = pq->_phead->_next;
	free(del);
	del = NULL;

	pq->_size--;
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->_phead->_val;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->_ptail->_val;
}
//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_size == 0;
}
//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->_size;
}