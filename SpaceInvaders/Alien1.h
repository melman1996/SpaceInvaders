#pragma once
#include "Alien.h"
#include "Buffer.h"
#include "Bullet.h"

class Alien1 : public Alien
{
private:
	std::vector<Bullet *> mBullets;
public:
	Alien1(int, int);
	~Alien1();

	void draw() override;
	void shoot() override;
	std::vector<std::shared_ptr<Point>> moveBullets() override;
	void deleteBullet(Bullet *);
};

