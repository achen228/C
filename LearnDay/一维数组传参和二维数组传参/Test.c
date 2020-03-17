// 一维数组传参和二维数组传参
#include <stdio.h>
#include <stdlib.h>

void Func(int arr[]);
void Func(int arr[10]);
void Func(int* arr);

void Func2(int arr[][20]);
void Func2(int arr[10][20]);
void Func2(int (*arr)[20]);

int main()
{
	// 一维数组传参
	int arr[10];
	Func(arr);
	// 二维数组传参
	int arr[10][20];
	Func2(arr);
	system("pause");
	return 0;
}
