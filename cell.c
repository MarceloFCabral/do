#include"cell.h"

Cell* createCell(Task *ta){
    Cell *newCell = NULL;
    newCell = (Cell*) malloc(sizeof(Cell));
    newCell->t = ta;
    newCell->prev = newCell->next = NULL;
    return newCell;
}

Task* removeCell(Cell *c, int op){ //0 -> desalocar tarefa; op != 0 -> retornar tarefa para uso posTueior
    Task *remov = NULL;
    if(c != NULL){
        if(c->prev != NULL){c->prev->next = c->next;}
        if(c->next != NULL){c->next->prev = c->prev;}
        c->prev = c->next = NULL;
        printf("Task removida:");
        printTask(c->t);
        remov = removeTask(c->t, op);
        free(c);
    }
    return remov;
}