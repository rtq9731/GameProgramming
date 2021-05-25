#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main();

void gotoXY(int x, int y);
int getKeyDown();
void setConsoleView();
void drawReadyGame();
bool readyGame();
void startGame();
void setWords();
void drawStartGame();

vector<string> pastWords;
vector<string> strWords;

int main()
{
	setConsoleView();

	while (true)
	{
		if (readyGame())
		{
			startGame();
		}
	}

	return (0);
}

void gotoXY(int x, int y)
{
	COORD cur;
	cur.X = x * 2;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

int getKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void setConsoleView()
{
	system("mode con:cols=50 lines20");
	system("WORD Game");
}

void drawReadyGame()
{
	system("cls");
	gotoXY(5, 2);
	cout << "======================" << endl;
	gotoXY(5, 3);
	cout << "====== WORD GAME =====" << endl;
	gotoXY(5, 4);
	cout << "======================" << endl;
	gotoXY(1, 8);
	cout << "==== 시작하려면 S를 누르십시오. ===";
}

bool readyGame()
{
	drawReadyGame();
	while (true)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 's')
		{
			return true;
		}
	}
	return false;
}

void startGame()
{
	srand((unsigned)time(NULL));

	setWords();

	while (true)
	{
		int num = rand() % strWords.size();
		string strOrigin = strWords[num];
		int originLen = strOrigin.length();
		 
		string strQuestion;
		for (int i = 0; i < originLen; i++)
		{
			strQuestion += "_";
		}

		while (true)
		{
			drawStartGame();

			gotoXY(5, 5);
			for (int i = 0; i < originLen; i++)
			{
				cout << strQuestion[i] << " ";
			}
			cout << endl;

			gotoXY(9, 12);
			string strInput;
			cin >> strInput;

			bool isinput = true;
			for (int i = 0; i < pastWords.size(); i++)
			{
				if (strInput == pastWords[i])
					isinput = false;
			}

			if (isinput)
			{
				pastWords.push_back(strInput);
			}
			else
			{
				isinput = true;
			}

			if (strInput.length() == 1)
			{
				for (int i = 0; i < originLen; i++)
				{
					if (strOrigin[i] == strInput[0])
					{
						strQuestion[i] = strInput[0];
					}
				}
			}
			else if (strInput.length() > 1)
			{
				if (strOrigin == strInput)
				{
					pastWords.clear();
					break;
				}
			}

		}
	}
}

void drawStartGame()
{
	system("cls");

	gotoXY(5, 8);
	cout << "past = ";

	for (int i = 0; i < (int)pastWords.size(); i++)
	{
		cout << pastWords[i] << " ";
	}

	gotoXY(5, 12);
	cout << "input : ";
}


void setWords()
{
	string str[4] = { "apple", "banana", "code", "program" };

	ifstream readFromFile("words.txt");

	if (!readFromFile.is_open())
	{
		ofstream writeToFile("words.txt");

		for (int i = 0; i < 4; i++)
		{
			string temp = str[i];
			if (i < 3)
			{
				temp += "\n";
			}
			writeToFile.write(temp.c_str(), temp.size());
			strWords.push_back(str[i]);
		}

		writeToFile.close();
	}
	else
	{
		while (!readFromFile.eof())
		{
			string temp;
			getline(readFromFile, temp);
			strWords.push_back(temp);
		}

		readFromFile.close();
	}

}
