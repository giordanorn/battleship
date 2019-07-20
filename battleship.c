#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int
main (void)
{
    const int ROWS = 10;
    const int COLS = 10;

    Grid *player_grid = (Grid *) calloc (ROWS * COLS, sizeof(Grid));

    print_grid (player_grid, ROWS, COLS);
    set_grid_empty (player_grid, ROWS, COLS);
 
    return 0;
}
