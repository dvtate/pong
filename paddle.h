#ifndef PADDLE_H
#define PADDLE_H

#include <stdint.h>

#include <SDL/SDL.h>

#include "ball.h"

extern uint8_t difficulty;
extern const uint16_t screenHeight;



class Paddle {
public:
	static const uint8_t paddleWidth = 20;
	SDL_Rect rect;
	Paddle(const uint16_t& x, const uint16_t& y){
		rect.x = x;
		rect.y = y;
		rect.h = 60;
		rect.w = paddleWidth;

	}
	Paddle(const uint16_t& _x, const uint16_t& _y, const uint16_t& paddleHeight){
		rect.x = _x;
		rect.y = _y;
		rect.h = paddleHeight;
		rect.w = paddleWidth;

	}
	~Paddle(){}

	SDL_Rect& getRect()
		{ return rect; }


	void moveUpDown(const int16_t& yChange){

		if (yChange == 0)
			return;

		if (yChange < 0) {
			if (rect.y + yChange < 0)
				return;
			else
				rect.y += yChange;
			return;
		}
		if (rect.y + yChange + rect.h > screenHeight)
			return;
		else
			rect.y += yChange;

	}

	void moveUpDown(bool up, bool down){

		int8_t change = 0;

		if (up)
			change -= 1;
		if (down)
			change += 1;

		moveUpDown(change);
	}

	bool isTouching(const Ball& ball){

	}
};

#endif
