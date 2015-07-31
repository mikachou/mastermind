#ifndef _SDL_GAME_H_
#define _SDL_GAME_H_

#include <SDL2/SDL.h>
#include "game.h"
#include "SDL_area.h"

typedef struct {
    Game * base;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Area * area;
    int * baseColors;
} SDL_Game;

SDL_Game * SDL_Game_create(SDL_Renderer * renderer, int n_rows, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors);
void SDL_Game_destroy(SDL_Game * game);

#endif
