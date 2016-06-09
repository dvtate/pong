#include <SDL/SDL.h>
#include <stdint.h>
#include <stdlib.h> // atoi
#include <string.h> // strcmp
#include <iostream>

#define FPS 200000000000000000


const uint16_t screenHeight = 1080, screenWidth = 1920;


#include "paddle.h"
#include "ball.h"


uint8_t difficulty = 2;




int main(int argc, char* args[]){



	// initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// make the screen/main
	SDL_Surface* screen;

	// height and width could come from the command line
	screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE|SDL_FULLSCREEN);



	const uint32_t black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	const uint32_t white = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);

	// set screen background color to black
	SDL_FillRect(screen, &screen->clip_rect, black);




	struct arrowKeyVals {
		bool up, down;
	};
	arrowKeyVals arrows[2];

	arrows[0].up = false;
	arrows[0].down = false;

	arrows[1].up = false;
	arrows[1].down = false;



	Paddle player1(10, 10, 500 / difficulty),
		player2(screenWidth - Paddle::paddleWidth - 10, 10, 500 / difficulty);

	Ball ball(screenWidth / 2, screenHeight / 2);

	// main loop
	for (uint32_t frameNumber;true;frameNumber++) {

		// get start time
		uint32_t frameStartTime = SDL_GetTicks();


		SDL_Event event;



		while (SDL_PollEvent(&event)) {


			// event handling
			switch (event.type) {

			case SDL_QUIT:
				goto quit_program; // I might regret this...
				break;

			case SDL_KEYDOWN:
				// a key has been pressed
				switch (event.key.keysym.sym) {

				// player1
				case SDLK_w:
					arrows[0].up = true;
					break;
				case SDLK_s:
					arrows[0].down = true;
					break;

				// player2
				case SDLK_UP:
					arrows[1].up = true;
					break;
				case SDLK_DOWN:
					arrows[1].down = true;
					break;


				// exit
				case SDLK_q: case SDLK_ESCAPE:
					// for those mad that I'm using a goto...
					// remember that a goto gets translated to `jmp`
					goto quit_program;
					break;

				}
				break;

			case SDL_KEYUP:
				// a key has been pressed
				switch (event.key.keysym.sym) {

				// player1
				case SDLK_w:
					arrows[0].up = false;
					break;
				case SDLK_s:
					arrows[0].down = false;
					break;

				// player2
				case SDLK_UP:
					arrows[1].up = false;
					break;
				case SDLK_DOWN:
					arrows[1].down = false;
					break;

				}
				break;
			}
		}

		player1.moveUpDown(arrows[0].up, arrows[0].down);
		player2.moveUpDown(arrows[1].up, arrows[1].down);


		// set screen background color to black
		SDL_FillRect(screen, &screen->clip_rect, black);

		// add paddles to render list
		SDL_FillRect(screen, &player1.rect, white);
		SDL_FillRect(screen, &player2.rect, white);

		// add ball to render list
		SDL_FillRect(screen, &ball.rect, white);

		// render
		SDL_Flip(screen);

		// finish the frame...
		if (1000 / FPS > SDL_GetTicks() - frameStartTime)
			SDL_Delay(1000 / FPS  -  (SDL_GetTicks() - frameStartTime));

	}






// the program has been closed
quit_program:
	SDL_FreeSurface(screen);
	SDL_Quit();




	return 0;


} // main

