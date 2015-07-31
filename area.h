#ifndef _AREA_H_
#define _AREA_H_

#include "row.h"

typedef struct {
    Row ** combinationRows;
    Row ** answerRows;
    int n_rows;
    int n_slots;
    int n_colors;
} Area;

Area * Area_create(int n_rows, int n_slots, int n_colors);
void Area_destroy(Area * area);

#endif