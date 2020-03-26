// strstr的模拟实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const char* Strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != '\0');
	assert(*str2 != '\0');
	const char* black_ptr = str1;
	while (*black_ptr != '\0')
	{
		const char* red_ptr = black_ptr;
		const char* sub_ptr = str2;
		while (*red_ptr != '\0' && *sub_ptr != '\0' && *red_ptr == *sub_ptr)
		{
			++red_ptr;
			++sub_ptr;
		}
		if (*sub_ptr == '\0')
		{
			return black_ptr;
		}
		if (*red_ptr == '\0')
		{
			return NULL;
		}
		++black_ptr;
	}
	return NULL;
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "cde";
	const char* ret = Strstr(str1, str2);
	printf("%p\n", ret);
	printf("%p\n", str1);
	printf("%p\n", str2);
	system("pause");
	return 0;
}
