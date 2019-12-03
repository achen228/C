#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu()
{
	printf("========================\n");
	printf("1.开始游戏   0.退出游戏\n");
	printf("========================\n");
	printf("请输入您的选项：");
	int choice = 0;
	scanf_s("%d", &choice);
	return choice;
}
