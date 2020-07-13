/**
 * Defines all the functions listed in "list.h".
 * @author Marcelo F, Cabral (marcelofc12@gmail.com)
 */

#include"list.h"
#include"util.c"
#ifndef LIST_C
#define LIST_C

/**
 * Creates a List struct by dynamically allocating memory for it.
 * @return a pointer to the newly allocated List struct (List*).
 */
List* createList(){
    List *l = (List*) malloc(sizeof(List));
    l->first = l->last = createCell(NULL);
    l->n = 0;
    return l;
}

/**
 * Deallocates a List struct in memory or simply returns a List struct's first cell's address, depending on the operation code.
 * @param l a pointer to a List struct.
 * @param op an operation code. If 1 is passed, returns the list's first cell's (sentinel) address.
 * If 0 is passed, deallocates data pointed at by l.
 * @return NULL, if op == 0; l->first, if op == 1.
 * Returning the list's first cell's (sentinel) address becomes convenient when swapping all the tasks between two different days.
 */
Cell* removeList(List* l, int op){
    Cell* remov = NULL;
    if(op){ remov = l->first; }
    else{
        Cell *tmp = l->first, *tmp2 = tmp->next;
        while(tmp != NULL){
            removeCell(tmp, op);
            tmp = tmp2;
            tmp2 = tmp->next;
        }
    }
    return remov;
}

/**
 * Deallocates a List's first valid cell (sentinel's "next" cell, or front cell) in memory or returns the first valid cell's task, depending on the operation code.
 * @param l a pointer to a List struct.
 * @param op an operation code. If 1 is passed, returns the front cell's task pointer (Task*).
 * If 0 is passed, deallocates the list's front cell in memory (and all it's dynamically allocated contents).
 * @return NULL, if op == 0 or the list has no cells/tasks; l->first->next->t, if op == 1.
 */
Task* removeFront(List *l, int op){ //idem
    Task *remov = NULL;
    if(l->n == 0){
        printf("There are no tasks!");
    }else{
        remov = removeCell(l->first->next, op);
        l->n--;
    }
    return remov;
}


/**
 * Deallocates a List's last cell in memory or returns the last cell's task, depending on the operation code.
 * @param l a pointer to a List struct.
 * @param op an operation code. If 1 is passed, returns the list's last cell's task pointer (Task*).
 * If 0 is passed, deallocates the list's last cell in memory (and all it's dynamically allocated contents).
 * @return NULL, if op == 0 or the list has no cells/tasks; l->last->t, if op == 1.
 */
Task* removeEnd(List *l, int op){ //idem
    Task *remov = NULL;
    if(l->n == 0){
        printf("There are no tasks!");
    }else{
        Cell *tmp = l->last;
        l->last = l->last->prev;
        remov = removeCell(tmp, op);
        l->n--;
    }
    return remov;
}

/**
 * Searches for a cell that contains a task with a certain name.
 * @param l a pointer to a List struct.
 * @param name the task's name.
 * @return the cell's address, if found. NULL, if not found.
 * This function is for internal use.
 */
Cell* searchForCell(List *l, char *name){
    Cell *c = NULL;
    for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
        if(strcmp(name, tmp->t->name) == 0){
            c = tmp;
            tmp = l->last;
        }
    }

    if(c == NULL){printf("Couldn't find the cell that contains this task!\n");}
    return c;
}

/**
 * Searches for a task with a certain name.
 * @param l a pointer to a List struct.
 * @param name the task's name.
 * @return the task's address, if found. NULL, if not found.
 */
Task* searchForTask(List *l, char *name){
    Task *t = NULL;
    for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
        if(strcmp(name, tmp->t->name) == 0){
            t = tmp->t;
            tmp = l->last;
        }
    }

    if(t == NULL){printf("Task not found!\n");}
    return t;
}

/**
 * Inserts a task in a list. The task's position is sorted according to its time data (especifically the fractionary starting and end times) in order
 * to improve the schedule's visualization.
 * If the time of the task to be inserted (Task *ta) conflicts with the time of a task already in the list, the task will not be inserted.
 * @param l a pointer to a List struct.
 * @param ta a pointer to a Task struct.
 * @param op an operation code. If 1, an "Added task" message, alongside with the task's name and time info, will be displayed.
 * If 0, nothing will be displayed.
 * @return 0, if the task has not been inserted; 1, if the task has been successfully inserted.
 */
int insertTask(List *l, Task *ta, int op){ //codigos: 0 -> nao inserido; 1 -> inserido
    int inserted = 0;
    if(ta != NULL){
        if(l->n == 0){
            Cell *c = createCell(ta);
            l->first->next = c;
            c->prev = l->first;
            l->last = c;
            if(op){printf("Added task:"); printTask(ta);}
            inserted = 1;
            l->n++;
        }else{
            Cell *tmp = l->first->next;    
            int i = 0;
            for(i; tmp != NULL && i < l->n; i++){
                Task *tb = tmp->t;
                if( (inserted = checkTime(ta, tb)) == 0){
                    printf("Invalid task time!\n");
                    tmp = NULL;
                }else if(inserted == -1){
                    Cell *c = createCell(ta);
                    c->next = tmp;
                    c->prev = tmp->prev;
                    tmp->prev->next = c;
                    tmp->prev = c;
                    if(op){printf("Added task:"); printTask(ta);}
                    inserted = 1;
                    l->n++;
                    tmp = NULL;
                }else{
                    tmp = tmp->next;
                }
            }

            if(i == l->n && inserted != 0){
                Cell *c = createCell(ta);
                c->prev = l->last;
                l->last = l->last->next = c;
                if(op){printf("Added task:"); printTask(ta);}
                inserted = 1;
                l->n++;
            }
        }
    }
    return inserted;
}

/**
 * Searches for and removes a cell that contains a certain task from a list, if the cell is found,
 * also deallocating the cell in memory (and all of it's dynamically allocated contents) or simply returning
 * the removed cell's task's address, depending on the operation code.
 * @param l a pointer to a List struct.
 * @param name the task's name.
 * @param op an operation code. If 1, returns the removed cell's task's address, if the cell is found.
 * If 0, deallocates the cell in memory.
 */
Task* removeTaskFromList(List *l, char *name, int op){ //ATENCAO: retorna null se nao encontrou a tarefa
    Task *t = NULL;
    Cell *c = NULL;
    if( (c = searchForCell(l, name)) != NULL){
        t = removeCell(c, op);
        l->n--;
    }
    return t;
}

/**
 * Prints all the tasks in a list. A list, in this schedule's structure, contains all the tasks of a single day.
 * @param l a pointer to a List struct.
 */
void printList(List *l){
    if(l->n == 0){
        printf("There are no tasks!\n");
    }else{
        printf("\nNumber of tasks on this day: %d", l->n);
        for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
            printTask(tmp->t);
        }
    }
}

#endif