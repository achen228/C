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


void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
{
	// 1.show_map 全部初始化成 *（用 * 表示没有被翻开的位置）
	for (int row = 0; row < ROW + 2; row++)
	{
		for (int col = 0; col < COL+2; col++)
		{
			show_map[row][col] = '*';
		}
	}
	// 2.mine_map 先全都初始化成 '0'
	for (int row = 0; row < ROW + 2; row++)
	{
		for (int col = 0; col < COL+2; col++)
		{
			mine_map[row][col] = '0';
		}
	}
	// memset函数 能够对一段连续的内存空间进行赋值操作
	// 二维数组也是在一个连续的内存空间上
	// memset(show_map, '*', (ROW + 2)*(COL + 2));
	// memset(mine_map, '0', (ROW + 2)*(COL + 2));
	// 3.对 mine_map 进行雷阵的布置
	int mine_count = Mine_Count;
	while (mine_count>0)
	{
		// 这个循环尝试进行布雷，每次成功布置一个雷，mine_count--
		int row = rand() % ROW + 1;
		int col = rand() % ROW + 1;
		if (mine_map[row][col] == '1')
		{
			continue;
		}
		// 当前位置可以用来设置地雷
		mine_map[row][col] = '1';
		mine_count--;
	}
}
