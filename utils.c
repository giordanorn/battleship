#include "utils.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void
start_new_game (void)
{
    Board player = {
        .owner  = "Player",
        .width  = 10,
        .height = 10
    };

    Board enemy = {
        .owner  = "Enemy",
        .width  = 10,
        .height = 10
    };
    
    initialize_board (player);
    initialize_board (enemy);

    // printing is for debugging purposes :P
    print_board (player); 
    print_board (enemy);

    //setup_board (player);
    //setup_board (enemy);
    
    start_game ();
}

void
load_game (void)
{
    printf ("void load_game (void) method is currently in progress. Exiting.\n");
}

void
display_menu (void)
{
    printf ("Battleship Game - Menu:\n");
    printf ("0 - Exit\n");
    printf ("1 - Start new game\n");
    printf ("2 - Load previous game\n");
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
print_board (Board board)
{
    printf ("Printing %s's board:\n", board.owner);
    for (int i = 0; i < board.height; i++)
        for (int j = 0; j < board.width; j++)
            printf ("board.grid[%d][%d] = %d\n", i, j, board.grid[i][j]);
}

void
initialize_board (Board board)
{
    for (int i = 0; i < board.height; i++)
        for (int j = 0; j < board.width; j++)
            board.grid[i][j] = WATER;
}
