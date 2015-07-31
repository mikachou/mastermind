#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

#define N_ROWS 12
#define N_SLOTS 4
#define N_COLORS 6

int main()
{
    Game * game;
    
    srand(time(NULL));
    
    game = Game_create(N_ROWS, N_SLOTS, N_COLORS);
    
    do {
        printf("Tentative %d\n", game->attempt + 1);
        
        scanf("%d %d %d %d", 
            &Game_getCurrentPlayerCombination(game)->slots[0]->color,
            &Game_getCurrentPlayerCombination(game)->slots[1]->color,
            &Game_getCurrentPlayerCombination(game)->slots[2]->color,
            &Game_getCurrentPlayerCombination(game)->slots[3]->color);
            
        Game_evaluateCurrentPlayerCombination(game);
        
        printf("Résultat : %d %d %d %d\n",
            Game_getCurrentAnswer(game)->slots[0]->color,
            Game_getCurrentAnswer(game)->slots[1]->color,
            Game_getCurrentAnswer(game)->slots[2]->color,
            Game_getCurrentAnswer(game)->slots[3]->color);
            
    } while (!Game_hasPlayerWon(game) && !Game_hasPlayerLost(game) && ++game->attempt);
    
    if (Game_hasPlayerWon(game)) {
        printf("gagné\n");
    }
    
    if (Game_hasPlayerLost(game)) {
        printf("perdu\n");
        printf("Combinaison : %d %d %d %d\n",
            game->combination->slots[0]->color,
            game->combination->slots[1]->color,
            game->combination->slots[2]->color,
            game->combination->slots[3]->color);
    }
}