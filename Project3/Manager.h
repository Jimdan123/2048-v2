#pragma once
#include "Board.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
class Manager
{
public:
	Board *board; 
	const int WIN_CONDITION = 2048;
	int n = 4; 
	int m = 4;
	Manager();
	void start();
	void randomizer();
	void move();
	bool win();
	void playAgain();
	bool fail();
};