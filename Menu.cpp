#include<fstream>
#include<iostream>
#include<string>
#include<conio.h>
#include"Menu.h"

using namespace std;

void Menu::pausemenu()
{
	//LOADS THE MENU
	ifstream file;

	file.open("pause.txt");
	if (file.fail())
	{
		cerr << "Failed" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		file.getline(_menudata[i], 90);
	}
	file.close();

	print();
	system("pause");
}

void Menu::load()
{
	//LOADS THE MENU
	ifstream file;

	file.open("menu.txt");
	if (file.fail())
	{
		cerr << "Failed" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		file.getline(_menudata[i], 90);
	}
	file.close();

	print();
	system("pause");
}

void Menu::process()
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < strlen(_menudata[i]); j++) {
			if (_menudata[i][j] == '>') {
				CursorPosition(j, i);
			}

		}
	}
}

void Menu::print()
{
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		cout << _menudata[i];
		cout << endl;
	}
	cout << endl;
}


void Menu::controlmenu()
{
	_input = _getch();
	switch (_input) {
	case 'w':
	case 'W':
		if (_menudata[_y - 1][_x] == '*') {
			//CANT MOVE
		}
		else {
			_menudata[_y - 1][_x] = _menudata[_y][_x];
			_menudata[_y][_x] = ' ';
		}
		break;
	case 'S':
	case 's':
		if ((_menudata[_y + 1][_x] == '*')||(_menudata[_y + 1][_x] == 'J')) {
			//CANT MOVE
		}
		else {
			_menudata[_y + 1][_x] = _menudata[_y][_x];
			_menudata[_y][_x] = ' ';
		}
		break;
	case char(13) :
		if (_menudata[_y][_x + 2] == 'N') {
			GameSystem gamesystem("level1.txt");
			gamesystem.PlayGame();
		}
		else if (_menudata[_y][_x + 2] == 'L') {
			char pname[100];
			cout << "Enter Your Profile Name" << endl;
			cin.getline(pname, 100);
			GameSystem gamesystem(pname);
			gamesystem.PlayGame();
		}
		else {
			system("pause");
			exit(1);
		}
	}
	print();
}

void Menu::CursorPosition(int x, int y)
{
	_x = x;
	_y = y;
}
