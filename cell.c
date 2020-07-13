/**
 * Defines all the functions listed in "cell.h".
 * @author Marcelo F, Cabral (marcelofc12@gmail.com)
 */

#include"cell.h"
#ifndef CELL_C
#define CELL_c

/**
 * Creates a Cell struct by dynamically allocating memory for it.
 * @param ta a pointer to a Task struct.
 * @return a pointer to the newly allocated Cell struct (Cell*).
 * This function assumes that, if NULL is passed as an argument, the created cell is a sentinel node. 
 * For this reason, the pointer's value is not checked.
 */
Cell* createCell(Task *ta){
    Cell *newCell = NULL;
    newCell = (Cell*) malloc(sizeof(Cell));
    newCell->t = ta;
    newCell->prev = newCell->next = NULL;
    return newCell;
}

/**
 * Removes a cell from a doubly linked list ("connecting" the removed cell's previous and next node to eachother).
 * Also deallocates the Task struct pointed at by the removed Cell or simply returns its address, depending on the operation code.
 * @param c a pointer to a Cell struct (Cell*).
 * @param op an operation code. If 1 is passed, returns a pointer which contains the removed cell's Task struct address (Task*).
 * If 0 is passed, deallocates data pointed at by the Cell struct's Task pointer (Task*) and deallocates the cell in memory (Cell*).
 * @return NULL, if op == 0; c->t, if op == 1.
 */
Task* removeCell(Cell *c, int op){
    Task *remov = NULL;
    if(c != NULL){
        if(c->prev != NULL){c->prev->next = c->next;}
        if(c->next != NULL){c->next->prev = c->prev;}
        c->prev = c->next = NULL;
        printf("Removed task:");
        printTask(c->t);
        remov = removeTask(c->t, op);
        free(c);
    }
    return remov;
}

#endif