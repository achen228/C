// memmove的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* Memmove(void* dest, void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	if (psrc < pdest && (psrc + num) > pdest)
	{
		// 缓冲区重叠
		for (long i = num - 1; i >= 0; --i)
		{
			pdest[i] = psrc[i];
		}
	}
	else
	{
		// 缓冲区没有重叠，同memcpy
		for (size_t i = 0; i < num; ++i)
		{
			pdest[i] = psrc[i];
		}
	}
	return dest;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 0 };
	Memmove(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", arr2[i]);
	}
	system("pause");
	return 0;
}
