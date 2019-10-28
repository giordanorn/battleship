#ifndef UTILS_H
#define UTILS_H

/*
 * Essential Types
 */

typedef enum {
    EXIT_GAME,
    NEW_GAME,
    LOAD_GAME
} MenuOption;

typedef enum {
    WATER,
    CARRIER,	
    BATTLESHIP,
    DESTROYER,
    SUBMARINE,
    PATROL_BOAT
} Point;

typedef Point Grid[10][10];

typedef struct {
    char owner[16];
    int width;
    int height;
    Grid grid;
} Board;

/*
 * Procedures
 */

void start_new_game (void);
void load_game (void);
void display_menu (void);
MenuOption get_menu_option (void);
void print_board (Board);
void initialize_board (Board);

#endif
