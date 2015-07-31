#ifndef _SDL_AREA_H_
#define _SDL_AREA_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "area.h"
#include "SDL_row.h"

typedef struct {
    Area * base;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Row ** rows;
    SDL_CombinationRow * codeRow;
    int x1;
    int y1;
    int x2;
    int y2;
    int width;
    int height;
    int color;
    int n_rows;
    int n_slots;
    int n_colors;
    int slotRadius;
    int distBtwSlotAndBorder;
    int * baseColors;
} SDL_Area;

SDL_Area * SDL_Area_create(SDL_Renderer * renderer, int x1, int y1, int n_rows, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors);
void SDL_Area_draw(SDL_Area * area);
void SDL_Area_destroy(SDL_Area * area);

#endif
