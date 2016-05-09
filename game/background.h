#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL2/SDL.h>

#include "../engine/renderer.h"
#include "../engine/input.h"
#include "../engine/worldentity.h"

class Background : public WorldEntity
{
public:
	Background(Renderer* renderer, Input* input);
	virtual ~Background();

	void Update(const unsigned int ticks);
	void Render();
};

#endif

