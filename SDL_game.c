#include "SDL_game.h"

SDL_Game * SDL_Game_create(SDL_Renderer * renderer, int n_rows, int n_slots, int n_colors, int slotRadius, int distBtwSlotAndBorder, int fillColor, int borderColor, int cursorColor, int * baseColors)
{   
    SDL_Game * game;
    
    game = malloc(sizeof(SDL_Game));
    
    game->base = Game_create(n_rows, n_slots, n_colors);
    game->area = SDL_Area_create(renderer, 0, 0, n_rows, n_slots, n_colors, slotRadius, distBtwSlotAndBorder, fillColor, borderColor, cursorColor, baseColors);
    
    return game;
}

void SDL_Game_destroy(SDL_Game * game)
{
    SDL_Area_destroy(game->area);
    
	free(game);
}
