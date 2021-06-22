#include <iostream>
#include <fstream>
#include <string>
#include "Console.h"

using namespace std;

bool bStart;
int currentScore;
int highScore[5];

void saveFile()
{
	ofstream writeToFile("score.txt");

	for (int i = 0; i < 5; i++)
	{
		string temp = to_string(highScore[i]);

		if (i < 4)
		{
			temp += "\n";
		}

		writeToFile.write(temp.c_str(), temp.size());
	}

	writeToFile.close();
}

void loadFile()
{
	ifstream readFromFile("score.txt");

	if (!readFromFile.is_open())
	{
		saveFile();
		readFromFile.open("score.txt");
	}

	int i = 0;
	while (!readFromFile.eof())
	{
		string temp;
		getline(readFromFile, temp);

		highScore[i] = stoi(temp);
		i++;
	}

	readFromFile.close();
}

void setConsoleView()
{
	system("mode con:cols=35 lines=28");
	system("title Score Game");
}

void initData()
{
	for (int i = 0; i < 5; i++)
	{
		highScore[i] = 0;
	}

	loadFile();

	bStart = false;

	currentScore = 0;
}

void drawHighScore()
{
	gotoXY(6, 10);
	cout << "HIGH SCORE";

	for (int i = 0; i < 5; i++)
	{
		gotoXY(5, 12 + i * 2);
		cout << i + 1 << " : " << highScore[i];
	}

	gotoXY(3, 22);
	cout << "-----------------------";
}

void drawScore()
{
	gotoXY(5, 10);
	cout << "[a] ADD SCORE";

	gotoXY(3, 12);
	cout << "-----------------------";

	gotoXY(5, 14);
	cout << "SCORE : " << currentScore;
}

void drawMenu()
{
	gotoXY(3, 2);
	cout << "-----------------------"; // 23°³
	gotoXY(6, 3);
	cout << "SCORE GAME";
	gotoXY(3, 4);
	cout << "-----------------------";

	gotoXY(5, 6);
	bStart ? cout << "[x] EXIT GAME" : cout << "[s] START GAME";

	gotoXY(3, 8);
	cout << "-----------------------";

	bStart ? drawScore() : drawHighScore();
}

void saveScore(int score)
{
	for (int i = 0; i < 5; i++)
	{
		if (score >= highScore[i])
		{
			for (int j = 3; j >= i; j--)
			{
				highScore[j + 1] = highScore[j];
			}

			highScore[i] = score;
			break;
		}
	}
}

void checkKeyDown(int key)
{
	if (key == 's')
	{
		if (!bStart)
		{
			bStart = true;
		}
	}
	else if (key == 'x')
	{
		if (bStart)
		{
			saveScore(currentScore);
			saveFile();
			currentScore = 0;
			bStart = false;
		}
	}
	else if (key == 'a')
	{
		if (bStart)
		{
			currentScore++;
		}
	}
}


int main()
{
	setConsoleView();

	initData();

	while (true)
	{
		checkKeyDown(getKeyDown());

		drawMenu();

		gotoXY(0, 27);

		Sleep(100);
		clrscr();
	}

	return 0;
}