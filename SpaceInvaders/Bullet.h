#pragma once
#include "Buffer.h"
#include "Point.h"

class Bullet
{
private:
	std::shared_ptr<Point> point;
	int mDirection;
	char mSymbol;
public:
	Bullet(int, int, int);
	~Bullet();

	bool moveBullet();
	
	friend class SpaceShip;
	friend class Alien1;
};

