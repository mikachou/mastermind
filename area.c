#include "area.h"

Area * Area_create(int n_rows, int n_slots, int n_colors)
{
    int i;
    Area * area;
    
    area = malloc(sizeof(Area));
    
    area->n_rows = n_rows;
    area->n_slots = n_slots;
    area->n_colors = n_colors;
    
    area->combinationRows = malloc(area->n_rows * sizeof(Row *));
    area->answerRows = malloc(area->n_rows * sizeof(Row *));
    
    for (i = 0; i < area->n_rows; i++) {
        *(area->combinationRows + i) = Row_create(combination, area->n_slots, area->n_colors);
        *(area->answerRows + i) = Row_create(answer, area->n_slots, area->n_colors);
    }
    
    return area;
}

void Area_destroy(Area * area)
{
    int i;
    
    for (i = 0; i < area->n_rows; i++) {
        Row_destroy(*(area->combinationRows + i));
        Row_destroy(*(area->answerRows + i));
    }
    
    free(area->combinationRows);
    free(area->answerRows);
    
    free(area);
}