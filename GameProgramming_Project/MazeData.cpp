#include "MazeData.h"

void MazeData::getMaze(int arr[][12])
{
	int randNum;
	randNum = rand() % 5;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			arr[i][j] = mazeMap[randNum][i][j];
		}
		cout << endl;
	} 
}