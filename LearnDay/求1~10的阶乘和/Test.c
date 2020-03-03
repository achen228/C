#include <stdio.h>
#include <stdlib.h>

int Factor(int i) // 非递归写法
{
	int ret = 1;
	for (int j = 1; j <= i; j++)
	{
		ret = ret * j;
	}
	return ret;
}

int FactorRecur(int i) // 递归写法，不创建临时变量
{
	if (i == 1)
	{
		return 1;
	}
	return i * FactorRecur(i - 1);
}

int main()
{
	int sum = 0;
	for (int i = 1; i <= 10; ++i)
	{
		sum = sum + FactorRecur(i);
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
