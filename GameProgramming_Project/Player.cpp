#include "headers_WhatIneed.h"

Player::Player()
{
	this->pos = new Data::Position();
	this->exit_XY = new Data::Position();
	this->moveCount = 0;
}

void Player::ShowScreenFirst(Data::Position pos, int map[][12])
{
	cout << pos.x << pos.y << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 3)
			{
				this->exit_XY->x = j;
				this->exit_XY->y = i;
				cout << "▣";
			}
			if (map[pos.y] == map[i] && map[pos.x] == map[j])
			{
				cout << "★";
				continue;
			}
			if (map[i][j] == 1) cout << "■";
			if (map[i][j] == 0) cout << "□";
		}
		cout << endl;
	}
}

void Player::ShowScreen(int map[][12])
{
	cout << "현재 좌표는 " << pos->x << " , " << pos->y << endl;
	cout << endl;
	cout << "움직인 횟수는 " << moveCount << endl;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 3)
			{
				cout << "▣";
			}
			if (map[pos->y] == map[i] && map[pos->x] == map[j])
			{
				cout << "★";
				continue;
			}
			if (map[i][j] == 1) cout << "■";
			if (map[i][j] == 0) cout << "□";
		}
		cout << endl;
	}

}