#ifndef _SDL_COMBINATION_ROW_H_
#define _SDL_COMBINATION_ROW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "row.h"
#include "SDL_slot.h"

typedef struct {
    Row * base;
    SDL_Renderer * renderer;
    SDL_Slot ** slots;
    int x1;
    int y1;
    int x2;
    int y2;
    int width;
    int height;
    int color;
    int n_slots;
    int n_colors;
    int slotRadius;
    int distBtwSlotAndBorder;
    int fillColor;
    int borderColor;
    int cursorCurrentPos;
    int * baseColors;
} SDL_CombinationRow;

SDL_CombinationRow * SDL_CombinationRow_create(SDL_Renderer * renderer, int x1, int y1, int width, int height, int n_slots, int n_colors, int slotRadius, int fillColor, int borderColor, int cursorColor, int * baseColors);
void SDL_CombinationRow_draw(SDL_CombinationRow * row);
void SDL_CombinationRow_moveCursorLeft(SDL_CombinationRow * row);
void SDL_CombinationRow_moveCursorRight(SDL_CombinationRow * row);
void SDL_CombinationRow_destroy(SDL_CombinationRow * row);

#endif
