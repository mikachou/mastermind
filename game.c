#include "game.h"

Game * Game_create(int n_rows, int n_slots, int n_colors)
{
    Game * game;
    
    game = malloc(sizeof(Game));
    
    game->n_rows = n_rows;
    game->n_slots = n_slots;
    game->n_colors = n_colors;
    
    game->area = Area_create(game->n_rows, game->n_slots, game->n_colors);
    
    game->attempt = 0;
    
    Game_initCombination(game);
    
    return game;
}

void Game_initCombination(Game * game)
{
    int i;
        
    game->combination = Row_create(combination, game->n_slots, game->n_colors);
    
    for (i = 0; i < game->n_slots; i++) {
        game->combination->slots[i]->color = Game_getRandomColor(game);
    }
}

int Game_getRandomColor(Game * game)
{
    return rand() % game->n_colors;
}

Row * Game_getCurrentPlayerCombination(Game * game)
{
    return game->area->combinationRows[game->attempt];
}

Row * Game_getCurrentAnswer(Game * game)
{
    return game->area->answerRows[game->attempt];
}

void Game_evaluateCurrentPlayerCombination(Game * game)
{
    int * codeUsed, * guessUsed, correct, match, i, j;
    
    correct = match = 0;
    
    codeUsed = calloc(game->n_slots, sizeof(int));
    guessUsed = calloc(game->n_slots, sizeof(int));
    
    for (int i = 0; i < game->n_slots; i++) {
        if (game->combination->slots[i]->color == Game_getCurrentPlayerCombination(game)->slots[i]->color) {
            correct++;
            codeUsed[i] = guessUsed[i] = 1;
        }
    }
    
    // Compare matching colors for "pins" that were not used
    for (int i = 0; i < game->n_slots; i++) {
        for (int j = 0; j < game->n_slots; j++) {
            if (!codeUsed[i] && !guessUsed[j] 
                && game->combination->slots[i]->color == Game_getCurrentPlayerCombination(game)->slots[j]->color) {
                match++;
                codeUsed[i] = guessUsed[j] = 1;
                break;
            }
        }
    }
    
    for (i = 0, j = 0; i < correct; i++) {
        Game_getCurrentAnswer(game)->slots[j++]->color = SLOT_COLOR_OK(game->n_colors);
    }
    
    for (i = 0; i < match; i++) {
        Game_getCurrentAnswer(game)->slots[j++]->color = SLOT_COLOR_ANOTHER(game->n_colors);
    }
    
    free(codeUsed);
    free(guessUsed);
}

int Game_hasPlayerWon(Game * game)
{
    int i;
    
    for (i = 0; i < game->n_slots; i++) {
        if (Game_getCurrentAnswer(game)->slots[i]->color != SLOT_COLOR_OK(game->n_colors)) {
            return 0;
        }
    }
    
    return 1;
}

int Game_hasPlayerLost(Game * game)
{
    if (game->attempt < game->n_rows - 1) {
        return 0;
    }
    
    return !Game_hasPlayerWon(game);
}

void Game_destroy(Game * game)
{
    Area_destroy(game->area);
    
    free(game);
}
