// 短路求值，针对&& ||
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//对于逻辑与来说，如果左侧的表达式值为假，那么就不再计算右侧的表达式
	//对于逻辑或来说，如果左侧的表达式值为真，那么就不再计算右侧的表达式
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	i = a++ || ++b || d++;
	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
	system("pause");
	return 0;
}
