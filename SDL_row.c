#include "SDL_row.h"

SDL_Row * SDL_Row_create(SDL_Renderer * renderer, int x1, int y1, int height, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors)
{
    SDL_Row * row;
    
    row = malloc(sizeof(SDL_Row));
    
    row->x1 = x1;
    row->y1 = y1;
    row->height = height;
    row->renderer = renderer;
    row->n_slots = n_slots;
    row->n_colors = n_colors;
    row->slotRadius = slotRadius;
    row->distBtwSlotAndBorder = distBtwSlotAndBorder;
    row->fillColor = fillColor;
    row->borderColor = borderColor;
    //row->button = SDL_RowButton_create(renderer, row->x1, row->y1, row->height, fillColor, borderColor);
    //row->combination = SDL_CombinationRow_create(renderer, row->button->x2, row->y1, n_slots * row->height, row->height, n_slots, n_colors, slotRadius, fillColor, borderColor);
    row->combination = SDL_CombinationRow_create(renderer, row->x1, row->y1, n_slots * row->height, row->height, n_slots, n_colors, slotRadius, fillColor, borderColor, cursorColor, baseColors);
    row->answer = SDL_AnswerRow_create(renderer, row->combination->x2, y1, height, n_slots, fillColor, borderColor, baseColors);
    //row->width = row->button->width + row->combination->width + row->answer->width;
    row->width = row->combination->width + row->answer->width;
    
    return row;
}


void SDL_Row_draw(SDL_Row * row)
{
    //SDL_RowButton_draw(row->button);
    SDL_CombinationRow_draw(row->combination);
    SDL_AnswerRow_draw(row->answer);
}

void SDL_Row_destroy(SDL_Row * row)
{
    //SDL_RowButton_destroy(row->button);
    SDL_CombinationRow_destroy(row->combination);
    SDL_AnswerRow_destroy(row->answer);    
    
    free(row);
}
