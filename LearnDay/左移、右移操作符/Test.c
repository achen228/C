// 左移/右移操作符
// 对于CPU来说，进行移位操作的运算效率大大高于乘除法的运算效率
// 注意：不可以移动负数位或过大数字，是未定义行为 即 num << -1 或 num << 50 是错误的
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1 = 10;
	num1 = num1 << 1; // 左移一位，相当于乘2
	printf("%d\n", num1); // num1 = 20
	int num2 = 10;
	num2 = num2 >> 1; // 右移一位，相当于除2
	printf("%d\n", num2); // num2 = 5
	system("pause");
	return 0;
}
