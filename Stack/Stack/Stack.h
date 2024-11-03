#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _arr;
	int _top;
	int _capacity;
}ST;

// 初始化栈
void STInit(ST* ps);
// 销毁栈
void STDestroy(ST* ps);
// ⼊栈
void STPush(ST* ps, STDataType x);
//出栈
void STPop(ST* ps);
//取栈顶元素
STDataType STTop(ST* ps);
//获取栈中有效元素个数
int STSize(ST* ps);
//栈是否为空
bool STEmpty(ST* ps);