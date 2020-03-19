// 回调函数的应用:多规则冒泡排序
#include <stdio.h>
#include <stdlib.h>

typedef int(*Comp)(int, int);

// 升序
int Less(int x, int y)
{
	return x < y ? 1 : 0;
}

// 降序
int Greater(int x, int y)
{
	return x > y ? 1 : 0;
}

// 按照数字的绝对值大小升序排列
int Abs(int x, int y)
{
	return abs(x) < abs(y) ? 1 : 0;
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int* arr, int size, Comp comp)
{
	for (int bound = 0; bound < size; ++bound)
	{
		for (int cur = size - 1; cur > bound; --cur)
		{
			if (!comp(arr[cur - 1], arr[cur]))
			{
				Swap(&arr[cur - 1], &arr[cur]);
			}
		}
	}
}

void Print(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9, 5, 2, 7, -6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	// 升序排列
	BubbleSort(arr, size, Less);
	Print(arr, size);
	// 降序排列
	BubbleSort(arr, size, Greater);
	Print(arr, size);
	// 按照数字的绝对值大小升序排列
	BubbleSort(arr, size, Abs);
	Print(arr, size);

	system("pause");
	return 0;
}
