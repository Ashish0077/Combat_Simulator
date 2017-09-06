#include "Enemy.h"
#include<random>
#include<ctime>


void Enemy::enemy(string name, char tile, int level, int attack, int defense, int health, int xp)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;

}

int Enemy::attack()
{
	static default_random_engine randomEngine((time(NULL)));
	uniform_int_distribution<int> attackRoll(1, _attack);

	return attackRoll(randomEngine);
}

int Enemy::TakeDamage(int attack)
{
	attack -= _defense;
	//check if the attack does damage
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return _experienceValue;
		}
	}
	return 0;
}

void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Enemy::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}


