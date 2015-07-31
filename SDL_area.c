#include "SDL_area.h"

SDL_Area * SDL_Area_create(SDL_Renderer * renderer, int x1, int y1, int n_rows, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors)
{
    int i, rowHeight;
    SDL_Area * area;
    
    area = malloc(sizeof(SDL_Area));

    area->renderer = renderer;
    area->x1 = x1;
    area->y1 = y1;    
    area->n_rows = n_rows;
    area->n_slots = n_slots;
    area->n_colors = n_colors;
    
    area->base = Area_create(n_rows, n_slots, n_colors);
    
    area->slotRadius = slotRadius;
    area->distBtwSlotAndBorder = distBtwSlotAndBorder;
    
    area->rows = malloc(area->n_rows * sizeof(SDL_Row *));
    
    rowHeight = 2 * (slotRadius + distBtwSlotAndBorder);
    
    area->codeRow = SDL_CombinationRow_create(renderer, 0, 0, (n_slots + 2) * rowHeight, rowHeight, n_slots, n_colors, slotRadius, fillColor, borderColor, cursorColor, baseColors);
    
    for (i = 0; i < n_rows; i++) {
        *(area->rows + i) = SDL_Row_create(renderer, x1, y1 + (n_rows - i) * rowHeight, rowHeight, n_slots, n_colors, slotRadius, distBtwSlotAndBorder, fillColor, borderColor, cursorColor, baseColors);
    }
    
    area->width = (*(area->rows))->width;
    area->height = (*(area->rows))->height * (n_rows + 1);
    area->x2 = area->x1 + area->width;
    area->y2 = area->y1 + area->height;
    
    return area;
}

void SDL_Area_draw(SDL_Area * area)
{
    int i;
    
    SDL_CombinationRow_draw(area->codeRow);
    
    for (i = 0; i < area->n_rows; i++) {
        SDL_Row_draw(*(area->rows + i));
    }
}

void SDL_Area_destroy(SDL_Area * area)
{
    int i;
    for (i = 0; i < area->n_rows; i++) {
        SDL_Row_destroy(*(area->rows + i));
    }
    
    SDL_CombinationRow_destroy(area->codeRow);
    
    free(area->base);
    free(area);
}
