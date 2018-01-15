#include "stdafx.h"
#include "SpaceShip.h"

SpaceShip::SpaceShip(int x, int y) : hp(3), score(0), mIsAlive(true)
{
	mSymbol = char(24);
	point = std::make_unique<Point>(x, y);
	updateScore();
}


SpaceShip::~SpaceShip()
{
}

void SpaceShip::shoot()
{
	Bullet * tmp = new Bullet(point->x, point->y - 1, -1);
	mBullets.push_back(tmp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	Buffer::write(tmp->point, tmp->mSymbol);
}
std::vector<std::shared_ptr<Point>> SpaceShip::moveBullets()
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

void SpaceShip::deleteBullet(Bullet * bullet)
{
	for (int i = 0; i < mBullets.size(); i++) {
		if (mBullets[i] == bullet) {
			mBullets.erase(mBullets.begin() + i);
		}
	}
}

int SpaceShip::x()
{
	return point->x;
}

int SpaceShip::y()
{
	return point->y;
}

void SpaceShip::moveShip(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	Buffer::write(point, ' ');

	point->x += x;
	point->y += y;

	Buffer::write(point, mSymbol);
}

std::shared_ptr<Point> & SpaceShip::getPoint()
{
	return point;
}

void SpaceShip::addScore(int qwe)
{
	score += qwe;
	updateScore();
}

void SpaceShip::addHp(int qwe)
{
	hp += qwe;
	updateScore();
	if (hp <= 0)
		mIsAlive = false;
}

bool SpaceShip::isAlive()
{
	return mIsAlive;
}

void SpaceShip::updateScore()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Buffer::moveBuffer(0, 0);
	std::cout << "HP: " << hp << "\tScore: " << score;
}
