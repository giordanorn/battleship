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
} Water;

typedef enum {
    FREE,
    SHOT
} Target;

// Back layer
typedef Water ShipMap[10][10];

// Front layer
typedef Target HitMap[10][10];

typedef struct {
    char owner[16];
    int width;
    int height;
    ShipMap shipmap;
    HitMap hitmap;
} Board;

typedef enum {
    HORIZONTAL,
    VERTICAL
} Orientation;

typedef enum {
    MISS,
    HIT
} Shot;

/*
 * Procedures and functions
 */

void start_new_game (void);
void start_game (Board*, Board*);
void load_game (void);
void display_menu (void);
MenuOption get_menu_option (void);
void print_board (Board*);
void initialize_board (Board*);
void setup_ships (Board*);
void insert_ship (Board*, int, Water);
void insert_carrier (Board*);
void insert_battleship (Board*);
void insert_destroyer (Board*);
void insert_submarine (Board*);
void insert_patrol_boat (Board*);
void play_turn (Board*);
Shot fire (Board*, int, int);

#endif
