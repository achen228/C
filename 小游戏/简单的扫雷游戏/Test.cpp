#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define Mine_Count 10

int Menu()
{
	printf("===============\n");
	printf("  1.开始游戏\n");
	printf("  0.结束游戏\n");
	printf("===============\n");
	printf("请输入您的选项：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
