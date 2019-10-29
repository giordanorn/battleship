#include "utils.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
    
    initialize_board (&player);
    initialize_board (&enemy);

    srand (time (NULL));
    setup_board (&player);
    setup_board (&enemy);

    // printing is for debugging purposes :P
    print_board (player); 
    print_board (enemy);
    
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
    printf ("%s's board:\n", board.owner);
    for (int i = 0; i < board.height; i++)
    {
        for (int j = 0; j < board.width; j++)
            printf (" %d", board.grid[i][j]);
        printf ("\n");
    }
}

void
initialize_board (Board *board)
{
    for (int i = 0; i < board->height; i++)
        for (int j = 0; j < board->width; j++)
            board->grid[i][j] = WATER;
}

void
setup_board (Board *board)
{
    insert_carrier (board);
    insert_battleship (board);
    insert_destroyer (board);
    insert_submarine (board);
    insert_patrol_boat (board);
}

void
insert_carrier (Board *board)
{
    insert_ship (board, 5, CARRIER);
}

void
insert_battleship (Board *board)
{
    insert_ship (board, 4, BATTLESHIP);
}

void
insert_destroyer (Board *board)
{
    insert_ship (board, 3, DESTROYER);
}

void
insert_submarine (Board *board)
{
    insert_ship (board, 3, SUBMARINE);
}

void
insert_patrol_boat (Board *board)
{
    insert_ship (board, 2, PATROL_BOAT);
}

void
insert_ship (Board *board, int ship_size, Point ship_type)
{
    Orientation orientation = rand () % 2;
    if (orientation == HORIZONTAL)
    {
        bool
        seed_validity_check (int x, int y)
        {
            for (int i = 0; i < ship_size; ++i)
            {
                // conditions for avoiding accessing non-existent coordinates
                if ( y == 0 )
                    if (
                        board->grid[  y  ][x + i] != WATER ||
                        board->grid[y + 1][x + i] != WATER
                       )
                        return false;
                else if ( y == board->height - 1 )
                    if (
                        board->grid[y - 1][x + i] != WATER ||
                        board->grid[  y  ][x + i] != WATER
                       )
                        return false;
                else
                    if (
                        board->grid[y - 1][x + i] != WATER ||
                        board->grid[  y  ][x + i] != WATER ||
                        board->grid[y + 1][x + i] != WATER
                       )
                        return false;
            }
            return true;
        }
                
        // try to generate a seed (starting point) for the ship
        int xseed, yseed;
        do {
            xseed = rand () % (board->width - ship_size);
            yseed = rand () % board->height;
        } while ( ! seed_validity_check (xseed, yseed) );

        printf ("Inserting a ship of size %d at coordinate (%d,%d) in horizontal orientation.\n", ship_size, xseed, yseed);

        // inserts ship for real
        for (int i = 0; i < ship_size; ++i)
            board->grid[yseed][xseed + i] = ship_type;
    }
    else
    {
        int xseed, yseed;
        xseed = rand () % board->width;
        yseed = rand () % (board->height - ship_size);

        printf ("Inserting a ship of size %d at coordinate (%d,%d) in vertical orientation.\n", ship_size, xseed, yseed);

        for (int i = 0; i < ship_size; ++i)
            board->grid[yseed + i][xseed] = ship_type;
    }
}

