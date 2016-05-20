#include <SDL/SDL.h>
#include <stdint.h>
#include <stdlib.h> // atoi
#include <string.h> // strcmp
#include <iostream>

#define FPS 100
#define SCREEN_HEIGHT 1024
#define SCREEN_WIDTH 600

bool isInteger(char*);


uint16_t screenHeight, screenWidth;
uint8_t difficulty;

void getCommandLineArgs()


int main(int argc, char* args[]){


	std::cout <<"Pong:\n";





	// initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	// make the screen/main
	SDL_Surface* screen;

	// height and width could come from the command line
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE/*|SDL_FULLSCREEN*/);

	uint32_t frameStartTime;


	SDL_Rect rect;
	rect.x = 10;
	rect.y = 20;
	rect.h = 30;
	rect.w = 40;


	const uint32_t black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	const uint32_t white = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);

	// set screen background color to black
	SDL_FillRect(screen, &screen->clip_rect, black);




	struct arrowKeyVals {
		bool up, down, left, right;
	};
	arrowKeyVals arrows[2];

	arrows[0].up = false;
	arrows[0].down = false;
	arrows[0].left = false;
	arrows[0].right = false;
	arrows[1].up = false;
	arrows[1].down = false;
	arrows[1].left = false;
	arrows[1].right = false;




	// main loop
	for (uint32_t frameNumber;true;frameNumber++) {

		// get start time
		frameStartTime = SDL_GetTicks();


		SDL_Event event;



		while (SDL_PollEvent(&event))  {


			// event handling
			switch (event.type) {

			case SDL_QUIT:
				goto quit_program; // I might regret this...
				break;

			case SDL_KEYDOWN:
				// a key has been pressed
				switch (event.key.keysym.sym) {

				case SDLK_UP:
					arrows.up = true;
					break;

				case SDLK_DOWN:
					arrows.down = true;
					break;

				case SDLK_LEFT:
					arrows.left = true;
					break;

				case SDLK_RIGHT:
					arrows.right = true;
					break;

				case SDLK_q:
					goto quit_program;
					break;

				}
				break;

			case SDL_KEYUP:
				// a key has been pressed
				switch (event.key.keysym.sym) {

				case SDLK_UP:
					arrows.up = false;
					break;

				case SDLK_DOWN:
					arrows.down = false;
					break;

				case SDLK_LEFT:
					arrows.left = false;
					break;

				case SDLK_RIGHT:
					arrows.right = false;
					break;

				}
				break;
			}



		}







		if (arrows.up)
			rect.y--;
		if (arrows.down)
			rect.y++;
		if (arrows.left)
			rect.x--;
		if (arrows.right)
			rect.x ++;



		// set screen background color to black
		SDL_FillRect(screen, &screen->clip_rect, black);

		// add the rectangle to the render list
		SDL_FillRect(screen, &rect, white);

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
}




bool isInteger(char* str){
	if (!(*str == '0' || *str == '1' || *str == '2' || *str == '3'
			|| *str == '4' || *str == '5' || *str == '6' || *str == '7'
			|| *str == '8' || *str == '9'
	) || *str == '\0') return false;
	while (*str != '\0') {
		if (!(*str == '0' || *str == '1' || *str == '2' || *str == '3'
			|| *str == '4' || *str == '5' || *str == '6' || *str == '7'
			|| *str == '8' || *str == '9'
		)) return false;
		str++; // next char
	}
	return true;
}
