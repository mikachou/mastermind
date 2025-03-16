#include "SDL_ui.h"

SDL_UI * SDL_UI_create()
{
    SDL_UI * ui;

    ui = malloc(sizeof(SDL_UI));

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "SDL_Init Error : %s\n", SDL_GetError());

        return NULL;
    }

    if (SDL_CreateWindowAndRenderer(400, 600, SDL_WINDOW_SHOWN, &ui->window, &ui->renderer) < 0)
    {
        fprintf(stderr, "Error whle creating window and renderer : %s", SDL_GetError());

        return NULL;
    }

    SDL_UI_newGame(ui);

    return ui;
}

void SDL_UI_newGame(SDL_UI * ui)
{
    if (ui->game != NULL) {
        SDL_Game_destroy(ui->game);
    }

    ui->game = SDL_Game_create(ui->renderer, N_ROWS, N_SLOTS, N_COLORS, SLOT_RADIUS, DIST_BTW_SLOT_AND_BORDER, FILL_COLOR, BORDER_COLOR, CURSOR_COLOR, baseColors);
}

void SDL_UI_playGame(SDL_UI * ui)
{
    int quit, end, i;
    SDL_Event event;

    SDL_Area_draw(ui->game->area);

    SDL_RenderPresent(ui->renderer);

    SDL_SetWindowSize(ui->window, ui->game->area->width, ui->game->area->height);

    //((*(ui->game->area->rows + ui->game->base->attempt))->combination)->cursorCurrentPos = 0;
    //SDL_Slot_cursorOn(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots));

    for (i = 0; i < N_SLOTS; i++) {
        (*((*(ui->game->area->rows))->combination->slots + i))->base->color = 0;
    }

    while (quit != 1 && end != 1) {
        SDL_Area_draw(ui->game->area);
        SDL_Slot_cursorOn(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + (*(ui->game->area->rows + ui->game->base->attempt))->combination->cursorCurrentPos));

        SDL_RenderPresent(ui->renderer);

        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    quit = 1;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_LEFT) {
                    SDL_CombinationRow_moveCursorLeft((*(ui->game->area->rows + ui->game->base->attempt))->combination);
                }

                if (event.key.keysym.sym == SDLK_RIGHT) {
                    SDL_CombinationRow_moveCursorRight((*(ui->game->area->rows + ui->game->base->attempt))->combination);
                }

                if (event.key.keysym.sym == SDLK_UP) {
                    SDL_Slot_nextColor(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + (*(ui->game->area->rows + ui->game->base->attempt))->combination->cursorCurrentPos));
                }

                if (event.key.keysym.sym == SDLK_DOWN) {
                    SDL_Slot_previousColor(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + (*(ui->game->area->rows + ui->game->base->attempt))->combination->cursorCurrentPos));
                }

                if (event.key.keysym.sym == SDLK_RETURN
                    || event.key.keysym.sym == SDLK_RETURN2
                    || event.key.keysym.sym == SDLK_KP_ENTER) {
                    for (i = 0; i < ui->game->base->n_slots; i++) {
                        Game_getCurrentPlayerCombination(ui->game->base)->slots[i]->color
                            = (*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + i))->base->color;
                    }

                    Game_evaluateCurrentPlayerCombination(ui->game->base);

                    for (i = 0; i < ui->game->base->n_slots; i++) {
                        (*((*(ui->game->area->rows + ui->game->base->attempt))->answer->slots + i))->base->color
                            = Game_getCurrentAnswer(ui->game->base)->slots[i]->color;
                    }

                    SDL_AnswerRow_draw((*(ui->game->area->rows + ui->game->base->attempt))->answer);

                    if (Game_hasPlayerWon(ui->game->base) || Game_hasPlayerLost(ui->game->base)) {
                        end = 1;

                        for (i = 0; i < ui->game->base->n_slots; i++) {
                            (*(ui->game->area->codeRow->slots + i))->base->color
                               = (*(ui->game->base->combination->slots + i))->color;
                        }
                    } else {
                        ui->game->base->attempt++;

                        for (i = 0; i < N_SLOTS; i++) {
                            (*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + i))->base->color
                                = (*((*(ui->game->area->rows + ui->game->base->attempt - 1))->combination->slots + i))->base->color;
                        }

                        (*(ui->game->area->rows + ui->game->base->attempt))->combination->cursorCurrentPos
                            = (*(ui->game->area->rows + ui->game->base->attempt - 1))->combination->cursorCurrentPos ;
                    }
                    //SDL_Area_draw(ui->game->area);
                    //SDL_Slot_cursorOn(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots + (*(ui->game->area->rows + ui->game->base->attempt))->combination->cursorCurrentPos));
                }

                /*else {
                    SDL_Slot_cursorOn(*((*(ui->game->area->rows + ui->game->base->attempt))->combination->slots));
                }*/

                break;
        }


        //SDL_RenderPresent(ui->renderer);
    }

    SDL_Area_draw(ui->game->area);

    SDL_RenderPresent(ui->renderer);

    while (quit != 1) {
        SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                    quit = 1;
                }
                break;
            case SDL_KEYUP:
                quit = 1;
                break;
        }
    }
}

void SDL_UI_destroy(SDL_UI * ui)
{
    SDL_DestroyWindow(ui->window);
    SDL_Quit();
    SDL_Game_destroy(ui->game);
    free(ui);
}
