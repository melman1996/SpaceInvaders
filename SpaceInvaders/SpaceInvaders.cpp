// SpaceInvaders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

#include "GameInstance.h"

using namespace std;

int main()
{
	srand(time(NULL));
	GameInstance * game = new GameInstance(50, 25);
	game->startGame();
    return 0;
}

