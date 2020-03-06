#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int arr[], int size)
{
	// [0, bound) 已排序区间
	// [bound, size) 待排序区间
	for (int bound = 0; bound < size; ++bound)
	{
		// 从后向前找，找到最小的放到最前面，升序排列
		for (int cur = size - 1; cur > bound; --cur)
		{
			if (arr[cur] < arr[cur - 1])
			{
				swap(&arr[cur], &arr[cur - 1]);
			}
		}
	}
}

int main()
{
	int arr[] = { 9, 5, 2, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
