#include <iostream>
#include <conio.h>
#include "Board.h"
#include "Manager.h"
using namespace std; 
int main ()
{
	Manager *game = new  Manager(); 
	game->start();
}
