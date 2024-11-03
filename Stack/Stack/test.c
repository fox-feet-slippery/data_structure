#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void CreateStack()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);

	while (!STEmpty(&st))
	{
		STDataType data = STTop(&st);
		printf("%d ", data);
		STPop(&st);
	}
	printf("\n ");


	STDestroy(&st);
}

int main()
{
	CreateStack();

	return 0;
}