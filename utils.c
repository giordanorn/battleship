#include "utils.h"
#include <stdio.h>

void
set_grid_empty (Grid *grid, int rows, int cols)
{
    for (int i = 0; i < rows*cols; ++i)
	{
        grid[i] = EMPTY;
	}
}

void
print_grid (Grid *grid, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			printf ("%c ", grid[i] + 97);
		}
		printf ("\n");
	}
}