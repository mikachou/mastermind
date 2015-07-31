#ifndef _SDL_ROW_BUTTON_H_
#define _SDL_ROW_BUTTON_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

typedef struct {
    SDL_Renderer * renderer;
    int x1;
    int y1;
    int x2;
    int y2;
    int color;
    int width;
    int fillColor;
    int borderColor;
} SDL_RowButton;

SDL_RowButton * SDL_RowButton_create(SDL_Renderer * renderer, int x1, int y1, int width, int fillColor, int borderColor, int * baseColors);
void SDL_RowButton_draw(SDL_RowButton * button);
void SDL_RowButton_destroy(SDL_RowButton * button);

#endif
