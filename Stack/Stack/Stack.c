#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
// 初始化栈
void STInit(ST* ps)
{
	assert(ps);
	ps->_arr = NULL;
	ps->_capacity = ps->_top = 0;
}
// 销毁栈
void STDestroy(ST* ps)
{
	assert(ps);
	if (ps->_arr)
		free(ps->_arr);
	ps->_arr = NULL;
	ps->_capacity = ps->_top = 0;
}


// ⼊栈
void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_arr, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("Memory allocation failed!");
			exit(EXIT_FAILURE);
		}
		ps->_arr = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_arr[ps->_top++] = x;
}
//出栈
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->_top--;
}
//取栈顶元素
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));

	return ps->_arr[ps->_top - 1];
}
//获取栈中有效元素个数
int STSize(ST* ps)
{
	assert(ps);
	return ps->_top;
}
//栈是否为空
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->_top == 0;
}