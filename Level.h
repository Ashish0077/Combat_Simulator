#pragma once
#include<string>
#include<iostream>

#include"Player.h"
#include"Enemy.h"


using namespace std;
class Level
{
public:
	Level();

	void load(string filename, Player &player);
	void print();
	void MovePlayer(char input, Player &player);
	//Getters
	char getTile(int x, int y);
	//Setters
	void setTile(int x, int y, char tile);

private:
	void playerMoveProcess(Player &player, int TargetX, int TargetY);
	void BattleMonster(Player &player, int TargetX, int TargetY);
	char _leveldata[30][90];
	Enemy _enemies[100];
	int _k;
};

