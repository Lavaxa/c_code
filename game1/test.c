#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
void menu() {
	printf("************************\n");
	printf("*****1.play  0.exit*****\n");
	printf("************************\n");

}
void game() {
	int ret = 0;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1) {
		PlayarMove(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
		Computer(board, ROW, COL);
		//判断输赢
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);	
	}
	if (ret == '*') {
		printf("你赢了！\n");
	}
	else if (ret == '#') {
		printf("你输了！\n");
	}
	else{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main() {
	int input = 0;
	srand(time(NULL));
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误");
			break;

		}
	} while (input);
}




