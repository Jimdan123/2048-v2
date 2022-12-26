#include "Tile.h"
#include "Board.h"
using namespace std; 
Tile::Tile()
{
	number = 0;
}
void Tile::setNumber(int a)
	{
		number = a;
	}
	int Tile::getNumber()
	{
		return number;
	}
