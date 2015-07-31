#include "slot.h"

Slot * Slot_create(SlotType type, int n_colors)
{
    Slot * slot;
    
    slot = malloc(sizeof(Slot));
    
    slot->type = type;
    slot->n_colors = n_colors;
    
    slot->color = SLOT_COLOR_NONE;
    
    return slot;
}

void Slot_setNextCombinationColor(Slot * slot)
{
    int i;
    
    if (slot->color == SLOT_COLOR_NONE 
        || slot->color == slot->n_colors - 1) {
        slot->color = 0;
    } else {
        slot->color++;
    }
}

void Slot_setPreviousCombinationColor(Slot * slot)
{
    int i;
    
    if (slot->color == SLOT_COLOR_NONE 
        || slot->color == 0) {
        slot->color = slot->n_colors - 1;
    } else {
        slot->color--;
    }
}

void Slot_destroy(Slot * slot)
{
    free(slot);
}
