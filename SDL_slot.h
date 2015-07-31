#ifndef _SDL_SLOT_H_
#define _SDL_SLOT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "slot.h"

typedef struct {
    Slot * base;
    SDL_Renderer * renderer;
    int x;
    int y;
    int radius;
    int fillColor;
    int borderColor;
    int cursorColor;
    int cursorX1;
    int cursorY1;
    int cursorX2;
    int cursorY2;
    int * baseColors;
} SDL_Slot;

SDL_Slot * SDL_Slot_create(SDL_Renderer * renderer, SlotType type, int x, int y, int radius, int fillColor, int borderColor, int cursorColor, int * baseColors, int n_colors);
void SDL_Slot_draw(SDL_Slot * slot);
void SDL_Slot_cursorOn(SDL_Slot * slot);
void SDL_Slot_cursorOff(SDL_Slot * slot);
void SDL_Slot_nextColor(SDL_Slot * slot);
void SDL_Slot_previousColor(SDL_Slot * slot);
void SDL_Slot_destroy(SDL_Slot * slot);

#endif
