#include <time.h>
#include <vector>
#include <iostream>

#include "Console.h"
#include "MIssile.h"

using namespace std;

bool bMoveDown;
int y;

vector<Missile> missiles;
vector<Missile> myMissiles;

void setConsoleView()
{
	system("mode con:cols=60 lines=20");
	system("title SHOOTING GAME");
}

int main()
{
	int key = 0;
	bMoveDown = true;
	y = 0;;

	srand((unsigned)time(NULL));

	missiles.clear();
	myMissiles.clear();

	setConsoleView();
	
	while (true)
	{
		key = getKeyDown();
		key = tolower(key);

		if (key == 'a')
		{
			Missile myMissile;
			myMissile.set(y);

			myMissiles.push_back(myMissile);
		}

		if ((rand() % 100) < 10)
		{
			Missile missile;
			missile.set(-1);

			missiles.push_back(missile);
		}

		for (int i = 0; i < (int)missiles.size(); i++)
		{
			missiles[i].move();
			missiles[i].draw();
		}

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			myMissiles[i].move();
			myMissiles[i].draw();
		}

		//10% È®·ü·Î »ý¼º
		gotoXY(2, y);
		cout << "¢º";
		gotoXY(59, 19);
	
		if (bMoveDown)
		{
			y++;
			if (y > 19)
			{
				y = 19;
				bMoveDown = false;
			}
		}
		else
		{
			y--;
			if (y < 0)
			{
				y = 0;
				bMoveDown = true;
			}
		}

		for (int i = 0; i < (int)missiles.size(); i++)
		{
			if (missiles[i].checkEnd())
			{
				missiles.erase(missiles.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < (int)myMissiles.size(); i++)
		{
			for (int e = 0; e < (int)missiles.size(); e++)
			{
				if (myMissiles[i].getPos().x == missiles[e].getPos().x
					&& myMissiles[i].getPos().y == missiles[e].getPos().y)
				{
					missiles.erase(missiles.begin() + e);
					myMissiles.erase(myMissiles.begin() + i);
				}
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

		Sleep(50);
		clrscr();
	}

	return(0);
}