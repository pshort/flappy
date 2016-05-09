#include "engine/game.h"
#include "game/flappygame.h"
#include <iostream>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main()
{
	auto game = new FlappyGame();

	game->Run();

	game->~FlappyGame();

	return 0;
}

