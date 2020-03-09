// 将两个整数交换，且不能创建临时变量
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	system("pause");
	return 0;
}
