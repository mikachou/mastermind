#include "SDL_row_button.h"

SDL_RowButton * SDL_RowButton_create(SDL_Renderer * renderer, int x1, int y1, int width, int fillColor, int borderColor, int * baseColors)
{
    SDL_RowButton * button;
    
    button = malloc(sizeof(SDL_RowButton));
    
    button->renderer = renderer;
    button->x1 = x1;
    button->y1 = y1;
    button->x2 = x1 + width;
    button->y2 = y1 + width;
    button->width = width;
    button->fillColor = fillColor;
    button->borderColor = borderColor;
    
    return button;
}

void SDL_RowButton_draw(SDL_RowButton * button)
{
    boxColor(button->renderer, button->x1, button->y1, button->x2, button->y2, button->fillColor);
    rectangleColor(button->renderer, button->x1, button->y1, button->x2, button->y2, button->borderColor);
}

void SDL_RowButton_destroy(SDL_RowButton * button)
{
    free(button);
}
