#ifndef PIPE_H
#define PIPE_H

#include <iostream>

#include "../engine/renderer.h"
#include "../engine/input.h"
#include "../engine/worldentity.h"
#include "../engine/aabb.h"
#include "score.h"

class Pipe : public WorldEntity
{
public:
	Pipe(Renderer* renderer, std::string name, Score* score, Input* input);
	virtual ~Pipe();

	void Render();
	void Update(const unsigned int ticks);

	AABB topPipe;
	AABB bottomPipe;

private:
	int gap;
	Score* score;

    bool scored;

};


#endif
