#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int
main (void)
{

    MenuOption option = display_menu ();

    switch (option)
    {
        case EXIT_GAME:
            exit (0);
            break;
        case NEW_GAME:
            start_new_game ();
            break;
        case LOAD_GAME:
            load_game ();
            break;
        default:
            printf ("Unrecognized option %d. Exiting game...\n", option);
            break;
    }
 
    return 0;
}
