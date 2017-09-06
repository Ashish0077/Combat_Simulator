#pragma once
#include"Player.h"
#include"Level.h"
#include<vector>
#include<string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelfilename);

	void PlayGame();
	void PlayerMovement();

private:
	Player _player;
	Level _level;
};

