#include "Level.h"
#include<fstream>
#include<iostream>

#include"Enemy.h"
#include"Menu.h"



Level::Level()
{
	_k = -1;
}

void Level::load(string filename,Player &player)
{
	//LOADS THE LEVEL
	ifstream file;
		
	file.open(filename);
	if (file.fail())
	{
		cerr << "Failed" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < 30; i++) {
		file.getline(_leveldata[i], 90);
	}
	file.close();

	//PROCESS THE LEVEL
	char tile;

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < strlen(_leveldata[i]); j++) {
			tile = _leveldata[i][j];
			switch (_leveldata[i][j]) {
			case '@': //PLAYER
				player.setPosition(j, i);
				break;
			case 'S': //SNAKE
				_k++;
				_enemies[_k].enemy("Snake",tile,1,10,5,60,20);
				_enemies[_k].setPosition(j, i);
				break;
			case 'G': //GOBLIN
				_k++;
				_enemies[_k].enemy("Goblin",tile,5,30,7,70,60);
				_enemies[_k].setPosition(j, i);
				break;
			case 'D': //DRAGON
				_k++;
				_enemies[_k].enemy("Dragon",tile,200,200,200,2000,50000);
				_enemies[_k].setPosition(j, i);
				break;
			}
		}
	}
}

void Level::print()
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		cout << _leveldata[i];
		cout << endl;
	}
	cout << endl;
}

void Level::MovePlayer(char input,Player &player)
{
	int PlayerX;
	int PlayerY;
	int q = 10;
	Menu menu;
	player.getPosition(PlayerX, PlayerY);

	switch (input) {
			//UP
		case 'w':
		case 'W':
			playerMoveProcess(player, PlayerX, PlayerY - 1);
				break;
			//LEFT
		case 'a':
		case 'A':
			playerMoveProcess(player, PlayerX - 1, PlayerY);
			break;
			//DOWN
		case 's':
		case 'S':
			playerMoveProcess(player, PlayerX, PlayerY + 1);
			break;
			//RIGHT
		case 'D':
		case 'd':
			playerMoveProcess(player, PlayerX + 1, PlayerY);
			break;
		case char(27) :
			menu.pausemenu();
			while (q >= 0) {
				menu.process();
				menu.controlmenu();
				q--;
			}
			break;
		default:
			cout << "INVALID INPUT";
			cout << endl;
			system("pause");
			break;


	}
}

char Level::getTile(int x, int y)
{
	char tile = _leveldata[y][x];

	return tile;
}

void Level::setTile(int x, int y, char tile)
{
	_leveldata[y][x] = tile;
}

void Level::playerMoveProcess(Player &player, int TargetX, int TargetY)
{
	int PlayerX;
	int PlayerY;
	player.getPosition(PlayerX, PlayerY);

	char movetile = getTile(TargetX, TargetY);

	switch (movetile) {
	case '.':
		player.setPosition(TargetX, TargetY);
		setTile(PlayerX, PlayerY, '.');
		setTile(TargetX, TargetY, '@');
		break;
	case '#':
		break;
	default:
		BattleMonster(player, TargetX, TargetY);
		break;
	}
}

void Level::BattleMonster(Player & player, int TargetX, int TargetY)
{
	int enemyX,playerX;
	int enemyY,playerY;
	int attackRoll;
	int attackResult;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _k; i++) {
		_enemies[i].getPosition(enemyX, enemyY);
		if ((TargetX == enemyX) && (TargetY == enemyY)) 
		{

			//Battle
			attackRoll = player.attack();
			cout << "Player Attacked Enemy With a Roll of " << attackRoll << endl;
			attackResult = _enemies[i].TakeDamage(attackRoll);
			if (attackResult > 0) 
			{
				setTile(TargetX, TargetY, '.');
				print();
				cout << "Enemy Died"<<endl;
				system("pause");
				player.AddXP(attackResult);
				return;
			}
			//Enemy Turn
			attackRoll = _enemies[i].attack();
			cout << "Enemy Attacked Player With a Roll of " << attackRoll << endl;
			attackResult = player.TakeDamage(attackRoll);
			if (attackResult > 0) {
				setTile(playerX, playerY, '*');
				print();
				cout << "You Died" << endl;
				system("pause");
				Menu menu;
				menu.load();
				while (true) {
					menu.process();
					menu.controlmenu();
				}
			}
			system("pause");
			return;

		}

	}
}