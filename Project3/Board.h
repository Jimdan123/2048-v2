#pragma once
#include <iostream>
#include <vector>
#include "Tile.h"

using namespace std;

class BoardUI;

class Board
{
public:
	BoardUI *boardUI;
	int row;
	int column;
	Tile ** board;
	Board(int n, int m);
	void resetBoard();
	void setNumber(int row, int column, int number);
	void getEmptyCell(vector<pair<int, int>>&store);
	vector<pair<int, int>> getEmptyCell();
	bool canMoveDown();
	bool canMoveUp();
	bool canMoveRight();
	bool canMoveLeft();
	~Board();
	void rotate();
	bool checkWinCondition(int WIN_CONDITION);
	void create2DArray(int **&store);
	void copy2DArray(int **&store);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void print();
};
