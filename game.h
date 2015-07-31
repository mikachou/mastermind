#ifndef _GAME_H_
#define _GAME_H_

#include "area.h"

typedef struct {
    int attempt;
    Row * combination;
    Area * area;
    int n_rows;
    int n_slots;
    int n_colors;
} Game;

Game * Game_create(int n_rows, int n_slots, int n_colors);
void Game_initCombination(Game * game);
int Game_getRandomColor(Game * game);
Row * Game_getCurrentPlayerCombination(Game * game);
Row * Game_getCurrentAnswer(Game * game);
void Game_evaluateCurrentPlayerCombination(Game * game);
int Game_hasPlayerWon(Game * game);
int Game_hasPlayerLost(Game * game);
void Game_destroy(Game * game);

#endif