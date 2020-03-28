// memcpy的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* Memcpy(void* dest, void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	for (size_t i = 0; i < num; ++i)
	{
		pdest[i] = psrc[i];
	}
	return dest;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 0 };
	Memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", arr2[i]);
	}
	system("pause");
	return 0;
}
