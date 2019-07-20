#ifndef UTILS_H
#define UTILS_H

/*
 * Essential Types
 */

typedef enum {
    EMPTY,
    SHIP_OF_TYPE_1,
    SHIP_OF_TYPE_2
} Grid;

/*
 * Procedures
 */

void set_grid_empty (Grid *, int, int);
void print_grid (Grid *, int, int);

#endif
