#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//大堆：父节点>=子节点，堆顶是最大值
//小堆：父节点<=子节点，堆顶是最小值

//⼆叉树性质
//对于具有 _size 个结点的完全⼆叉树，如果按照从上⾄下从左⾄右的数组顺序对所有结点从0 开始编号，
//则对于序号为 i 的结点有：
//1. 若 i > 0 ， i 位置结点的双亲序号：(i - 1) / 2 ； i = 0 ， i 为根结点编号，⽆双亲结点
//2. 若 2i + 1 < _size ，左孩⼦序号： 2i + 1 ， 2i + 1 >= _size 否则⽆左孩⼦
//3. 若 2i + 2 < _size ，右孩⼦序号： 2i + 2 ， 2i + 2 >= _size 否则⽆右孩⼦

typedef int HPDataType;

//定义堆的结构---数组
typedef struct Heap
{
	HPDataType* _arr;
	int _size;
	int _capacity;
}HP;

void HPInit(HP* php);

//利⽤给定数组初始化堆
void HPInitArray(HP* php, HPDataType* arr, int size);

//堆的销毁
void HPDestroy(HP* php);

//堆的插⼊
void MakeMinHPPush(HP* php, HPDataType x);
void MakeMaxHPPush(HP* php, HPDataType x);

HPDataType HPTop(HP * php);

// 删除堆顶的数据
void MinHPPop(HP* php);
void MaxHPPop(HP* php);

// 判空
bool HPEmpty(HP* php);

//求size
int HPSize(HP* php);

//向上调整算法
void MakeMinAdjustUp(HPDataType* arr, int child);
void MakeMaxAdjustUp(HPDataType* arr, int child);

//向下调整算法
void MakeMinAdjustDown(HPDataType* arr, int n, int parent);
void MakeMaxAdjustDown(HPDataType* arr, int size, int parent);

// 交换两个整数
void Swap(HPDataType* a, HPDataType* b);
