#include "headers_WhatIneed.h"

void Data::getMaze(int arr[][12])
{
	memcpy(arr, this->mazeMap[mazeNum], 576);
	//for (int i = 0; i < 12; i++)
	//{
	//	for (int j = 0; j < 12; j++)
	//	{
	//		arr[i][j] = mazeMap[randNum][i][j];
	//	}
	//	cout << endl;
	//} 
}

void Data::refreshMaze()
{
	mazeNum = rand() % 5;
}