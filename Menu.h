#pragma once
#include"GameSystem.h"

class Menu
{
public:
	void pausemenu();
	void load();
	void print();
	void controlmenu();
	void CursorPosition(int x, int y);
	void process();
private:
	char _level[30][90];
	char _menudata[30][90];
	int _x;
	int _y;
	char _input;

};

