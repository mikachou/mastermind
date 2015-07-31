#ifndef _SLOT_H_
#define _SLOT_H_

#include <stdlib.h>

#define SLOT_COLOR_OK(n_colors) (n_colors)
#define SLOT_COLOR_ANOTHER(n_colors) (n_colors + 1)
#define SLOT_COLOR_NONE -1

typedef enum {
    combination, answer
} SlotType;

typedef enum {
    none, another, ok
} SlotCheck;

typedef struct {
    SlotType type;
    int color;
    int n_colors;
} Slot;

Slot * Slot_create(SlotType type, int n_colors);
void Slot_setNextCombinationColor(Slot * slot);
void Slot_setPreviousCombinationColor(Slot * slot);
void Slot_destroy(Slot * slot);

#endif