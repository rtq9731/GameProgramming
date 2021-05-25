#include "MIssile.h"
#include "Console.h"

#include <iostream>

using namespace std;

void Missile::set(int _y)
{
	if(_y == -1)
	{
		x = 59;
		y = rand() % 20;

		bMoveLeft = true;
	}
	else
	{
		x = 3;
		y = _y;
		bMoveLeft = false;
	}

}

void Missile::move()
{
	if (bMoveLeft)
	{
		x--;
	}
	else
	{
		x++;
	}
}

void Missile::draw()
{
	if (x < 1 || x > 58) return;

	gotoXY(x, y);

	if (bMoveLeft)
	{
		setTextColor(1);
		cout << "¢¸";
		setTextColor(15);
	}
	else
	{
		setTextColor(14);
		cout << "¡æ";
		setTextColor(15);
	}
}

bool Missile::checkEnd()
{
	if (bMoveLeft)
	{
		if (x < 1)
		{
			return true;
		}
	}
	else
	{
		if (x > 59)
		{
			return true;
		}
	}

	return false;
}

Vector2 Missile::getPos()
{
	myPos.x = this->x;
	myPos.y = this->y;
	return myPos;
}

Missile::Missile()
{

}

Missile::~Missile()
{
}