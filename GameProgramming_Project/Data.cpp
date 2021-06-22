#include "headers_WhatIneed.h"

void Data::getMaze(int arr[][12])
{
	memcpy(arr, this->mazeMap[mazeNum], 576);
}

void Data::refreshMaze()
{
	mazeNum = rand() % 5;
}