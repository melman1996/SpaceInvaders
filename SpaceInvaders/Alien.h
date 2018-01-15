#pragma once
#include "stdafx.h"
#include "Point.h"
#include "Buffer.h"

class Alien
{
protected:
	std::shared_ptr<Point> point;
	char mSymbol;
public:
	void move(int, int);
	virtual void draw() = 0;
	virtual void shoot();
	virtual std::vector<std::shared_ptr<Point>> moveBullets();
	int x();
	std::shared_ptr<Point> & getPoint();
};

