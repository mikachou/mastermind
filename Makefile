.SUFFIXES:
.PHONY: clean, message, objects

CC = gcc
CFLAGS = -std=c11
EXEC = mastermind
DEBUG = yes

ifeq ($(DEBUG),yes)
		CFLAGS += -Wall
endif

ifeq ($(CLEAN),yes)
		CALLS += clean
endif

all:
		make clean sdl;

message:
ifeq ($(DEBUG),yes)
		@echo "Compile in debug mode"
else
		@echo "Compile in release mode"
endif

console: slot.o row.o area.o game.o main.o
		$(CC) $^ -o $(EXEC)

sdl: slot.o row.o area.o game.o SDL_slot.o SDL_row_button.o SDL_combination_row.o SDL_answer_row.o SDL_row.o SDL_area.o SDL_game.o SDL_ui.o SDL_main.o
		$(CC) $^ -o $(EXEC) -lSDL2 -lSDL2_gfx -lm

%.o: %.c
		$(CC) -c $< -o $@ $(CFLAGS) -lSDL2-2 -lSDL2gfx -lm
		
clean:
		rm -rf *.o
