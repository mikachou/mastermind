#ifndef _SDL_ROW_H_
#define _SDL_ROW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "row.h"
#include "SDL_combination_row.h"
#include "SDL_answer_row.h"
#include "SDL_row_button.h"

typedef struct {
    Row * base;
    SDL_Renderer * renderer;
    SDL_CombinationRow * combination;
    SDL_AnswerRow * answer;
    //SDL_RowButton * button;
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
    int * baseColors;
} SDL_Row;

SDL_Row * SDL_Row_create(SDL_Renderer * renderer, int x1, int y1, int height, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors);
void SDL_Row_draw(SDL_Row * row);
void SDL_Row_destroy(SDL_Row * row);

#endif
