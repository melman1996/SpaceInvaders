#include "stdafx.h"
#include "Alien.h"

void Alien::shoot()
{
}

std::vector<std::shared_ptr<Point>> Alien::moveBullets()
{
	return {};
}

int Alien::x()
{
	return point->x;
}

void Alien::move(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Buffer::write(point, ' ');

	point->x += x;
	point->y += y;

	Buffer::write(point, mSymbol);
}

std::shared_ptr<Point> & Alien::getPoint()
{
	return point;
}
