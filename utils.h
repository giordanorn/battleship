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


/*
 * Procedures
 */

void start_new_game (void);
void load_game (void);
MenuOption display_menu (void);

#endif
