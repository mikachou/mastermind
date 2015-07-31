#include "SDL_ui.h"

int main()
{
    SDL_UI * ui;
    
    if ((ui = SDL_UI_create()) == NULL) {
        return EXIT_FAILURE;
    }
    
    SDL_UI_playGame(ui);
    
    SDL_UI_destroy(ui);
    
    return EXIT_SUCCESS;
}
