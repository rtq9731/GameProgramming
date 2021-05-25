#pragma once

struct Vector2
{
public:
	int x;
	int y;
};

class Missile
{
public:
	void set(int _y);
	void move();
	void draw();
	Vector2 getPos();

	bool checkEnd();

	Missile();
	~Missile();

private:
	int x;
	int y;

	Vector2 myPos;
	bool bMoveLeft;

};