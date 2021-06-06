#include "EnemyMissile.h"
#include "Console.h"

#include <iostream>
using namespace std;

void EnemyMissile::setMissile(int _x, int _y)
{
	x = _x;
	y = _y;
}

void EnemyMissile::drawMissile()
{
	gotoXY(x, y);

	setTextColor(2);
	cout << "бр";
	setTextColor(15);

	y += 2;
}

bool EnemyMissile::checkEnd()
{
	if (y < 0)
	{
		return true;
	}
	return false;
}

bool EnemyMissile::checkCollision(int _x, int _y)
{
	if (x == _x && y == _y)
	{
		return true;
	}
	return false;
}

int EnemyMissile::getX()
{
	return this->x;
}

int EnemyMissile::getY()
{
	return this->y;
}