#ifndef _ROW_H_
#define _ROW_H_

#include "slot.h"

#define RowType SlotType

typedef struct {
    RowType type;
    Slot ** slots;
    int n_slots;
    int n_colors;
} Row;

Row * Row_create(RowType type, int n_slots, int n_colors);
void Row_destroy(Row * row);

#endif