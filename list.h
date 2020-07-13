/**
 * Defines the List struct and all the function headers related to it.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"cell.c"
#ifndef LIST_H
#define LIST_H

/**
 * struct List: a doubly linked list. Holds the pointers to the first and last cells (Cell*) of the list.
 * Also holds an integer (n) that is always equal to the number of cells (and tasks) in the list.
 */
typedef struct List{
    Cell *first, *last;
    int n;
}List;

List* createList();
Cell* removeList(List *l, int op);
Task* removeFront(List *l, int op);
Task* removeEnd(List *l, int op);
Cell* searchForCell(List *l, char *name);
Task* searchForTask(List *l, char *name);
int insertTask(List *l, Task *ta, int op);
Task* removeTaskFromList(List *l, char *name, int op);
void printList(List *l);

#endif