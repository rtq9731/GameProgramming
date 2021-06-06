#include "Missile.h"
#include "Console.h"

#include <iostream>
using namespace std;

void Missile::setMissile(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Missile::drawMissile()
{
	gotoXY(x, y);

	setTextColor(2);
	cout << "¡Û";
	setTextColor(15);

	y--;
}

bool Missile::checkEnd()
{
	if (y < 0)
	{
		return true;
	}
	return false;
}

bool Missile::checkCollision(int _x, int _y)
{
	if (x == _x && y == _y)
	{
		return true;
	}
	return false;
}