#pragma once
#include "headers_WhatIneed.h"

class Player
{
private:
	Data::Position* pos;
	Data::Position* exit_XY;

	int moveCount;
public:
	Player();

	void ShowScreenFirst(Data::Position pos, int map[][12]);
	void ShowScreen(int map[][12]);
};

