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
    CARRIER,	// it occupies 5 points
    BATTLESHIP, // it occupies 4 points
    DESTROYER,  // it occupies 3 points
    SUBMARINE,  // it occupies 3 points
    PATROL_BOAT // it occupies 2 points
} Point;

typedef Point Grid[10][10];

typedef struct {
    char owner[16];
    int width;
    int height;
    Grid grid;
} Board;

typedef enum {
    HORIZONTAL,
    VERTICAL
} Orientation;

/*
 * Procedures and functions
 */

void start_new_game (void);
void load_game (void);
void display_menu (void);
MenuOption get_menu_option (void);
void print_board (Board);
void initialize_board (Board*);
void setup_board (Board*);
void insert_ship (Board*, int, Point);
void insert_carrier (Board*);
void insert_battleship (Board*);
void insert_destroyer (Board*);
void insert_submarine (Board*);
void insert_patrol_boat (Board*);


#endif
