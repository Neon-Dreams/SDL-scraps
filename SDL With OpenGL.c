#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char **argv) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window* window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    SDL_Event event;
    SDL_bool quit = SDL_FALSE;

    while(!quit) {
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


        SDL_GL_SwapWindow(window);
    }


    SDL_GL_DeleteContext(context);
    SDL_Quit();
    return 0;
}
