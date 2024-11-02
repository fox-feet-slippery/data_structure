#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//初始化和销毁
void SLInit(SL* ps)
{
	ps->_arr = NULL;
	ps->_capacity = ps->_size = 0;
}
void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->_arr)
	{
		free(ps->_arr);
	}
	ps->_arr = NULL;
	ps->_capacity = ps->_size = 0;
}
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_arr[i]);
	}
	return 0;
}
//扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	int capacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;

	SLDataType* oldArr = ps->_arr;
	ps->_arr = (SLDataType*)realloc(ps->_arr, sizeof(SLDataType) * capacity);
	if (ps->_arr == NULL)
	{
		ps->_arr = oldArr;
		perror("realloc fail!");
		return;
	}
	ps->_capacity = capacity;
}
//尾部插⼊删除 
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		SLCheckCapacity(ps);
	}
	ps->_arr[ps->_size++] = x;
}
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->_size);
	ps->_size--;
}
// 头部插⼊删除
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		SLCheckCapacity(ps);
	}
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_arr[i + 1] = ps->_arr[i];
	}
	ps->_arr[0] = x;
	ps->_size++;
}
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->_size);

	for (size_t i = 0; i < ps->_size; ++i)
	{
		ps->_arr[i] = ps->_arr[i + 1];
	}
	ps->_size--;
}
//指定位置之前插⼊/删除数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->_size);
	/*if (pos == 0)
	{
		SLPushFront(ps, x);
		return;
	}
	if (pos == ps->_size)
	{
		SLPushBack(ps, x);
		return;
	}*/

	if (ps->_capacity == ps->_size)
	{
		SLCheckCapacity(ps);
	}
	for (size_t i = ps->_size; i > pos; --i)
	{
		ps->_arr[i] = ps->_arr[i - 1];
	}
	ps->_arr[pos] = x;
	ps->_size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->_size >= 0 && pos < ps->_size);

	for (size_t i = pos; i < ps->_size - 1; i++)
	{
		ps->_arr[i] = ps->_arr[i + 1]; 
	}
	ps->_size--;
	
}
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		if (ps->_arr[i] == x) {
			return i;
		}
	}
	return -1;
}