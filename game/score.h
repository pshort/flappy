#ifndef SCORE_H
#define SCORE_H

#include <sstream>
#include <string>

#include "../engine/worldentity.h"

class Score : public WorldEntity {

public:

	Score(Renderer* renderer, Input* input) : WorldEntity("score", renderer, input) {
        this->drawOrder = 4000;
        this->score = 0;
    };

	virtual ~Score() {};

    void AddScore() {
        this->score += 1;
    };

	void Update(const unsigned int ticks) {
    };

	void Render() {
		std::ostringstream oss;
		oss << "Score : " << score;
        this->renderer->RenderText("baseFont", oss.str(), 10, 10, 255, 255, 255);
    };

private:
    int score = 0;
};

#endif
