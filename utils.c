#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void
start_new_game (void)
{
    printf ("void start_new_game (void) method is currently in progress. Exiting...\n");
}

void
load_game (void)
{
    printf ("void load_game (void) method is currently in progress. Exiting...\n");
}

MenuOption
get_menu_option (void)
{
    printf ("Please, choose an option from menu options.\n");
    printf ("> ");
    MenuOption option;
    scanf ("%d", &option);
    return option;
}

void
display_menu (void)
{
    printf ("Battleship Game - Menu:\n");
    printf ("0 - Exit\n");
    printf ("1 - Start new game\n");
    printf ("2 - Load previous game\n");
}
