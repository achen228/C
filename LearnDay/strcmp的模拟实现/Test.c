// strcmp的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int Strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 > * str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			++str1;
			++str2;
		}
	}

	if (*str1 < *str2)
	{
		return -1;
	}
	else if (*str1 > * str2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char str1[] = "bbb";
	char str2[] = "aaa";
	int ret = Strcmp(str1, str2);
	if (ret < 0)
	{
		printf("str1 < str2\n");
	}
	else if (ret > 0)
	{
		printf("str1 > str2\n");
	}
	else
	{
		printf("str1 == str2\n");
	}
	system("pause");
	return 0;
}
