// strlen的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t Strlen(const char* str)
{
	assert(str != NULL);
	size_t size = 0;
	while (str[size] != '\0')
	{
		++size;
	}
	return size;
}

int main()
{
	char str[] = "Hello World!";
	printf("%d\n", Strlen(str));
	system("pause");
	return 0;
}
