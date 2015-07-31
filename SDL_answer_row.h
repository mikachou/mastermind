#ifndef _SDL_ANSWER_ROW_H_
#define _SDL_ANSWER_ROW_H_

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
    int height;
    int width;
    int n_slots;
    int fillColor;
    int borderColor;
    int * baseColors;
} SDL_AnswerRow;

SDL_AnswerRow * SDL_AnswerRow_create(SDL_Renderer * renderer, int x1, int y1, int height, int n_slots, int fillColor, int borderColor, int * baseColors);
void SDL_AnswerRow_draw(SDL_AnswerRow * row);
void SDL_AnswerRow_destroy(SDL_AnswerRow * row);

#endif
