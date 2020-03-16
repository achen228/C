// 判断当前机器的字节序
#include <stdio.h>
#include <stdlib.h>

void IsLittle()
{
	int num = 0x11223344;
	char* ret = (char*)&num;
	if (*ret == 0x11)
	{
		printf("大端字节序\n");
	}
	printf("小端字节序\n");
}

int main()
{
	IsLittle();
	system("pause");
	return 0;
}
