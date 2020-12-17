#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
void menu()
{
	printf("*************************************\n");
	printf("****************1.play***************\n");
	printf("****************0.exit***************\n");
	printf("*************************************\n");
}

void initboard(char arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void print_chess(char arr[3][3], int row, int col)    //打印当前棋盘
{
	int i = 0; int j = 0;
	for (i = 0; i < row; i++)    
	{
		for (j = 0; j < col; j++)     //循环输出数组一行的元素，并用|隔开
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				putchar('|');
		}
		putchar('\n');
		for ( j = 0; j < col; j++)    //循环输出数组一行的元素，并用|隔开
		{
			if (i < row - 1)
			{
				printf("___");
			}
			else
			{
				printf("   ");
			}
			if (j < col - 1)
				putchar('|');
		}
		putchar('\n');
	}
}

void player(char arr[3][3])
{
	while (1)
	{
		int x, y;
		printf("在这里输入落子点坐标：");
		scanf("%d %d", &x, &y);
		if (Isok(arr, x, y) == 1)   //判断坐标合法性
		{
			arr[x - 1][y - 1] = 'x';
			break;
		}
		else
		{
			printf("坐标不合法，请重新输入:\n");
		}
	}
}


void computer( char arr[3][3],int row,int col)
{
	while (1)
	{
		int x, y;
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (Isok(arr, x, y) == 1)
		{
			arr[x - 1][y - 1] = 'o';
			break;
		}
	}
}

char Iswin(char arr[3][3],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')  //行
		{
			return arr[i][0];
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')  //列
		{
			return arr[0][i];
		}
		if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')  //列
		{
			return arr[0][0];
		}
		if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][0] != ' ')  //列
		{
			return arr[0][2];
		}
		if (Isfull(arr) == 1)
		{
			return 'Q';
		}
	}             //没赢没输也没平，继续游戏
	return '0';    
}

void referee(char flag)
{
	if (flag == 'x')
	{
		printf("玩家胜利！\n");
	}
	else if (flag == 'o')
	{
		printf("电脑胜利！\n");
	}
	else if (flag == 'Q')
	{
		printf("平局\n");
	}
}

int Isfull(char arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')  //存在空格，未满
			{
				return 0;
			}
		}
	}
	return 1;
}


int Isok(char arr[3][3],int x,int y)
{
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
	{
		if (arr[x - 1][y - 1] == ' ')
		{
			return 1;
		}
	}
	return 0;
}

void game()
{
	char flag = '0';
	char board[3][3];
	initboard(board, 3, 3);  //初始化棋盘
	while (flag == '0')
	{
		print_chess(board, 3, 3);  //打印当前棋盘
		player(board);  //玩家落子
		computer(board, 3, 3);  //电脑落子
		flag = Iswin(board, 3, 3);  //判断
	}
	referee(flag);  //
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择!\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(); break;
		case 0:
			printf("退出游戏！\n"); break;
		default:
			printf("选择错误！请重新选择\n"); break;
		}
	} while (input);
	system("pause");
	return 0;
}