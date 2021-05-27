#include "headers_WhatIneed.h"

void Player::ShowScreenFirst(Data::Position pos, int map[][12])
{
	cout << pos.x << pos.y << endl;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 3) cout << "��";
			if (map[pos.y] == map[i] && map[pos.x] == map[j])
			{
				cout << "��";
				continue;
			}
			if (map[i][j] == 1) cout << "��";
			if (map[i][j] == 0) cout << "��";
		}
		cout << endl;
	}
}