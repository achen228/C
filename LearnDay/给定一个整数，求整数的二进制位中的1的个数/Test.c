// 给定一个整数，求整数的二进制位中的1的个数
#include <stdio.h>
#include <stdlib.h>

int CountBitOne1(int num) // 不能够处理负数
{
	int count = 0;
	while (num != 0)
	{
		if (num % 2 == 1)
		{
			++count;
		}
		num = num >> 1;
	}
	return count;
}

int CountBitOne2(int num) // 正数负数均可处理
{
	int count = 0;
	for (int i = 0; i < sizeof(int) * 8; ++i)
	{
		if ((num >> i) & 0x1)
		{
			++count;
		}
	}
	return count;
}

int main()
{
	printf("%d\n", CountBitOne2(-10));
	system("pause");
	return 0;
}
