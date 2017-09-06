#pragma once
#include<string>

using namespace std;
class Enemy
{
public:
	void enemy(string name,char tile,int level,int attack,int defense,int health,int xp);
	int attack();
	int TakeDamage(int attack);

	//setters
	void setPosition(int x, int y);

	//getters
	void getPosition(int &x, int &y);

private:
	string _name;
	char _tile;
	int _level;
	int _attack;
	int _defense;
	int _health;
	int _experienceValue;

	//Position
	int _x;
	int _y;
};

