#include "flappygame.h"
#include <string>
#include <sstream>

#include "floor.h"
#include "../engine/logger.h"

FlappyGame::FlappyGame() : Game("Crappy Bird 2.0", 320, 200) {

}

bool FlappyGame::Initialize(void) {
	renderer->SetZoom(3);
	background = new Background(renderer, input);
	entities.push_back(background);
    score = new Score(renderer, input);
    entities.push_back(score);

	bird = new Bird(renderer, input);
	entities.push_back(bird);

	entities.push_back(new Floor(renderer, input));
    
    renderer->LoadFont("baseFont", "content//OpenSans-Regular.ttf", 12);

	deathAcc = 1000;
	pipeAccumulator = 3000;

	fpsCount = 0;
    pipeCount = 0;
	return true;
}


void FlappyGame::Update(const unsigned int ticks) {

	pipeAccumulator -= ticks;

	if (pipeAccumulator <= 0) {

		std::ostringstream oss;
		oss << "Pipe" << pipeCount++;
		entities.push_back(new Pipe(renderer, oss.str(), score, input));
		pipeAccumulator = 1500;
	}

	auto i = entities.begin();

	if (!bird->isDead) {
		while (i != entities.end()) {
			(*i)->Update(ticks);

			if ((*i)->readyForCollection) {
				delete (*i);
				entities.erase(i++);
				Logger::Log("Killing a pipe");
			}
			else {
				++i;
			}
		}

		i = entities.begin();

		while (i != entities.end()) {
			Pipe* p = dynamic_cast<Pipe*>((*i));
			if (p != nullptr) {
				if (bird->IsColliding(p->topPipe) || bird->IsColliding(p->bottomPipe)) {
					bird->Die();
				}
			}
			++i;
		}
	}
	else {
		deathAcc -= ticks;

		if (deathAcc <= 0) {
			Shutdown();
			Initialize();
		}
	}
}


