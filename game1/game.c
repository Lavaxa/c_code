#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if(i < row - 1)
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
	}
}
void PlayarMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1) {
		printf("请输入坐标>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("输入位置已被占用,请重新输入\n");
			}
		}
		else
			printf("超出限制，重新输入\n");
	}
}
void Computer(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	while (1) {
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

} 
//满了返回1
//不满返回0
int Full(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char isWin(char board[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//判断列
	int j = 0;
	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][i] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}
    if (Full(board, row, col)) {
		return 'Q';
	}
	
		return 'C';
}




