#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int
main (void)
{
    display_menu ();
    MenuOption option = get_menu_option ();
    switch (option)
    {
        case EXIT_GAME:
            printf ("Bye.\n");
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
