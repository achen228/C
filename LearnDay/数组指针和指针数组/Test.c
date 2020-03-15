// 数组指针和指针数组
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10] = { 0 };
	// arr 指向数组首元素的指针 (int*)
	printf("%p\n", arr);
	printf("%p\n", arr + 1);
	// 数组指针
	// arr 指向整个数组的指针 (int (*)[10])
	int arr[10];
	printf("%p\n", &arr);
	printf("%p\n", &arr + 1);

	// 指针数组
	// 数组中的每一个元素是一个指针类型的变量
	int* arr2[10];

	system("pause");
	return 0;
}
