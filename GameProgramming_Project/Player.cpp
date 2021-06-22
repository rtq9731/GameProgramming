#include "headers_WhatIneed.h"

Player::Player()
{
	this->pos = new Data::Position();
	this->exit_XY = new Data::Position();
	this->moveCount = 0;
	this->coin = 0;
	this->speed = 1;
}

void Player::SetPosition(int x, int y)
{
	this->pos->x = x;
	this->pos->y = y;
}

void Player::ShowScreenFirst(Data::Position pos, int map[][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 3)
			{
				this->exit_XY->x = j;
				this->exit_XY->y = i;
				setTextColor(2);
				cout << "��";
				setTextColor(15);
			}
			if (map[pos.y] == map[i] && map[pos.x] == map[j])
			{
				setTextColor(3);
				cout << "��";
				setTextColor(15);
				continue;
			}
			if (map[i][j] == 1)
			{
				setTextColor(7);
				cout << "��";
				setTextColor(15);
			}
			if (map[i][j] == 0)
			{
				setTextColor(8);
				cout << "��";
				setTextColor(15);
			}
		}
		cout << endl;
	}
}

void Player::ShowScreen(int map[][12])
{
	system("cls");
	gotoXY(25, 3);
	cout << "���� ��ǥ�� " << pos->x << " , " << pos->y;
	gotoXY(60, 3);
	cout << "���� �ӵ� : " << speed;
	gotoXY(25, 5);
	cout << "������ Ƚ���� " << moveCount << endl;
	gotoXY(25, 7);
	cout << "�ⱸ�� ��ǥ�� " << exit_XY->x << ", " << exit_XY->y << endl;
	gotoXY(25, 9);
	cout << "�����Ϸ��� Q�� �Է����ּ���";
	gotoXY(60, 9);
	cout << "�ӵ��� ���̷��� z Ű, ���߷��� x Ű�� �����ּ���";

	gotoXY(0, 1);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 3)
			{
				setTextColor(2);
				cout << "��";
				setTextColor(15);
			}
			else if (map[pos->y] == map[i] && map[pos->x] == map[j])
			{
				setTextColor(3);
				cout << "��";
				setTextColor(15);
				continue;
			}
			else if (map[i][j] == 1 || map[i][j] == 0)
			{
				if (map[i][j] == 1)
				{
					setTextColor(7);
					cout << "��";
					setTextColor(15);
				}
				if (map[i][j] == 0)
				{
					setTextColor(8);
					cout << "��";
					setTextColor(15);
				}
			}
			else
			{
				setTextColor(7);
				cout << "��";
				setTextColor(15);
			}
		}
		cout << endl;
	}
}

void Player::MoveToExit()
{
	stack<Data::Position> trace;
	trace.push(*pos); 
	Data::Position dir;
	char input;
	while (!trace.empty())
	{
		input = getKeyDown();
		input = tolower(input);

		//if (input == 0xE0)
		//{
		//	if (_getch() == 72) // ���� ȭ��ǥ
		//	{
		//		if (speed == 1.5f)
		//			continue;

		//		speed += 0.1f;
		//	}
		//	else if (_getch() == 80) // �Ʒ��� ȭ��ǥ
		//	{
		//		if (speed == 0.5f)
		//			continue;

		//		speed -= 0.1f;
		//	}
		//}

		if (input == 'q')
		{
			exit(0);
		}
		else if (input == 'z')
		{
			if (speed >= 1.5f)
				speed = 1.4f;

			speed += 0.1f;
		}
		else if (input == 'x')
		{
			if (speed <= 0.5f)
				speed = 0.6f;

			speed -= 0.1f;
		}

		Sleep(100 / speed);
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				if (currentMap[this->pos->y + 1][this->pos->x + 0] == 1)
					continue;

				currentMap[pos->y][pos->x] = 1;

				pos->y = pos->y + 1;
				pos->x = pos->x + 0;
				moveCount++;
				trace.push(*pos);
				ShowScreen(backgroundMap);
				break;
			}
			else if (i == 1)
			{
				if (currentMap[pos->y - 1][pos->x + 0] == 1)
					continue;

				currentMap[pos->y][pos->x] = 1;

				pos->y = pos->y - 1;
				pos->x = pos->x + 0;
				moveCount++;
				trace.push(*pos);
				ShowScreen(backgroundMap);
				break;
			}
			else if (i == 2)
			{
				if (currentMap[pos->y + 0][pos->x + 1] == 1)
					continue;

				currentMap[pos->y][pos->x] = 1;

				pos->y = pos->y + 0;
				pos->x = pos->x + 1;
				moveCount++;
				trace.push(*pos);
				ShowScreen(backgroundMap);
				break;
			}
			else if (i == 3)
			{
				if (currentMap[pos->y + 0][pos->x - 1] == 1)
					continue;

				currentMap[pos->y][pos->x] = 1;

				pos->y = pos->y + 0;
				pos->x = pos->x - 1;
				moveCount++;
				trace.push(*pos);
				ShowScreen(backgroundMap);
				break;
			}
			else
			{
				if (trace.top().x == 1 && trace.top().y == 1)
				{
					cout << "�̷��� �ⱸ�� ã�µ� �����Ͽ����ϴ�." << endl;
					return;
				}

				trace.pop();
				currentMap[pos->y][pos->x] = 1;
				pos->y = trace.top().y;
				pos->x = trace.top().x;
				moveCount++;
				ShowScreen(backgroundMap);
				break;
			}
		}

		if (pos->x == exit_XY->x && pos->y == exit_XY->y)
		{
			clrscr();
			ShowScreen(backgroundMap);
			cout << "�̷��� �ⱸ�� ã�ҽ��ϴ�!" << endl;

			for (int i = 0; i < trace.size(); i++)
			{
				trace.pop();
			}

			cout << "���� �̷θ� �����մϴ�!" << endl;
			return;
		}

	}
}