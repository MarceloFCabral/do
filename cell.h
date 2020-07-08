#include"task.c"

typedef struct Cell{
    Task *t;
    struct Cell *prev, *next;
}Cell;

Cell* createCell(Task *ta);
Task* removeCell(Cell *c, int op);
