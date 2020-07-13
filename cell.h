/**
 * Defines the Cell struct and all the function headers related to it.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"task.c"
#ifndef CELL_H
#define CELL_H

/**
 * struct Cell: holds a pointer to a Task struct (Task*) and pointers to the previous (struct Cell *prev) and next (struct Cell *next)
 * Cells in a doubly linked list.
 */
typedef struct Cell{
    Task *t;
    struct Cell *prev, *next;
}Cell;

Cell* createCell(Task *ta);
Task* removeCell(Cell *c, int op);

#endif