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


void DisplayMap(char map[ROW + 2][COL + 2])
{
	// 先打印2个空格
	printf("  ");
	// 打印 列的坐标
	// [1,COL] 坐标有效范围
	for (int col = 1; col <= COL; col++)
	{
		printf("%d ", col);
	}
	printf("\n");
	// 到这里第一行就打印完成

	// 这里打印上边框
	for (int i = 1; i <= COL; i++)
	{
		printf("---");
	}
	printf("\n");

	// 打印棋盘的每一行，注意，每一行最前面要带上行号
	for (int row = 1; row <= ROW; row++)
	{
		printf("%d|", row);
		for (int col = 1; col <= COL; col++)
		{
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}


void UpdateShowMap(char mine_map[ROW+2][COL+2],
	 char show_map[ROW+2][COL+2],int row,int col)
{
	// 每次翻开一个格子的时候，如果这个格子不是地雷，就需要更新 show_map
	// 把当前位置替换成一个数字（数字就表示了当前位置周围8个格子中有几个地雷）

	//int mine_count = 0;
	//if (mine_map[row - 1][col - 1] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row - 1][col] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row + 1][col + 1] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row][col - 1] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row][col + 1] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row + 1][col - 1] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row + 1][col] = '1')
	//{
	//	++mine_count;
	//}
	//if (mine_map[row + 1][col + 1] = '1')
	//{
	//	++mine_count;
	//}

	// 第二种计算当前位置周围8个格子中有几个地雷的方法
	int mine_count =
		(mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col + 1] - '0');
	// 由于 show_map 中都是字符，需要把这个数字转为字符
	show_map[row][col] = mine_count + '0';
}


void Game()
{
	// 1.设定一个二维数组，作为表示地雷的地图，'o'表示没有地雷，'X'表示有地雷
	//   设定一个二维数组，作为给玩家看的地图，每个位置是否被翻开,如果翻开了，就会显示该位置周围有多少个地雷
	// 此处给地图加了一圈边框
	char mine_map[ROW + 2][COL + 2];
	char show_map[ROW + 2][COL + 2];
	// 2.对地雷进行初始化(包含布置地雷的过程)
	Init(mine_map, show_map);
	// 3.先打印初始的地图
	DisplayMap(show_map);
	int blank_not_mine_count = 0;
	while (1)
	{
		// 4.提示玩家输入一组坐标，并对玩家输入的坐标进行合法性检查
		printf("请输入坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		// row，col有效范围 [1,row],[1,col] 注意地图上有边框
		if (row<1 || row>ROW || col<1 || col>COL)
		{
			printf("您的坐标输入非法!请重新输入!\n");
			continue;
		}
		// 5.判定玩家翻开的位置是否是地雷，如果是地雷就游戏结束，玩家失败
		if (mine_map[row][col] == '1')
		{
			printf("您踩雷了，游戏结束！\n");
			//玩家踩雷的时候需要告诉玩家当前地图上都有哪些位置上是地雷
			DisplayMap(mine_map);
			break;
		}
		// 6.如果当前位置已经把最后一个不是地雷的位置翻开了，游戏结束，玩家胜利
		++blank_not_mine_count;
		if (blank_not_mine_count == ROW * COL - Mine_Count)
		{
			printf("扫雷成功！\n");
			DisplayMap(mine_map);
			break;
		}
		// 7.把这个位置翻开，并且计算当前位置周围8个格子中包含几个地雷
		UpdateShowMap(mine_map, show_map, row, col);
		DisplayMap(show_map);
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
			printf("Game Over!\n");
		}
	}
	system("pause");
	return 0;
}
