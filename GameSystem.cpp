#include "GameSystem.h"
#include<conio.h>





GameSystem::GameSystem(string levelfilename)
{

	_player.init(1,100,40,10,0);
	_level.load(levelfilename,_player);

	system("pause");
}

void GameSystem::PlayGame()
{
	bool isdone = false;

	while (isdone != true) {
		_level.print();
		PlayerMovement();

	}
}

void GameSystem::PlayerMovement()
{
	char input;
	cout << "enter a move command (w/a/s/d): " << endl;
	input = _getch();

	_level.MovePlayer(input ,_player);
}

