#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500

int main(int argc, char **argv) {

	SDL_bool quit = SDL_FALSE;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_Window* window = SDL_CreateWindow("Progressbar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 105, 105, 105, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect = { 100, 100, 100, 50 }; // the rectangle
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer); // copy to screen


	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;

			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT: 

						if ((event.button.x > rect.x && event.button.x < (rect.x + rect.w)) && (event.button.y > rect.y && event.button.y < (rect.y + rect.h))) {
							printf("Button Pressed\n");
						}
						break;
				}
				break;
			}
		}
		SDL_RenderPresent(renderer);
	}

	return 0;
}