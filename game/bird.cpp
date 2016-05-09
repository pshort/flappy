#include "bird.h"
#include <iostream>
#include "../engine/logger.h"

Bird::Bird(Renderer* renderer, Input* input) : WorldEntity("Bird", renderer, input) {
	this->x = 50;
	this->y = 50;

	this->xv = 0;
	this->yv = 0.0f;

	this->texture = renderer->LoadTexture("content//flappy.png");

	bounds.w = 11;
	bounds.h = 12;

	isDead = false;

	drawOrder = 2;
}

Bird::~Bird() {
	Logger::Log("Bird Destructor");
}

void Bird::Update(const unsigned int ticks) {

    if(this->input->IsKeyDown(SDL_SCANCODE_SPACE)) {
        this->Flap();
    }

	y -= yv;

	yv -= 0.1f;

	if (yv <= -2.0f) {
		yv = -2.0f;
	}

	if (yv >= 2.0f) {
		yv = 2.0f;
	}

	rot = -yv * 30;

	bounds.x = x + 12;
	bounds.y = y + 9;

	if (bounds.y + bounds.h > 150){
		Die();
	}
}

void Bird::Render() {
	renderer->RenderTexture(texture, x, y, rot);
} 

void Bird::Flap() {
	if (!isDead)
		yv += 4.0f;
}

void Bird::Die() {
	isDead = true;
}

bool Bird::IsColliding(AABB other) {
	return bounds.IsColliding(&other);
}
