#include "stdafx.h"
#include "Alien1.h"


Alien1::Alien1(int x = 0, int y = 0)
{
	point = std::make_shared<Point>(x, y);
	mSymbol = char(220);
}

Alien1::~Alien1()
{
}

void Alien1::draw()
{
	Buffer::write(point, mSymbol);
}

void Alien1::shoot()
{
	Bullet * tmp = new Bullet(point->x, point->y + 1, 1);
	mBullets.push_back(tmp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	Buffer::write(tmp->point, tmp->mSymbol);
}

std::vector<std::shared_ptr<Point>> Alien1::moveBullets()
{
	std::vector<std::shared_ptr<Point>> points;
	for (Bullet * bullet : mBullets) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		if (bullet->moveBullet()) {
			points.push_back(bullet->point);
			deleteBullet(bullet);
		}
	}
	return points;
}
void Alien1::deleteBullet(Bullet * bullet)
{
	for (int i = 0; i < mBullets.size(); i++) {
		if (mBullets[i] == bullet) {
			mBullets.erase(mBullets.begin() + i);
		}
	}
}