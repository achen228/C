// 结构体内存对齐
#include <stdio.h>
#include <stdlib.h>

struct A
{
	short a;
	short b;
	short c;
};

struct Test
{
	char a;
	int b;
	char c;
	struct A m;
};

int main()
{
	struct Test n;
	printf("%d\n", sizeof(struct Test));
	printf("%p\n", &n.a);
	printf("%p\n", &n.b);
	printf("%p\n", &n.c);
	printf("%p\n", &n.m);
	system("pause");
	return 0;
}
