#include "headers_WhatIneed.h"

int backgroundMap[12][12] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
}; // 저장 하고 있을 맵.

int currentMap[12][12] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
}; //실시간으로 데이터가 저장 될 맵.

int main()
{
	srand((unsigned)time(NULL));


	Data* dataClass = new Data();
	dataClass->refreshMaze();
	dataClass->getMaze(backgroundMap);
	dataClass->getMaze(currentMap);

	Data::Position* playerPos = new Data::Position();
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (backgroundMap[i][j] == 2)
			{
				playerPos->x = j;
				playerPos->y = i;
			}
		}
	}

	Player playerClass;
	playerClass.ShowScreenFirst(*playerPos, backgroundMap);

}