#include "background.h"
#include "../engine/logger.h"

Background::Background(Renderer* renderer, Input* input) : WorldEntity("Background", renderer, input)
{
	// comment
	this->texture = renderer->LoadTexture("content//background.png");
}


Background::~Background()
{
	Logger::Log("Background destructor");
}

void Background::Render() {
	renderer->RenderTexture(texture, 0, 0);
}

void Background::Update(const unsigned int ticks) {

}
