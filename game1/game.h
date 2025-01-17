#pragma once
#define ROW 3
#define COL 3
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayarMove(char board[ROW][COL], int row, int col);

void Computer(char board[ROW][COL], int row, int col);

char isWin(char board[ROW][COL], int row, int col);


//���Ӯ - *
//����Ӯ - #
//����   - C
//ƽ�� - Q