#include <SDL.h>
#include <SDL_image.h>


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

	SDL_Surface* surface_progressbar_border = IMG_Load("assets/progressbar_border.png");
	SDL_Texture* progressbar_border = SDL_CreateTextureFromSurface(renderer, surface_progressbar_border);

	SDL_Surface* surface_progressbar_loader = IMG_Load("assets/progressbar_loader.png");
	SDL_Texture* progressbar_loader = SDL_CreateTextureFromSurface(renderer, surface_progressbar_loader);

	SDL_Rect dstrect = { 5, 5, 300, 100 };
	SDL_Rect dstrect_s = { dstrect.x, dstrect.y, 0, 100 };

	while (!quit) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				quit = SDL_TRUE;
		}

		SDL_Delay(500);
		dstrect_s.w += 10;

		if (dstrect_s.w > 299)
			dstrect_s.w = 300;

		SDL_RenderCopy(renderer, progressbar_loader, NULL, &dstrect_s);
		SDL_RenderCopy(renderer, progressbar_border, NULL, &dstrect);
		SDL_RenderPresent(renderer);

	}

	return 0;
}