#pragma once
#include "Bullet.h"
#include "Buffer.h"
#include "Point.h"

class SpaceShip
{
private:
	std::shared_ptr<Point> point;
	std::vector<Bullet *> mBullets;
	int score, hp;
	char mSymbol;
	bool mIsAlive;
public:
	friend class GameInstance;

	SpaceShip(int, int);
	~SpaceShip();

	void shoot();
	std::vector<std::shared_ptr<Point>> moveBullets();
	void deleteBullet(Bullet *);
	int x();
	int y();
	void moveShip(int, int);

	std::shared_ptr<Point> & getPoint();
	void addScore(int);
	void addHp(int);
	bool isAlive();

	void updateScore();
};

