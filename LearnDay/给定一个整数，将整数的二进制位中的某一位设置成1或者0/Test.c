// 给定一个整数，将整数的二进制位中的某一位设置成1或者0
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 10 -> 0000 1010
	int num1 = 10;
	// 1  -> 0000 0001
	//    -> 0001 0000
	// 0000 1010
	// 0001 0000
	// 0001 1010 
	num1 = num1 | (1 << 4); // 将第四位设置成1
	printf("%x\n", num1);

	// 1  -> 0000 0001
	//    -> 0001 0000
	//    -> 1110 1111
	// 0001 1010
	// 1110 1111
	// 0000 1010
	num1 = num1 & ~(1 << 4); // 将第四位设置成0
	printf("%x\n", num1);
	system("pause");
	return 0;
}
