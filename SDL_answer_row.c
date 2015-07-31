#include "SDL_answer_row.h"

SDL_AnswerRow * SDL_AnswerRow_create(SDL_Renderer * renderer, int x1, int y1, int height, int n_slots, int fillColor, int borderColor, int * baseColors)
{
    int i, x, y, n_cols;
    SDL_AnswerRow * row;
    
    row = malloc(sizeof(SDL_AnswerRow));
    
    n_cols = (int) ceil((float) n_slots / 2.0);
    row->renderer = renderer;
    row->x1 = x1;
    row->y1 = y1;
    row->height = height;
    row->width = n_cols / 2 * height;
    row->n_slots = n_slots;
    row->fillColor = fillColor;
    row->borderColor = borderColor;
    row->x2 = x1 + row->width;
    row->y2 = y1 + row->height;
    
    row->slots = malloc(n_slots * sizeof(SDL_Slot *));

    for (i = 0; i < n_slots; i++) {
        y = y1 + height * (i >= n_cols ? 3 : 1) / 4;
        
        x = x1 + (2 * (i % n_cols) + 1) * height / 4;

        *(row->slots + i) = SDL_Slot_create(renderer, answer, x, y, height / 8, fillColor, borderColor, SLOT_COLOR_NONE, baseColors, 2);
    }
    
    return row;
}

void SDL_AnswerRow_draw(SDL_AnswerRow * row)
{
    int i;
    
    boxColor(row->renderer, row->x1, row->y1, row->x2, row->y2, row->fillColor);
    rectangleColor(row->renderer, row->x1, row->y1, row->x2, row->y2, row->borderColor);
    
    for (i = 0; i < row->n_slots; i++) {
        SDL_Slot_draw(*(row->slots + i));
    }
}

void SDL_AnswerRow_destroy(SDL_AnswerRow * row)
{
    free(row);
}
