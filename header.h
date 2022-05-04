#pragma once

// Standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Non-Standard C libraries
#include <curses.h>
#include <ncurses.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

// board related functions
#define N_ROWS 60
#define N_COLS 250

// color definitions
#define RED         2
#define YELLOW      3
#define GREEN       4
#define CYAN        5
#define BLUE        6
#define MAGENTA     7
#define WHITE       8
#define BLACK       9

#define SELECTED_PAIR 10
#define HOVER_PAIR    11

// State of the Game from the server end
typedef struct {
    int n_player;
    int grid[N_ROWS][N_COLS];
} GameState;

// State of the game from the client end
typedef struct {
    int grid[N_ROWS][N_COLS];
    int loc_x;
    int loc_y;
    int color;
} PlayerState;

GameState* init_game();

// graphics related functions
void init_screen();
void init_colors();
void draw_instructions();
void draw_grid(int, int);
void draw_palette();

//Player draw_all();
void draw_all();
// void draw_state(State* state);

// network related functions
int read_in(int, char*, int);
void error(char*);
int open_listener_socket();
void bind_to_port(int, int);
int say(int, char*);