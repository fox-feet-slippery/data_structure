#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>

void Func1(int N)
{
	int count = 0;

	// N^2
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}

	// 2 * N
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}

	int M = 10;

	// M
	while (M--)
	{
		++count;
	}

	//T(N) = N ^ 2 + 2 * N + M --> 大O的渐进表示法：O(N^2)
}

// 计算Func2的时间复杂度？
void Func2(int N)
{
	int count = 0;
	// 2*N
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}

	int M = 10;
	//M
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
	//T(N) = 2*N + M --> O(N)
}

void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++
		k)
	{
		++count;
	}
	printf("%d\n", count);
	//T(N) = M + N --> O(M+N)
}

// 计算Func4的时间复杂度？
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
	//T(N) = 100 --> O(1)  1代表常数
}

// 计算strchr的时间复杂度？
const char* strchr(const char* str, char character)
{
	const char* p_begin = str;
	while (*p_begin != character)
	{
		if (*p_begin == '\0')
			return NULL;
		p_begin++;
	}
	return p_begin;
	//T(N) 取决于查找位置
	//最好情况 O(1)
	//最坏情况 O(N)
	//评价情况 O(N)
	//大O通常关注坏运⾏情况
}

// 计算BubbleSort的时间复杂度？
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void BubbleSort(int* a, int n)
{
	//assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
	//T(N) = 1 + 2 + ... + N = N*(1+N)/2
	//O(N^2) 
}

void func5(int n)
{
	int cnt = 1;
	while (cnt < n)
	{
		cnt *= 2;
	}

	//假设执行次数X
	//2^x < n
	//x =  log n;
	//O(log n) 不管底数多少可以不写
}

// 计算阶乘递归Fac的时间复杂度？
long long Fac(size_t N)
{
	if (0 == N)
		return 1;
	return Fac(N - 1) * N;
	//单词递归时间复杂度 * 递归次数
	//O(N)
}

int main()
{
	//时间复杂度函数式T(N)
	//程序时间效率：运行时间(不确定) * 运行次数(确定的)

	//计算运行时间
	int begin = clock();
	//////////////////////////////////////////
	int cout = 0;
	for (int i = 0; i < 100000000; ++i)
	{
		cout++;
	}

	int end = clock();
	//////////////////////////////////////////
	printf("time:%dms\n", end - begin);

	return 0;
}