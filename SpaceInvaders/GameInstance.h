#pragma once

#include "SpaceShip.h"
#include "Alien1.h"



class GameInstance
{
private:
	int mWidth, mHeight;
	SpaceShip * mPlayer;

	std::vector<std::vector<std::shared_ptr<Alien>>> mAliens;
	std::vector<int> mDirections;
public:
	GameInstance(int, int);
	~GameInstance();

	void startGame();
	void generateAliens();
	void destroyAliens(std::vector<std::shared_ptr<Point>>);
	void makeAliensShoot();
	void destroyPlayer(std::vector<std::shared_ptr<Point>>);

	void movePlayer(int, int);
	void moveAliens();
};

