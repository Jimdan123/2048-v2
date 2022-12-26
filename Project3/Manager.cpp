#include "Manager.h"
Manager::Manager()
{
	board = new Board(n, m);
}

void Manager::start()
{
	board->updateLeaderBoard();
	board->resetBoard();
	randomizer();
	board->print();
	move();
}

void Manager::randomizer()
{
	srand(time(NULL));
	vector<pair<int, int>> store;
	board->getEmptyCell(store);
	// To do store.size() == 0
	if (store.size() == 0)
	{
		return;
	}
	int result = rand() % store.size();
	board->setNumber(store[result].first, store[result].second, 2);
}

void Manager::move()
{
	while (true)
	{
		if (_kbhit()) // Kiểm tra vùng nhớ đệm
		{
			bool flag = true;
			char c = _getch(); // lấy kí tự
			switch (c)
			{
			case 'w':
				flag = board->canMoveUp();
				board->moveUp();
				break;
			case 'd':
				flag = board->canMoveRight();
				board->moveRight();
				break;
			case 's':
				flag = board->canMoveDown();
				board->moveDown();
				break;
			case 'a':
				flag = board->canMoveLeft();
				board->moveLeft();
				break;
			case 'f':
				playAgain();
				flag = false;
				break;
			case '2':
				system("cls");
				board->printLeaderBoard();
				flag = false;
				break;
			default:
				flag = false;
			}
			if (flag == false)
			{
				continue;
			}
				randomizer();
				board->print();
			if (win() == true)
			{
				cout << "Win" << '\n';
				break;
			}
			if (fail())
			{
				cout << "Lost" << '\n';
				break;
			}
		}

	}
	playAgain();
}

 bool Manager::win()
{
	if (board->checkWinCondition(WIN_CONDITION))
	{
		return true;
	}
}
 void Manager::playAgain()
 {
	 cout << "Press any button to start";
	 _getch();
	 system("cls");
	 start();
 }
 //kieemr tra nuows ddi hopwj leej thif moiws cho 
 bool Manager::fail()
 {
	 //cout << board->getEmptyCell().size() << '\n';
	 //cout << board->canMoveDown() << ' ' << board->canMoveUp() << ' ' << board->canMoveRight() << ' ' << board->canMoveLeft();
	 if (board->getEmptyCell().size() == 0)
	 {
		 if (board->canMoveDown() + board->canMoveUp() + board->canMoveRight() + board->canMoveLeft() == 0)
		 {
			 return true;
		 }
	 }
	 return false;
 }
