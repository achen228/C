#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main()
{
	system("color 4");
	char str1[] = "I love RouRou forever!";
	char str2[] = "                      ";
	printf("%s\n", str2);
	int left = 0;
	int right = strlen(str1) - 1;
	while (left <= right)
	{
		Sleep(600); // Windows操作系统提供的函数
		system("cls"); // 清屏
		str2[left] = str1[left];
		str2[right] = str1[right];
		printf("%s\n", str2);
		++left;
		--right;
	}
	system("pause");
	return 0;
}
