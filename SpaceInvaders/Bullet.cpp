#include "stdafx.h"
#include "Bullet.h"



Bullet::Bullet(int x, int y, int direction) : mDirection(direction)
{
	point = std::make_shared<Point>(x, y);
	mSymbol = char(248);
}


Bullet::~Bullet()
{
}

bool Bullet::moveBullet()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

	Buffer::write(point, ' ');
	point->y += mDirection;

	if ((point->y < 1 && mDirection == -1) || (point->y >= 25 && mDirection == 1)) {
		return true;
	} else if (Buffer::read(point) == mSymbol || Buffer::read(point) == ' '){
		Buffer::write(point, mSymbol);
		return false;
	} else {
		return true;
	}
}
