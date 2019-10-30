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
    char name[16];
    int size;
    int health;
} Ship;

typedef Ship* Water;

// Back layer
typedef Water ShipMap[10][10];

typedef enum {
    FREE,
    SHOT,
    SANK
} Target;

// Front layer
typedef Target HitMap[10][10];

typedef struct {
    char owner[16];
    int width;
    int height;
    ShipMap shipmap;
    HitMap hitmap;
    Ship carrier;
    Ship battleship;
    Ship destroyer;
    Ship submarine;
    Ship patrolboat;
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
void insert_ship (Board*, int, Ship*);
void insert_carrier (Board*);
void insert_battleship (Board*);
void insert_destroyer (Board*);
void insert_submarine (Board*);
void insert_patrolboat (Board*);
void play_turn (Board*);
Shot fire (Board*, int, int);

#endif
