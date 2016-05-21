#ifndef BALL_H
#define BALL_H

#include <stdint.h>

#include <SDL/SDL.h>
#include "paddle.h"

extern uint8_t difficulty;
extern const uint16_t screenHeight, screenWidth;



class Ball {
public:
	SDL_Rect rect;
 	Ball(uint16_t x, uint16_t y){
		rect.x = x;
		rect.y = y;
	  	rect.h = 8;
	  	rect.w = 8;
	}









};



#endif
