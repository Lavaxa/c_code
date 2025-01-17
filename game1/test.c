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
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);
		Computer(board, ROW, COL);
		//�ж���Ӯ
		ret = isWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		DisplayBoard(board, ROW, COL);	
	}
	if (ret == '*') {
		printf("��Ӯ�ˣ�\n");
	}
	else if (ret == '#') {
		printf("�����ˣ�\n");
	}
	else{
		printf("ƽ��\n");
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
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����");
			break;

		}
	} while (input);
}




