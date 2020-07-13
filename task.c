/**
 * Defines all the functions listed in "task.h".
 * @author Marcelo F, Cabral (marcelofc12@gmail.com)
 */

#include"task.h"
#ifndef TASK_C
#define TASK_C

/**
 * Creates a Task struct by dynamically allocating memory for it.
 * @param _name a pointer to a character array that contains the task's name
 * @param _tt a pointer to a TaskTime struct.
 * @return a pointer to the newly allocated Task struct (Task*), if _tt is not NULL. Else, returns NULL.
 */
Task* createTask(char* _name, TaskTime *_tt){
    Task *ta = NULL;
    if(_tt != NULL){
        ta = (Task*) malloc(sizeof(Task));
        ta->name = _name;
        ta->tt = _tt;
    }
    return ta;
}

/**
 * Deallocates a Task struct in memory or simply returns a Task struct's address, depending on the operation code.
 * @param ta a pointer to a Task struct.
 * @param op an operation code. If 1 is passed, returns a pointer with the same value as ta. If 0 is passed, deallocates data pointed at by ta.
 * @return NULL, if op == 0; same value as ta, if op == 1.
 * Returning the same address as the one passed as an argument becomes convenient when swapping tasks between two different days or changing a task's day.
 */
Task* removeTask(Task *ta, int op){
    Task *remov = NULL;
    if(ta != NULL){
        if(op){ remov = ta; }
        else{
            free(ta->name); //deallocates the name string
            removeTaskTime(ta->tt, op); //deallocates the task time struct
            free(ta); //deallocates the pointers
        }
    }
    return remov;
}

/**
 * Prints a Task struct's name (name) and it's TaskTime struct's starting hour (b_h), starting minutes (b_m), ending hour (e_h) and ending minutes (e_m).
 * @param t a pointer to a Task struct (Task*).
 */
void printTask(Task *t){
    if(t != NULL){
        printf("\n\tName: %s", t->name);
        printTaskTime(t->tt);
    }
}

/**
 * Prints a Task struct's TaskTime info (starting hour (b_h), starting minutes (b_m), ending hour (e_h) and ending minutes (e_m)).
 * @param t a pointer to a Task struct (Task*).
 */
void printOnlyTaskTime(Task *t){
    if(t != NULL){
        printTaskTime(t->tt);
    }
}

#endif