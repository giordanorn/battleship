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

typedef struct {
    char owner[16];
    int width;
    int height;
    int grid[10][10];
} Board;

/*
 * Procedures
 */

void start_new_game (void);
void load_game (void);
void display_menu (void);
MenuOption get_menu_option (void);
void print_board (Board);

#endif
