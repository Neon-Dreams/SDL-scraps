#include <SDL.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500

int main() {

    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    SDL_Window *window = SDL_CreateWindow("Menu Bar", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Renderer *render[1];
    render[0] = SDL_CreateRenderer(window, -1, 0);
    render[1] = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(render[0], 105, 105, 105, 200);
	SDL_RenderClear(render[0]);
	SDL_RenderPresent(render[0]);

    while (!quit) {
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = SDL_TRUE;
                break;
            }
        }

    }

    return 0;
}
