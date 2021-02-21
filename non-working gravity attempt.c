#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500

int main(int argc, char **argv) {

    SDL_bool quit = SDL_FALSE;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("Dungeoneer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *dot_surface = IMG_Load("dot.png");
    SDL_Texture *dot_texture = SDL_CreateTextureFromSurface(renderer, dot_surface);

    SDL_Rect dstrect = { 5, 5, 50, 50 };

    Uint64 start = SDL_GetPerformanceCounter();
    Uint64 frequency = SDL_GetPerformanceFrequency();

    while (!quit) {

        SDL_PollEvent(&event);

        Uint64 end = SDL_GetPerformanceCounter();

        if(((float)end - (float)start / frequency) == 0)
            dstrect.y += 1;

        SDL_RenderCopy(renderer, dot_texture, NULL, &dstrect);

        switch(event.type) {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button) {

                }
                break;
        }
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


    SDL_Quit();

    return 0;
}
