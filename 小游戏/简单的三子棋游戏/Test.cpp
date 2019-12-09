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

