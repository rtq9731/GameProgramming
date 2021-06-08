#pragma once
#include "headers_WhatIneed.h"
#include <stack>

class Player
{
private:
	Data::Position* pos;
	Data::Position* exit_XY;

	float speed;
	int coin;
	int moveCount;
public:
	int currentMap[12][12]; //실시간으로 데이터가 저장 될 맵.
	int backgroundMap[12][12];

	Player();

	void SetPosition(int x, int y);
	void MoveToExit();
	void ShowScreenFirst(Data::Position pos, int map[][12]);
	void ShowScreen(int map[][12]);
};

