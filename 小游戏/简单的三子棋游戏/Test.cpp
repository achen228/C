#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 3
#define COL 3

char g_broad[ROW][COL];

void Init(char broad[ROW][COL])
{
	int row = 0, col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			broad[row][col] = ' ';
		}
	}
}


void Print(char broad[ROW][COL])
{
	int row = 0, col = 0;
	for (row = 0; row < ROW; row++)
	{
		printf("| %c | %c | %c |\n", broad[row][0], broad[row][1], broad[row][2]);
		if (row != ROW - 1)
		{
			printf("|---|---|---|\n");
		}	
	}
}


void PlayerMove(char broad[ROW][COL])
{
	printf("玩家落子！(您的棋子是'x')\n");
	while (1)
	{
		int row = 0, col = 0;
		printf("请输入一组坐标(row col):");
		scanf("%d %d", &row, &col);
		
		//if (row > 0 || row < ROW || col>0 || col < COL)
		//{
		//	broad[row][col] = 'x';
		//	break;
		//}
		//else if (broad[row][col] != ' ')
		//{
		//	printf("该位置已经有子了！请重新输入：\n");
		//	continue;
		//}
		//else
		//{
		//	printf("您的输入非法！请重新输入：\n");
		//	continue;
		//}
		if (row<0 || row>=ROW || col<0 || col>=COL)
		{
	        printf("您的输入非法！请重新输入：\n");
			continue;
		}
	    if (broad[row][col] != ' ')
		{
			printf("该位置已经有子了！请重新输入：\n");
			continue;
		}
		broad[row][col] = 'x';
		break;
	}
}


void ComputerMove(char broad[ROW][COL])
{
	printf("电脑落子！(我的棋子是'o')\n");
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (broad[row][col] != ' ')
		{
			//该位置被占用，重新生成随机数
			continue;
		}
		broad[row][col] = 'o';
		break;
	}
}



