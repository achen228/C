// 斐波那契数列
// 1 1 2 3 5 8 13
#include <stdio.h>
#include <stdlib.h>

int Fib(int n) // 非递归写法
{
	int fib1 = 1;
	int fib2 = 1;
	int ret = 0;
	for (int i = 3; i <= n; ++i)
	{
		ret = fib1 + fib2;
		fib1 = fib2;
		fib2 = ret;
	}
	return ret;
}

int FibRecur(int n) // 递归写法，不创建临时变量
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FibRecur(n - 1) + FibRecur(n - 2);
}

int main()
{
	printf("%d\n", FibRecur(7));
	system("pause");
	return 0;
}
