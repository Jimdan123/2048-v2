#include "Board.h"
#include "BoardUI.h"
#include <stdlib.h>
using namespace std;
Board::Board(int n, int m)
{
	listHighScore = new int[SIZELIST_SCORE + 1];
	resetArray(listHighScore, SIZELIST_SCORE + 1);
	boardUI = new BoardUI();
	row = n;
	column = m;
	board = new Tile*[row];
	for (int i = 0; i < row; i++)
	{
		board[i] = new Tile[column];
	}
	resetBoard();
}
void Board::resetBoard()
{
	score = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			board[i][j].setNumber(0);
		}
	}
}
void Board::insert(int number, int index)
{
	int storeTMP = 0;
	storeTMP = listHighScore[index];
	listHighScore[index] = number;
	for (int i = index + 1; i <= SIZELIST_SCORE; i++)
	{
		number = listHighScore[i];
		listHighScore[i] = storeTMP; 
		storeTMP = number;
	}
	/*
	for (int i = SIZELIST_SCORE - 1; i > index; --i)
	{
		listHighScore[i] = listHighScore[i - 1];
	}
	listHighScore[index] = number;
	*/
}
void Board::setNumber(int row, int column, int number)
{
	board[row][column].setNumber(number);
}
void Board::getEmptyCell(vector<pair<int, int>>& store)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j].getNumber() == 0)
			{
				store.push_back({ i,j });
			}
		}
	}
}
vector<pair<int, int>> Board::getEmptyCell()
{
	vector<pair<int, int>> store;
	getEmptyCell(store);
	return store;
}
bool Board::canMoveDown()
{
	Board *b = new Board(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			b->board[i][j].setNumber(this->board[i][j].getNumber());
		}
	}
	b->moveDown(); 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (b->board[i][j].getNumber() != this->board[i][j].getNumber())
				return true;
		}
	}
	return false;
}
bool Board::canMoveUp()
{
	Board *b = new Board(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			b->board[i][j].setNumber(this->board[i][j].getNumber());
		}
	}
	b->moveUp();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (b->board[i][j].getNumber() != this->board[i][j].getNumber())
				return true;
		}
	}
	return false;
}
bool Board::canMoveRight()
{
	Board *b = new Board(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			b->board[i][j].setNumber(this->board[i][j].getNumber());
		}
	}
	b->moveRight();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (b->board[i][j].getNumber() != this->board[i][j].getNumber())
				return true;
		}
	}
	return false;
}
bool Board::canMoveLeft()
{
	Board *b = new Board(row, column);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			b->board[i][j].setNumber(this->board[i][j].getNumber());
		}
	}
	b->moveLeft();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (b->board[i][j].getNumber() != this->board[i][j].getNumber())
				return true;
		}
	}
	return false;
}
void Board::printLeaderBoard()
{
	boardUI->printLeaderBoard(listHighScore, SIZELIST_SCORE);
}
void Board::resetArray(int * a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}
Board::~Board()
{
	for (int i = 0; i < row; i++)
		delete[]board[i];
	delete[]board;
}
void Board::rotate()
{
	int **store;
	create2DArray(store);
	copy2DArray(store);
	board = new Tile *[column];
	for (int i = 0; i < column; ++i)
	{
		board[i] = new Tile[row];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			board[j][row - i - 1].setNumber(store[i][j]);
		}
	}
	swap(row, column);
}
bool Board::checkWinCondition(int WIN_CONDITION)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (board[i][j].getNumber() == WIN_CONDITION)
				return true;
		}
	}
	return false;
}
void Board::create2DArray(int **&store)
{
	store = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		store[i] = new int[column];
	}
}
void Board::copy2DArray(int **&store)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			store[i][j] = board[i][j].number;
		}
	}
}
void Board::moveUp()
{
	for (int i = 0; i < 2; i++)
	{
		rotate();
	}
	moveDown();
	for (int i = 0; i < 2; i++)
	{
		rotate();
	}

}
void Board::moveDown()
{
	for (int j = 0; j < column; ++j)
	{
		int dayXaHoi = row - 1;
		for (int i = row - 1; i >= 0; --i)
		{
			if (board[i][j].number != 0)// ở trên có biến
			{
				if (board[dayXaHoi][j].number == 0) //day ko co biến
				{
					board[dayXaHoi][j] = board[i][j];
					board[i][j].number = 0;
				}
				else
				{
					if (board[i][j].number == board[dayXaHoi][j].number)// giong nhau quat
					{
						if (i != dayXaHoi)
						{
							board[dayXaHoi][j].number += board[i][j].number;
							score += board[dayXaHoi][j].number;
							calScore();
							board[i][j].number = 0;
							--dayXaHoi;
						}
					}
					else // ko giong nhau de len dau
					{
						--dayXaHoi;
						board[dayXaHoi][j] = board[i][j];
						if (dayXaHoi != i)
							board[i][j].number = 0;
					}
				}
			}
		}
	}
}

void Board::moveLeft()
{
	for (int i = 0; i < 3; i++)
	{
		rotate();
	}
	moveDown();
	for (int i = 0; i < 1; i++)
	{
		rotate();
	}
}

void Board::moveRight()
{
	for (int i = 0; i < 1; i++)
	{
		rotate();
	}
	moveDown();
	for (int i = 0; i < 3; i++)
	{
		rotate();
	}
}

void Board::calScore()
{
	if (highscore < score)
		highscore = score;
}
void Board::updateLeaderBoard()
{
	for (int i = 1; i <= SIZELIST_SCORE; i++)
	{
			if (listHighScore[i] > score)
			{
				continue;
			}
			else
			{
				insert(score, i);
				break;
			}
		}
}
void Board::print()
{
	system("cls");
	boardUI->printTopMenu(score,highscore);
	boardUI->printBoard(this);
	boardUI->printMenu();
}
