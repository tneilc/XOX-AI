#pragma once
#define num 3
#include <iostream>
#include <climits>
class controller
{
public:
	controller();
public:
	void HumanMove(int index);
	int FindBestMove(bool isMaximizing);
	bool checkEmpty(int row, int col);
	char daWinner();
	bool anyEmpty();
	int AIMove();

	char board[3][3] = {
	{' ',' ',' '},
	{' ',' ',' '},
	{' ',' ',' '} };
};

