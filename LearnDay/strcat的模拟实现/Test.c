// strcat的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* Strcat(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	int i = 0;
	for (i = 0; dest[i] != '\0'; ++i);
	for (int j = 0; src[j] != '\0'; ++j, ++i)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char str[1024] = "Hello";
	Strcat(str, "World");
	printf("%s\n", str);
	system("pause");
	return 0;
}
