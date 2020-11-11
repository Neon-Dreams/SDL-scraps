void SDL_CreateProgressbar(SDL_Renderer *renderer, SDL_Rect rect, Uint32 width, Uint32 height) {

    SDL_Rect outline_rect;
    outline_rect.h = height;
    outline_rect.w = width;
    outline_rect.x = rect.x;
    outline_rect.y = rect.y;

    SDL_Rect bar_rect;
    bar_rect.h = rect.h-2;
    bar_rect.w = rect.w-2;
    bar_rect.x = rect.x+1;
    bar_rect.y = rect.y+1;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &outline_rect);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
    SDL_RenderFillRect(renderer,&bar_rect);
}
