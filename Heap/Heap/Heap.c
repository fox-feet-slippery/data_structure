#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->_arr = NULL;
	php->_size = php->_capacity = 0;
}

//利⽤给定数组初始化堆
void HPInitArray(HP* php, HPDataType* arr, int size)
{

}

//堆的销毁
void HPDestroy(HP* php)
{
	assert(php);
	free(php->_arr);
	php->_arr = NULL;
	php->_size = php->_capacity = 0;
}

//堆的插⼊
void MakeMinHPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		int newcapacity = php->_capacity == 0 ? 4 : 2 * php->_capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->_arr, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("Memory allocation failed!");
			exit(1);
		}
		php->_arr = tmp;
		php->_capacity = newcapacity;
	}
	php->_arr[php->_size] = x;
	MakeMinAdjustUp(php->_arr, php->_size);
	++php->_size;
}
void MakeMaxHPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		int newcapacity = php->_capacity == 0 ? 4 : 2 * php->_capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->_arr, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("Memory allocation failed!");
			exit(1);
		}
		php->_arr = tmp;
		php->_capacity = newcapacity;
	}
	php->_arr[php->_size] = x;
	MakeMaxAdjustUp(php->_arr, php->_size);
	++php->_size;
}

// 交换两个整数
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}


HPDataType HPTop(HP* php)
{
	assert(php && php->_size);
	return php->_arr[0];

}

// 删除堆顶的数据
void MinHPPop(HP* php)
{
	assert(php && php->_size);
	Swap(&php->_arr[0], &php->_arr[--php->_size]);
	MakeMinAdjustDown(php->_arr, php->_size, 0);
}
void MaxHPPop(HP* php)
{
	assert(php && php->_size);
	Swap(&php->_arr[0], &php->_arr[--php->_size]);
	MakeMaxAdjustDown(php->_arr, php->_size, 0);
}

// 判空
bool HPEmpty(HP* php)
{
	assert(&php);
	return php->_size == 0;
}

//求size
int HPSize(HP* php)
{
	assert(&php);
	return php->_size;
}

//向上调整算法
void MakeMinAdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] > arr[child])//父亲>孩子，进行交换，建小堆
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void MakeMaxAdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] < arr[child])//父亲<孩子，进行交换，建大堆
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整算法
void MakeMinAdjustDown(HPDataType* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//小堆：找左右孩子中找最小的
		if (child + 1 < size && arr[child] > arr[child + 1])
		{
			++child;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void MakeMaxAdjustDown(HPDataType* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//小堆：找左右孩子中找最小的
		//大堆：找左右孩子中找最大的
		if (child + 1 < size && arr[child] < arr[child + 1])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}