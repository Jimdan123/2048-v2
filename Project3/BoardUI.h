#pragma once

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Board;

class BoardUI
{
	public:
	int NUMBER_SPACE = 5;
	int CELL_WIDTH = 5;
	int CELL_HEIGHT = 3;
	void printTopMenu(int score, int highscore);
	void printLineType1(int width);
	void printLineType2(Board * board, int i, int j);
	void printBoard(Board *board);
	void printMenu();
	void printLeaderBoard(int *a, int n);
};