#include "SDL_slot.h"

SDL_Slot * SDL_Slot_create(SDL_Renderer * renderer, SlotType type, int x, int y, int radius, int fillColor, int borderColor, int cursorColor, int * baseColors, int n_colors)
{
    SDL_Slot * slot;
    int size;
    
    slot = malloc(sizeof(SDL_Slot));
    
    slot->renderer = renderer;
    slot->x = x;
    slot->y = y;
    slot->radius = radius;
    slot->fillColor = fillColor;
    slot->borderColor = borderColor;
    slot->cursorColor = cursorColor;
    slot->cursorX1 = x - radius * 3 / 2;
    slot->cursorY1 = y - radius * 3 / 2;
    slot->cursorX2 = x + radius * 3 / 2;
    slot->cursorY2 = y + radius * 3 / 2;
    slot->baseColors = baseColors;
    
    slot->base = Slot_create(type, n_colors);
    
    return slot;
}

void SDL_Slot_draw(SDL_Slot * slot)
{
    if (slot->base->color == SLOT_COLOR_NONE) {
        filledCircleColor(slot->renderer, slot->x, slot->y, 2, slot->borderColor);
    } else {
        filledCircleColor(slot->renderer, slot->x, slot->y, slot->radius, *(slot->baseColors + slot->base->color));
        circleColor(slot->renderer, slot->x, slot->y, slot->radius, slot->borderColor);
    }
}

void SDL_Slot_cursorOn(SDL_Slot * slot)
{
    rectangleColor(slot->renderer, slot->cursorX1, slot->cursorY1, slot->cursorX2, slot->cursorY2, slot->cursorColor);
}

void SDL_Slot_cursorOff(SDL_Slot * slot)
{
    rectangleColor(slot->renderer, slot->cursorX1, slot->cursorY1, slot->cursorX2, slot->cursorY2, slot->fillColor);
}

void SDL_Slot_nextColor(SDL_Slot * slot)
{
    Slot_setNextCombinationColor(slot->base);
    
    SDL_Slot_draw(slot);
}

void SDL_Slot_previousColor(SDL_Slot * slot)
{
    Slot_setPreviousCombinationColor(slot->base);
    
    SDL_Slot_draw(slot);
}

void SDL_Slot_destroy(SDL_Slot * slot)
{
    Slot_destroy(slot->base);
    free(slot);
}
