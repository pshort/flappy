#ifndef FLAPPYGAME_H
#define FLAPPYGAME_H

#include "../engine/game.h"
#include "../engine/input.h"

#include "bird.h"
#include "background.h"
#include "pipe.h"
#include "score.h"

class FlappyGame : public Game {
public:
	FlappyGame();

	bool			Initialize(void);
	void			Update(const unsigned int ticks);

private:
	Background* background;
	Bird* bird;

	int pipeAccumulator;
	int pipeCount;
    Score* score;

	int deathAcc;
};

#endif
