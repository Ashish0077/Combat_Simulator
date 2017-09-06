#include "Player.h"
#include<random>
#include<ctime>
#include<iostream>


using namespace std;

Player::Player()
{
	_x = 0;
	_y = 0;
}

void Player::init(int level, int health, int attack, int defense, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}

int Player::attack()
{
	static default_random_engine randomEngine((time(NULL)));
	uniform_int_distribution<int> attackRoll(1, _attack);
	return attackRoll(randomEngine);
}

int Player::TakeDamage(int attack)
{
	attack -= _defense;
	//check if the attack does damage
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return 1;
		}
	}
	return 0;
}


void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::AddXP(int experience)
{
	_experience += experience;
	//LEVEL UP
	while (_experience > 50) {
		_experience -= 50;
		_attack += 2;
		_defense += 1;
		_level++;
		cout << "Level up!!" << endl;
		system("pause");
		return;
	}
}

void Player::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

