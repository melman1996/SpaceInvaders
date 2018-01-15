#include "stdafx.h"
#include "GameInstance.h"
#include "Buffer.h"

GameInstance::GameInstance(int width = 100, int height = 100) : mWidth(width), mHeight(height)
{
	Buffer::setWindow(mWidth, mHeight);
}


GameInstance::~GameInstance()
{
}
void GameInstance::startGame()
{
	//generate aliens
	generateAliens();
	//generate and draw spaceship
	mPlayer = new SpaceShip(mWidth/2, mHeight - 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	Buffer::write(mPlayer->point, char(24));
	//game loop
	clock_t tShoot = clock();
	clock_t tMove = clock();
	clock_t tAliens = clock();
	clock_t tBullets = clock();
	while (mPlayer->isAlive()) {
		if (clock() - tMove >= 50) {
			if (GetAsyncKeyState(VK_LEFT)) movePlayer(-1, 0);
			if (GetAsyncKeyState(VK_RIGHT)) movePlayer(1, 0);
			tMove = clock();
		}
		if (clock() - tShoot >= 500) {
			mPlayer->shoot();
			tShoot = clock();
		}
		if (clock() - tAliens >= 1000) {
			moveAliens();
			makeAliensShoot();
			tAliens = clock();
		}
		if (clock() - tBullets >= 111) {
			destroyAliens(mPlayer->moveBullets());
			for (auto& aliens : mAliens) {
				for (auto& alien : aliens) {
					destroyPlayer(alien->moveBullets());
				}
			}
			tBullets = clock();
		}
	}
	system("cls");
	Buffer::moveBuffer(12, 20);
	std::cout << "GAME OVER ";
	system("pause");
}

void GameInstance::generateAliens()
{
	for (int i = 0; i < 10; i++) {
		std::vector<std::shared_ptr<Alien>> tmp;
		for (int j = 0; j < 30; j += 2) {
			tmp.push_back(std::make_shared<Alien1>(j + 2, i + 1));
		}
		mAliens.push_back(tmp);
		for (auto& alien : tmp) {
			alien->draw();
		}
		mDirections.push_back((i % 2) ? 1 : -1);
	}
}

void GameInstance::destroyAliens(std::vector<std::shared_ptr<Point>> points)
{
	for (auto& point : points) {
		for (int i = 0; i < mAliens.size(); i++) {
			for (int j = 0; j < mAliens[i].size(); j++) {
				if (*(mAliens[i][j]->getPoint()) == *point) {
					Buffer::write(point, ' ');
					mAliens[i].erase(mAliens[i].begin() + j);
					mPlayer->addScore(1);
				}
			}
		}
	}
}

void GameInstance::makeAliensShoot()
{
	for (int i = mAliens.size() - 1; i >= 0; i--) {
		if (mAliens[i].size() > 0) {
			for (auto& alien : mAliens[i]) {
				if (rand() % 100 < 10)
					alien->shoot();
			}
			break;
		}
	}
}

void GameInstance::destroyPlayer(std::vector<std::shared_ptr<Point>> points)
{
	for (auto& point : points) {
		if (*(mPlayer->getPoint()) == *point) {
			mPlayer->addHp(-1);
		}
	}
}

void GameInstance::movePlayer(int x, int y)
{
	if (mPlayer->x() + x >= mWidth - 1 || mPlayer->x() + x < 0) return;
	mPlayer->moveShip(x, 0);
}

void GameInstance::moveAliens()
{
	for (int i = 0; i < mAliens.size(); i++) {
		if (mAliens[i].size() > 0) {
			if (mDirections[i] == 1 && mAliens[i][mAliens[i].size() - 1]->x() >= mWidth - 1)
				mDirections[i] *= -1;
			else if (mDirections[i] == -1 && mAliens[i][0]->x() <= 0)
				mDirections[i] *= -1;
			for (auto& alien : mAliens[i]) {
				alien->move(mDirections[i], 0);
			}
		}
	}
}
