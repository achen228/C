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


void Game()
{
	int to_guess = rand() % 100 + 1;
	while (1)
	{
		printf("请输入一个数字[1-100]:");
		int input = 0;
		scanf_s("%d", &input);
		if (input < to_guess)
		{
			printf("低了！\n");
		}
		else if (input > to_guess)
		{
			printf("高了！\n");
		}
		else
		{
			printf("恭喜您，猜对了！\n");
			break;
		}
	}
}


int main()
{
	srand((unsigned int)time(0));
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else
		{
			printf("Good Bye!\n");
			break;
		}
	}
    system("pause");
	return 0;
}
