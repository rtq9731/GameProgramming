#pragma once
class Missile
{
private:
	int x;
	int y;
public:
	void setMissile(int _x, int _y);
	void drawMissile();
	bool checkEnd();

	bool checkCollision(int _x, int _y);
};

