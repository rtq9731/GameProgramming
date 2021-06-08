#include "headers_WhatIneed.h"

int coin = 0;

int main()
{
	srand((unsigned)time(NULL));

	Data* dataClass = new Data();
	Player* player = new Player();
	dataClass->refreshMaze();
	dataClass->getMaze(player->backgroundMap);
	dataClass->getMaze(player->currentMap);

	Data::Position* playerPos = new Data::Position();
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (player->backgroundMap[i][j] == 2)
			{
				playerPos->x = j;
				playerPos->y = i;
			}
		}
	}

	player->SetPosition(playerPos->x, playerPos->y);
	player->ShowScreenFirst(*playerPos, player->backgroundMap);
	
	player->MoveToExit();
}