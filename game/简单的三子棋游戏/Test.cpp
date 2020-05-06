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


char CheckWinner(char broad[ROW][COL])
{
	int row = 0, col = 0;
	//检查所有行
	for (row = 0; row < ROW; row++)
	{
		if (broad[row][0] == broad[row][1] && broad[row][0] == broad[row][2]
			&& broad[row][0] != ' ')
			return broad[row][0];
	}
	//检查所有列
	for (col = 0; col < COL; col++)
	{
		if (broad[0][col] == broad[1][col] && broad[0][col] == broad[2][col]
			&& broad[0][col] != ' ')
			return broad[0][col];
	}
	//检查所有对角线
	if (broad[0][0] == broad[1][1] && broad[0][0] == broad[2][2]
		&& broad[0][0] != ' ')
		return broad[0][0];
	if (broad[2][0] == broad[1][1] && broad[2][0] == broad[0][2]
		&& broad[2][0] != ' ')
		return broad[2][0];
	if (IsFull(broad))
	{
		return 'q';
	}
	return ' ';
}


int IsFull(char broad[ROW][COL])
{
	int row = 0, col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (broad[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


int menu()
{
	printf("***************\n");
	printf("  1.玩家先走\n");
	printf("  0.电脑先走\n");
	printf("***************\n");
	int choose;
	printf("请输入您的选项：");
	while (1)
	{
		scanf("%d", &choose);
		if (choose != 1 && choose != 0)
		{
			printf("您的输入有误！请重新输入：");
			continue;
		}
		break;
	}
	return choose;
}


void Game()
{
	//2.先对棋盘进行初始化
	Init(g_broad);
	//Winner='x',玩家胜，winner='o',电脑胜，winner='q',和棋,winner=' ',继续循环进行游戏
	char Winner;
	printf("\n"); //给两个菜单之间换行，界面好看
	int choose = menu();
	if (choose == 1)
	{
		Print(g_broad);
		PlayerMove(g_broad);
		ComputerMove(g_broad);
	}
	else
	{
		ComputerMove(g_broad);
	}
	//switch (choose)
	//{
	//case 1:	Print(g_broad);
	//	    PlayerMove(g_broad);
	//	    Winner = CheckWinner(g_broad);
	//	    if (Winner != ' ')
	//		{
	//		    break;
	//	    }
	//case 2: Print(g_broad);
	//	    ComputerMove(g_broad);
	//	    Winner = CheckWinner(g_broad);
	//	    if (Winner != ' ')
	//		{
	//		   break;
	//	    }
	//		break;
	//}
	while (1)
	{
		//3.打印棋盘（第一次打印的是一个空的棋盘）
		Print(g_broad);
		//4.玩家落子，检查游戏是否结束
		PlayerMove(g_broad);
		Winner = CheckWinner(g_broad);
		if (Winner != ' ')
		{
			break;
		}
		//5.电脑落子，检查游戏是否结束
		ComputerMove(g_broad);
		Winner = CheckWinner(g_broad);
		if (Winner != ' ')
		{
			break;
		}
	}
	Print(g_broad);
	if (Winner == 'x')
	{
		printf("亲,恭喜您胜利啦！\n");
	}
	else if (Winner == 'o')
	{
		printf("亲，再接再厉！重新开始一局吧！\n");
	}
	else if (Winner == 'q')
	{
		printf("和棋！\n");
	}
	else
	{
		printf("程序出错！\n");
	}
}


int Menu()
{
	printf("===============\n");
	printf("  三子棋游戏\n");
	printf("  1.开始游戏\n");
	printf("  0.结束游戏\n");
	printf("===============\n");
	int choice;
	printf("请输入您的选项：");
	scanf("%d", &choice);
	return choice;
}


int main()
{
	//随机种子的设置，程序启动的时候设置一次就行
	srand((unsigned int)time(0));
	system("color  2");
	while (1)
	{
		//1.设置一个菜单给用户提供选择
		int choice = Menu();
		if (choice == 1)
		{
			Game();
			//break;
		}
		else 
		{
			printf("Game Over!\n");
			break;
		}
	}
	system("pause");
	return 0;
}
