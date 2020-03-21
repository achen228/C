// 字符指针
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char ch = 'w'; // 无 \0
	char* p = &ch;
	int ret = strlen(p); // 会访问到非法内存
	printf("%d\n", ret);

	char* p2 = "Hello"; // 有 \0
	printf("%d\n", strlen(p2)); // 遇到 \0 终止
	system("pause");
	return 0;
}
