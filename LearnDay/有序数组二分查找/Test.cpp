#include <stdio.h>
#include <stdlib.h>
int BinaryFind(int arr[], int size, int to_find)
{
	// 待查找区间[left, right]
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (to_find < arr[mid])
		{
			right = mid - 1;
		}
		else if(to_find > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 5, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int to_find = 10;
	int ret = BinaryFind(arr, size, to_find);

	if (ret == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了\n");
	}
	system("pause");
	return 0;
}
