
#include "floor.h"
#include "../engine/logger.h"

Floor::Floor(Renderer* renderer, Input* input) : WorldEntity("Floor", renderer, input) {
	texture = renderer->LoadTexture("content//floor.png");
	drawOrder = 1;
	movement = 0;
}


Floor::~Floor() {
	Logger::Log("Destructor called for Floor");
}

void Floor::Render() {

	for (int i = 0; i < 19; i++) {
		renderer->RenderTexture(texture, (i*18) + movement, 150);
	}
	
}

void Floor::Update(const unsigned int ticks) {
	movement--;
	if (movement == -18) {
		movement = 0;
	}
}
