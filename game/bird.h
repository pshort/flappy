#ifndef BIRD_H
#define BIRD_H

#include "../engine/renderer.h"
#include "../engine/input.h"
#include "../engine/worldentity.h"
#include "../engine/aabb.h"

class Bird : public WorldEntity
{
public:
	Bird(Renderer* renderer, Input* input);
	virtual ~Bird();

	void Update(const unsigned int ticks);
	void Render();

	void Flap();
	void Die();

	bool IsColliding(AABB other);

	bool isDead;

private:
	float rot;
	

	AABB bounds;
};

#endif
