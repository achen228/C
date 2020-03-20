#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int(*pFunc)(int, int);

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int Menu()
{
	printf("1.Add\n");
	printf("2.Sub\n");
	printf("3.Mul\n");
	printf("4.Div\n");
	printf("输入选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Run()
{
	pFunc arr[] = { Add, Sub, Mul, Div };
	int choice = Menu();
	pFunc func = arr[choice - 1];
	printf("%d\n", func(10, 20));
}

int main()
{
	Run();
	system("pause");
	return 0;
}
