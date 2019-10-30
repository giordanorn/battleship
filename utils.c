#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

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
    setup_ships (&player);
    setup_ships (&enemy);

    start_game (&player, &enemy);
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
print_board (Board *board)
{
    printf ("# %s's board:\n", board->owner);
    printf (" ");
    for (int i = 0; i < board->height; i++)
        printf (" %d", i);
    printf ("\n");
    for (int i = 0; i < board->height; i++)
    {
        printf ("%d", i);
        for (int j = 0; j < board->width; j++)
        {
            if ( board->hitmap[i][j] == SHOT )
                if ( board->shipmap[i][j] == WATER )
                    printf (" %c", ' ');
                else
                    printf (" %c", '*');
            else 
                printf (" %c", '~');
        }
        printf ("\n");
    }
}

void
initialize_board (Board *board)
{
    for (int i = 0; i < board->height; i++)
        for (int j = 0; j < board->width; j++)
        {
            board->shipmap[i][j] = WATER;
            board->hitmap[i][j] = FREE;
        }
}

void
setup_ships (Board *board)
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
insert_ship (Board *board, int ship_size, Water ship_type)
{
    Orientation orientation = rand () % 2;
    if (orientation == HORIZONTAL)
    {
        bool
        seed_validity_check (int x, int y)
        {
            // check the left corners (up, middle and down)
            if ( x != 0 )
            {
                if ( board->shipmap[y][x - 1] != WATER )
                    return false;
                if ( y != 0 )
                   if ( board->shipmap[y - 1][x - 1] != WATER )
                       return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x - 1] != WATER )
                        return false;
            }
            // check the right corners (up, middle and down)
            if ( x != board->width - 1 )
            {
                if ( board->shipmap[y][x + ship_size] != WATER )
                    return false;
                if ( y != 0 )
                   if ( board->shipmap[y - 1][x + ship_size] != WATER )
                       return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x + ship_size] != WATER )
                        return false;
            }
            // check the up an downwards the ship
            for (int i = 0; i < ship_size; ++i)
            {
                if ( board->shipmap[y][x + i] != WATER ) return false;
                if ( y != 0 )
                    if ( board->shipmap[y - 1][x + i] != WATER )
                        return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x + i] != WATER )
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

        // inserts ship for real
        for (int i = 0; i < ship_size; ++i)
            board->shipmap[yseed][xseed + i] = ship_type;
    }
    else
    {
        bool
        seed_validity_check (int x, int y)
        {
            // check the upwards (left, center and right)
            if ( y != 0 )
            {
                if ( board->shipmap[y - 1][x] != WATER )
                    return false;
                if ( x != 0 )
                   if ( board->shipmap[y - 1][x - 1] != WATER )
                       return false;
                if ( x != board->width - 1 )
                    if ( board->shipmap[y - 1][x + 1] != WATER )
                        return false;
            }
            // check the downwards (left, center and right)
            if ( y != board->height - 1 )
            {
                if ( board->shipmap[y + ship_size][x] != WATER )
                    return false;
                if ( x != 0 )
                   if ( board->shipmap[y + ship_size][x - 1] != WATER )
                       return false;
                if ( x != board->width - 1 )
                    if ( board->shipmap[y + ship_size][x + 1] != WATER )
                        return false;
            }
            // check the sides of the ship
            for (int i = 0; i < ship_size; ++i)
            {
                if ( board->shipmap[y + i][x] != WATER ) return false;
                if ( x != 0 )
                    if ( board->shipmap[y + i][x - 1] != WATER )
                        return false;
                if ( x != board->height - 1 )
                    if ( board->shipmap[y + i][x + 1] != WATER )
                        return false;
            }
            return true;
        }

        int xseed, yseed;
        do {
            xseed = rand () % board->width;
            yseed = rand () % (board->height - ship_size);
        } while ( ! seed_validity_check (xseed, yseed) );

        for (int i = 0; i < ship_size; ++i)
            board->shipmap[yseed + i][xseed] = ship_type;
    }
}

void
start_game (Board *player, Board *enemy)
{
    while (true)
    {
        printf ("# %s's turn now.\n", player->owner);
        sleep (1);
        play_turn (player);
        sleep (2);
        printf ("# %s's turn is over.\n", player->owner);
        sleep (2);

        printf ("# %s's turn now.\n", enemy->owner);
        sleep (1);
        play_turn (enemy);
        sleep (2);
        printf ("# %s's turn is over.\n", enemy->owner);
        sleep (2);
    }
}

void
play_turn (Board *board)
{
    Shot attempt;
    do {

        print_board (board);

        int x, y;
        
        // TODO check invalid inputs and all of those good shit
        printf ("# Enter the coordinates x and y of your target respectively:\n");
        printf ("> ");
        scanf ("%d %d", &x, &y);

        // inverted axes for respect the logic of matrices indexes
        printf ("# Fire!\n");
        sleep (1);
        attempt = fire (board, y, x);
        sleep (1);
    } while ( attempt == HIT );
    print_board (board);
}

Shot
fire (Board *board, int x, int y)
{
    if (board->hitmap[x][y] == FREE)
    {
        board->hitmap[x][y] = SHOT;
        if (board->shipmap[x][y] == WATER)
        {
            printf ("# You shot the water.\n");
            return MISS;
        }
        else
        {
            printf ("# Nice shot, you got it!\n");
            return HIT;
        }
    }
    else
    {
        printf ("# You already shot this place, dammit!\n");
        return HIT;
    }
}
