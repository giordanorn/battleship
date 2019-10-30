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
        .owner             = "Player",
        .width             = 10,
        .height            = 10,
    };

    Board enemy = {
        .owner             = "Enemy",
        .width             = 10,
        .height            = 10,
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
    for (int j = 0; j < board->width; j++)
        printf (" %d", j);
    printf ("\n");

    for (int i = 0; i < board->height; i++)
    {
        printf ("%d", i);
        for (int j = 0; j < board->width; j++)
        {
            if ( board->hitmap[i][j] == SHOT )
                if ( board->shipmap[i][j] == NULL )
                    printf (" %c", ' ');
                else
                {
                    if ( board->shipmap[i][j]->health == 0 )
                        printf (" %c", 'x');
                    else
                        printf (" %c", '*');
                }
            else 
                printf (" %c", '~');
        }
        printf ("\n");
    }
}

void
initialize_board (Board *board)
{
    Ship carrier = {
        .name      = "Carrier",
        .size      = 5,
        .health    = 5
    };
    Ship battleship = {
        .name   = "Battleship",
        .size   = 4,
        .health = 4
    };
    Ship destroyer = {
        .name    = "Destroyer",
        .size    = 3,
        .health  = 3
    };
    Ship submarine = {
        .name    = "Submarine",
        .size    = 3,
        .health  = 3
    };
    Ship patrolboat = {
        .name   = "Patrol Boat",
        .size   = 2,
        .health = 2
    };

    board->carrier    = carrier;
    board->battleship = battleship;
    board->destroyer  = destroyer;
    board->submarine  = submarine;
    board->patrolboat = patrolboat;

    for (int i = 0; i < board->height; i++)
        for (int j = 0; j < board->width; j++)
        {
            board->shipmap[i][j] = NULL;
            board->hitmap[i][j] = FREE;
        }
}

void
setup_ships (Board *board)
{
    insert_ship (board, board->carrier.size,    &board->carrier);
    insert_ship (board, board->battleship.size, &board->battleship);
    insert_ship (board, board->destroyer.size,  &board->destroyer);
    insert_ship (board, board->submarine.size,  &board->submarine);
    insert_ship (board, board->patrolboat.size, &board->patrolboat);
}

void
insert_ship (Board *board, int ship_size, Ship *ship)
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
                if ( board->shipmap[y][x - 1] != NULL )
                    return false;
                if ( y != 0 )
                   if ( board->shipmap[y - 1][x - 1] != NULL )
                       return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x - 1] != NULL )
                        return false;
            }
            // check the right corners (up, middle and down)
            if ( x != board->width - 1 )
            {
                if ( board->shipmap[y][x + ship_size] != NULL )
                    return false;
                if ( y != 0 )
                   if ( board->shipmap[y - 1][x + ship_size] != NULL )
                       return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x + ship_size] != NULL )
                        return false;
            }
            // check the up an downwards the ship
            for (int i = 0; i < ship_size; ++i)
            {
                if ( board->shipmap[y][x + i] != NULL ) return false;
                if ( y != 0 )
                    if ( board->shipmap[y - 1][x + i] != NULL )
                        return false;
                if ( y != board->height - 1 )
                    if ( board->shipmap[y + 1][x + i] != NULL )
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
            board->shipmap[yseed][xseed + i] = ship;
    }
    else
    {
        bool
        seed_validity_check (int x, int y)
        {
            // check the upwards (left, center and right)
            if ( y != 0 )
            {
                if ( board->shipmap[y - 1][x] != NULL )
                    return false;
                if ( x != 0 )
                   if ( board->shipmap[y - 1][x - 1] != NULL )
                       return false;
                if ( x != board->width - 1 )
                    if ( board->shipmap[y - 1][x + 1] != NULL )
                        return false;
            }
            // check the downwards (left, center and right)
            if ( y != board->height - 1 )
            {
                if ( board->shipmap[y + ship_size][x] != NULL )
                    return false;
                if ( x != 0 )
                    if ( board->shipmap[y + ship_size][x - 1] != NULL )
                        return false;
                if ( x != board->width - 1 )
                    if ( board->shipmap[y + ship_size][x + 1] != NULL )
                        return false;
            }
            // check the sides of the ship
            for (int i = 0; i < ship_size; ++i)
            {
                if ( board->shipmap[y + i][x] != NULL ) return false;
                if ( x != 0 )
                    if ( board->shipmap[y + i][x - 1] != NULL )
                        return false;
                if ( x != board->height - 1 )
                    if ( board->shipmap[y + i][x + 1] != NULL )
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
            board->shipmap[yseed + i][xseed] = ship;
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
        printf ("# Enter the line and column of your target respectively:\n");
        printf ("> ");
        scanf ("%d %d", &x, &y);

        printf ("# Fire!\n");
        sleep (1);
        attempt = fire (board, x, y);
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
        if ( board->shipmap[x][y] == NULL )
        {
            printf ("# You shot the water.\n");
            return MISS;
        }
        else
        {
            printf ("# Nice shot, you hit something!\n");
            board->shipmap[x][y]->health--;
            if ( board->shipmap[x][y]->health == 0 )
                printf ("# Great! You sank a %s.\n", board->shipmap[x][y]->name );
            return HIT;
        }
    }
    else
    {
        printf ("# You already shot at this place, please try again.\n");
        return HIT;
    }
}
