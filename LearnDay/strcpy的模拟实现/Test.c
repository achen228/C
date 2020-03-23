// strcpy的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strcpy(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	int i = 0;
	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char str[1024] = "abcdef";
	Strcpy(str, "Hello World!");
	printf("%s\n", str);
	system("pause");
	return 0;
}
