#include "pipe.h"

#include <sstream>
#include <stdlib.h>

#include "../engine/logger.h"

Pipe::Pipe(Renderer* renderer, std::string name, Score* score, Input* input) : WorldEntity(name, renderer, input) {
	texture = renderer->LoadTexture("content//pipes.png");
	x = 320;
	y = std::rand() % 80 + 20;

	this->score = score;
    this->scored = false;

	gap = 45;

	topPipe.x = x;
	topPipe.y = 0;
	topPipe.h = y;
	topPipe.w = 32;

	bottomPipe.x = x;
	bottomPipe.y = y + gap;
	bottomPipe.h = 200 - (y + gap);
	bottomPipe.w = 32;
}

Pipe::~Pipe() {
	std::ostringstream oss;
	oss << "Destructor for " << name;
	Logger::Log(oss.str());
}

void Pipe::Render() {
	SDL_Rect src;
	SDL_Rect dest;

	src.w = 32;
	src.h = 32;
	src.x = 0;
	src.y = 64 + 32; // top pipe top

	dest.x = x;
	dest.y = y - 32;
	dest.w = 32;
	dest.h = 32;

	renderer->RenderTexture(texture, &src, &dest);

	for (int i = 1; i < 6; i++)
	{
		dest.y = y - (32 + (i * 32));
		src.y = 32; // pipe
		renderer->RenderTexture(texture, &src, &dest);
	}

	src.y = 0; // bottom top of pipe
	dest.y = y + gap;
	renderer->RenderTexture(texture, &src, &dest);

	for (int i = 1; i < 6; i++)
	{
		dest.y = y + (gap + (i * 32));
		src.y = 32; // pipe
		renderer->RenderTexture(texture, &src, &dest);
	}

}

void Pipe::Update(const unsigned int ticks) {
	x -= 1.0f;

	topPipe.x = x;
	bottomPipe.x = x;

	if (x < 50 && !scored) {
        this->scored = true;
        this->score->AddScore();
	}

	if (x < -32) {
		readyForCollection = true;
	}
}
