#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
public:
	SDL_Rect rect;
	uint16_t x, y;
	Paddle(uint16_t _x, uint16_t _y):
		x(_x), y(_y)
	{
		rect.x = x;
		rect.y = y;
		rect.h = 60;
		rect.w = 20;

	}
	Paddle(uint16_t _x, uint16_t _y, uint16_t paddleHeight):
		x(_x), y(_y)
	{
		rect.x = x;
		rect.y = y;
		rect.h = paddleHeight;
		rect.w = 20;

	}
	~Paddle(){}

	SDL_Rect& getRect()
		{ return rect; }

	void translate(uint32_t
};


#endif
