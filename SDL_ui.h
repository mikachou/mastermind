#ifndef _SDL_UI_H_
#define _SDL_UI_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include "game.h"
#include "SDL_game.h"

#define N_ROWS 12
#define N_SLOTS 4
#define N_COLORS 6
#define SLOT_RADIUS 15
#define DIST_BTW_SLOT_AND_BORDER 10
#define FILL_COLOR 0xFF0085CD
#define BORDER_COLOR 0xFF000000
#define CURSOR_COLOR 0xFF00FF00

static int baseColors[] = {
    0xFFFF0000, // blue
    0xFF00FF00, // green
    0xFF0000FF, // red
    0xFF00FFFF, // yellow
    0xFFF020A0, // purple
    0xFF00A5FF, // orange
    0xFF0000FF, // red
    0xFFFFFFFF  // white
};

typedef struct {
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Game * game;
} SDL_UI;

SDL_UI * SDL_UI_create();
void SDL_UI_newGame(SDL_UI * ui);
void SDL_UI_playGame(SDL_UI * ui);
void SDL_UI_destroy(SDL_UI * ui);

#endif
