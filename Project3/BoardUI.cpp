#include "BoardUI.h"
#include "Board.h"

void BoardUI::printTopMenu(int score, int highscore)
{
	//system("Color 5A");
	cout << "Score";
	for (int i = 0; i < NUMBER_SPACE; i++)
	{
		cout << ' ';
	}
	cout << "Best" << '\n';
	cout << score;
	for (int i = 0; i < NUMBER_SPACE; i++)
	{
		cout << ' ';
	}
	cout << highscore;
	cout << "\n";
}

void BoardUI::printLineType1(int width)
{
	for (int i = 0; i < width; ++i)
		cout << "*";
	cout << '\n';
}

string alignCenter(string s, int length)
{
	if (s.size() >= length)
		return s;
	string res = "";
	int padding = (length - s.size()) / 2;
	for (int i = 0; i < padding; ++i)
	{
		res += " ";
	}
	res += s;
	
	for (int i = res.size(); i < length; ++i)
	{
		res += " ";
	}
	return res;
}

void BoardUI::printLineType2(Board *board, int i, int j)
{
	string formatType = "%";
	formatType += to_string(CELL_WIDTH - 2);
	formatType += "d";
	cout << "*";
	for (int k = 0; k < board->column; k++)
	{
		/*
		for (int k = 0; k < CELL_WIDTH - 2; ++k)
			cout << " ";
		*/
		cout << alignCenter(to_string(board->board[i][j].getNumber()), CELL_WIDTH - 2);
		j += 1;
		cout << "*";
	}
	cout << '\n';
}

void BoardUI::printBoard(Board *board)
{
	cout << "\n";
	int height = board->row * CELL_HEIGHT - (board->row - 1);
	int width = board->column * CELL_WIDTH - (board->column - 1);
	int k = 0;
	int cnt = 0;
	for (int i = 0; i < height; i++)
	{
		if (k == CELL_HEIGHT - 2)
		{
			printLineType1(width);
			k = 0;
			cnt += 1;
			continue;
		}
		if (i != 0 && i != height - 1)
		{
			printLineType2(board, cnt, 0);
			k += 1;
		}
		else
		{
			printLineType1(width);
		}
	}
	cout << "\n";
}

void BoardUI::printMenu()
{
	cout << "1. Menu" << '\n';
	cout << "2. LeaderBoard" << '\n';
}

void BoardUI::printLeaderBoard(int *a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << i << '.' << a[i] << '\n';
	}
}
