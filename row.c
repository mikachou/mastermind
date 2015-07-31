#include "row.h"

Row * Row_create(RowType type, int n_slots, int n_colors)
{
    int i;
    Row * row;
    
    row = malloc(sizeof(Row));
    
    row->type = type;
    row->n_slots = n_slots;
    row->n_colors = n_colors;

    row->slots = malloc(row->n_slots * sizeof(Slot *));

    for (i = 0; i < row->n_slots; i++) {
        *(row->slots + i) = Slot_create(row->type, n_colors);
    }
    
    return row;
}

void Row_destroy(Row * row)
{
    int i;
    
    for (i = 0; i < row->n_slots; i++) {
        Slot_destroy(*(row->slots + i));
    }
    
    free(row->slots);
    
    free(row);
}