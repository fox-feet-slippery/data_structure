#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


void CreateQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType val = QueueFront(&q);
		QueuePop(&q);
		printf("%d->", val);
	}
	printf("NULL\n");

	QueueDestroy(&q);
	
}

int main()
{

	CreateQueue();

	return 0;
}