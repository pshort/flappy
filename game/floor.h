#ifndef FLOOR_H
#define FLOOR_H

#include "../engine/renderer.h"
#include "../engine/input.h"
#include "../engine/worldentity.h"

class Floor : public WorldEntity
{
public:
	Floor(Renderer* renderer, Input* input);
	virtual ~Floor();

	void Update(const unsigned int ticks);
	void Render();

private:
	int movement;
};

#endif
