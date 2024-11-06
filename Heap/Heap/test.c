#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void CreateHeap()
{
	HP hp;
	HPInit(&hp);

	int arr[] = { 23,7,12,16,10,20 };

	for (size_t i = 0; i < 6; i++)
	{
		MakeMaxHPPush(&hp, arr[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		arr[i++] = HPTop(&hp);
		MaxHPPop(&hp);
	}

	for (size_t i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	HPDestroy(&hp);
}

void HeapSort1(int* arr, int  size)//降序
{
	//向下调整算法建堆 -- 小堆
	for (int i = (size - 1 -1) / 2; i >=0; --i)
	{
		MakeMinAdjustDown(arr, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		MakeMinAdjustDown(arr, end, 0);
		end--;
	}
	for (size_t i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void HeapSort2(int* arr, int  size)//升序
{
	//向下调整算法建堆 -- 小堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		MakeMaxAdjustDown(arr, size, i);
	}
	int end = size - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		MakeMaxAdjustDown(arr, end, 0);
		end--;
	}
	for (size_t i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test01()
{
	int arr[] = { 23,7,12,16,10,20 };
	HeapSort1(arr, 6);
	HeapSort2(arr, 6);
}
#include<time.h>
void CreateData()
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error\n");
		exit(1);
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + 1) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void topk()
{
	printf("请输入k：>");
	int k = 0;
	scanf("%d", &k);
	const char* file = "data.txt";
	//读文件
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		exit(1);
	}
	//int val = 0;
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc error");
		exit(2);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}

	//建小堆
	for (int i = (k - 1 -1) / 2; i >= 0; --i)
	{
		MakeMinAdjustDown(minheap, k, i);
	}


	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		//与堆顶比较大小，大的入堆
		if (minheap[0] < x)
		{
			minheap[0] = x;
			MakeMinAdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	} 
	fclose(fout);
}

int main()
{
	//CreateHeap();
	//test01();
	//CreateData();
	topk();

	return 0;
}