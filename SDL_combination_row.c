#include "SDL_combination_row.h"

SDL_CombinationRow * SDL_CombinationRow_create(SDL_Renderer * renderer, int x1, int y1, int width, int height, int n_slots, int n_colors, int slotRadius, int fillColor, int borderColor, int cursorColor, int * baseColors)
{
    int i;
    SDL_CombinationRow * row;
    
    row = malloc(sizeof(SDL_CombinationRow));
    
    row->renderer = renderer;
    row->x1 = x1;
    row->y1 = y1;
    row->width = width;
    row->height = height;
    row->n_slots = n_slots;
    row->n_colors = n_colors;
    row->slotRadius = slotRadius;
    row->fillColor = fillColor;
    row->borderColor = borderColor;
    row->x2 = x1 + width;
    row->y2 = y1 + height;
    
    row->slots = malloc(n_slots * sizeof(SDL_Slot *));
    for (i = 0; i < n_slots; i++) {
        *(row->slots + i) = SDL_Slot_create(renderer, combination, x1 + (2 * i + 1) * height / 2, y1 + height / 2, slotRadius, fillColor, borderColor, cursorColor, baseColors, n_colors);
    }
    
    return row;
}

void SDL_CombinationRow_draw(SDL_CombinationRow * row)
{
    int i;
    
    boxColor(row->renderer, row->x1, row->y1, row->x2, row->y2, row->fillColor);
    rectangleColor(row->renderer, row->x1, row->y1, row->x2, row->y2, row->borderColor);
    
    for (i = 0; i < row->n_slots; i++) {
        SDL_Slot_draw(*(row->slots + i));
    }
}

void SDL_CombinationRow_moveCursorLeft(SDL_CombinationRow * row)
{
    SDL_Slot_cursorOff(*(row->slots + row->cursorCurrentPos));
    
    if (row->cursorCurrentPos == 0) {
        row->cursorCurrentPos = row->n_slots - 1;
    } else {
        row->cursorCurrentPos--;
    }
    
    SDL_Slot_cursorOn(*(row->slots + row->cursorCurrentPos));
}

void SDL_CombinationRow_moveCursorRight(SDL_CombinationRow * row)
{
    SDL_Slot_cursorOff(*(row->slots + row->cursorCurrentPos));
    
    if (row->cursorCurrentPos == row->n_slots - 1) {
        row->cursorCurrentPos = 0;
    } else {
        row->cursorCurrentPos++;
    }
    
    SDL_Slot_cursorOn(*(row->slots + row->cursorCurrentPos));
}

void SDL_CombinationRow_destroy(SDL_CombinationRow * row)
{
    int i;
    
    for (i = 0; i < row->n_slots; i++) {
        SDL_Slot_destroy(*(row->slots + i));
    }
    
    free(row);
}
