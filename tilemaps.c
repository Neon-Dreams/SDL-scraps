#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500

#define PADDING_X 50
#define PADDING_Y 50

#define IMG_SIZE 50

#define MAP_WIDTH 4
#define MAP_HEIGHT 4

int map[5][5] = {{1, 1, 0, 0, 1}, {1, 1, 1, 0, 1}, {0, 0, 1, 1, 1}, {0, 1, 1, 0, 0}, {0, 1, 0, 0, 0}};


int main(int argc, char **argv) {

    SDL_bool quit = SDL_FALSE;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window * window = SDL_CreateWindow("Dungeoneer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * image = IMG_Load("wall.png");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_Rect display_map = {0, 0, IMG_SIZE, IMG_SIZE};

    while (!quit) {


        for (int count_y = 0; count_y < MAP_HEIGHT; count_y++) {
            for (int count_x = 0; count_x < MAP_WIDTH; count_x++) {

                switch(map[count_y][count_x]) {
                    case 1:
                        display_rect.y = PADDING_Y + IMG_SIZE * count_y;
                        display_rect.x = PADDING_Y + IMG_SIZE * count_x;
                        SDL_RenderCopy(renderer, texture, NULL, &display_rect);
                        break;
                }
            }
        }

        SDL_WaitEvent(&event);

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
