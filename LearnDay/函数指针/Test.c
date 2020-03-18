// 函数指针
#include <stdio.h>
#include <stdlib.h>

void Func()
{
	printf("Hello\n");
}

void Func2()
{
	printf("nihao\n");
}

int main()
{
	// &Func 和 Func 两者是等价的
	printf("%p\n", &Func);
	printf("%p\n", Func);

	// P 的类型 void(*)()
	void(*p)() = Func;
	printf("%p\n", p);
	// 函数指针能够调用到指向的函数
	p(); // Hello

	p = Func2;
	p(); // nihao

	system("pause");
	return 0;
}
