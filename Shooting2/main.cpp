#include <iostream>
#include <time.h>
#include <vector>

#include "Enemy.h"
#include "Missile.h"
#include "Console.h"
#include "EnemyMissile.h"

#define UP			72
#define DOWN		80
#define LEFT		75
#define RIGHT		77

using namespace std;

int x, y, missileCount;

vector<Enemy> enemies; 
vector<Missile> myMissiles;
vector<EnemyMissile> enemyMissiles;

void setConsoleView()
{
	system("mode con:cols=40 lines=40");
	system("title SHOOTING GAME #2");
}

void initData()
{
	srand((unsigned)time(NULL));

	x = 10;
	y = 38;

	missileCount = 0;

	enemies.clear();
	myMissiles.clear();
}

void checkDirection()
{
	int key = _getch();

	switch (key)
	{
	case UP:
		if (y > 0)
		{
			y--;
		}
		break;

	case DOWN:
		if (y < 38)
		{
			y++;
		}
		break;

	case LEFT:
		if (x > 0)
		{
			x--;
		}
		break;

	case RIGHT:
		if (x < 19)
		{
			x++;
		}
		break;
	}
}

void checkCollision()
{
	bool bCollision = false;

	do
	{
		bCollision = false;

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			for (int j = 0; j < (int)enemies.size(); j++)
			{
				if (myMissiles[i].checkCollision(enemies[j].getX(), enemies[j].getY()))
				{
					myMissiles.erase(myMissiles.begin() + i);
					enemies.erase(enemies.begin() + j);

					bCollision = true;
					break;
				}
			}

			if (bCollision)
			{
				break;
			}
		}
	} while (bCollision);
}

void enemyMissileCollision()
{
	bool bCollision = false;

	do
	{
		bCollision = false;

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			for (int j = 0; j < (int)enemyMissiles.size(); j++)
			{
				if (myMissiles[i].checkCollision(enemyMissiles[j].getX(), enemyMissiles[j].getY()))
				{
					myMissiles.erase(myMissiles.begin() + i);
					enemyMissiles.erase(enemyMissiles.begin() + j);

					bCollision = true;
					break;
				}
			}

			if (bCollision)
			{
				break;
			}
		}
	} while (bCollision);
}

bool playerColision()
{
	for (int i = 0; i < (int)enemyMissiles.size(); i++)
	{
		if (enemyMissiles[i].checkCollision(x, y))
			return true;
	}
	return  false;
}

void drawPlayer()
{
	gotoXY(x, y);
	cout << "▲";

	gotoXY(19, 39);
}

void enemyFire()
{
	EnemyMissile enemyMissile;
	enemyMissile.setMissile(enemies[rand() % enemies.size()].getX(), enemies[rand() % enemies.size()].getY() + 2);
	enemyMissiles.push_back(enemyMissile);
}

int main()
{
	setConsoleView();

	initData();

	while (true)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 0xE0)
		{
			checkDirection();
		}
		else if (key == 'a')
		{
			if (missileCount == 0)
			{
				Missile missile;
				missile.setMissile(x, y);

				myMissiles.push_back(missile);

				missileCount = 3;
			}
		}

		// 10% 확률로 적 출현
		if (rand() % 100 < 10)
		{
			Enemy enemy;
			enemy.setEnemy();

			enemies.push_back(enemy);
			if (rand() % 100 < 50)
			{
				enemyFire();
			}
		}


		if (playerColision())
		{
			return 0;
		}

		checkCollision();
		enemyMissileCollision();

		for (int i = 0; i < (int)enemies.size(); i++)
		{
			enemies[i].drawEnemy();
		}

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			enemyMissiles[i].drawMissile();
		}

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			myMissiles[i].drawMissile();
		}

		drawPlayer();

		for (int i = 0; i < (int)enemies.size(); i++)
		{
			if (enemies[i].checkEnd())
			{
				enemies.erase(enemies.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			if (myMissiles[i].checkEnd())
			{
				myMissiles.erase(myMissiles.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)enemyMissiles.size(); i++)
		{
			if (enemyMissiles[i].checkEnd())
			{
				enemyMissiles.erase(enemyMissiles.begin() + i);
				i--;
			}
		}

		if (missileCount > 0)
		{
			missileCount--;
		}

		Sleep(100);
		clrscr();
	}

	return 0;
}