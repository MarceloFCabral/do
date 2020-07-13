/**
 * Defines all the functions listed in "tasktime.h".
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"tasktime.h"
#ifndef TASKTIME_C
#define TASKTIME_C

/**
 * Creates a TaskTime struct by dynamically allocating memory for it.
 * @param _b_h an unsigned integer that represents the stating hour.
 * @param _b_m an unsigned integer that represents the starting minutes.
 * @param _e_h an unsigned integer that represents the ending hour.
 * @param _e_m an unsigned integer that represents the ending minutes.
 * @return a pointer to the newly allocated TaskTime struct (TaskTime*), if the arguments are valid values.
 */
TaskTime* createTaskTime(unsigned int _b_h, unsigned int _b_m, unsigned int _e_h, unsigned int _e_m){
    TaskTime *tt = NULL;
    /*
    if a value that represents an hour is greater than 23 or a value that represents minutes is greater than 59,
    this value is not valid, and thus the task time isn't valid either.
    */
    if( (_b_h > 23 || _e_h > 23 || _b_m > 59 || _e_m > 59) ){
        printf("Invalid task time!\n");
    }else{
        tt = (TaskTime*) malloc(sizeof(TaskTime));
        tt->b_h = _b_h;
        tt->b_m = _b_m;
        tt->e_h = _e_h;
        tt->e_m = _e_m;
        tt->b_time = (float)_b_h + (float)_b_m / 60;
        tt->e_time = (float)_e_h + (float)_e_m / 60;
    }
    return tt; //returns NULL if any of the passed arguments are not valid.
}

/**
 * Deallocates a TaskTime struct in memory or simply returns a TaskTime struct's address, depending on the operation code.
 * @param tt a pointer to a TaskTime struct (TaskTime*).
 * @param op an operation code. If 1 is passed, returns a pointer with the same value as tt. If 0 is passed, deallocates data pointed at by tt.
 * @return NULL, if op == 0; same value as tt, if op == 1.
 * Returning the same address as the one passed as an argument becomes convenient when swapping tasks between two different days or changing a task's day.
 */
TaskTime* removeTaskTime(TaskTime* tt, int op){
    TaskTime *remov = NULL;
    if(tt != NULL){
        if(op){ remov = tt; }
        else{
            free(tt);
        }
    }
    return remov;
}

/**
 * Prints a TaskTime struct's starting hour (b_h), starting minutes (b_m), ending hour (e_h) and ending minutes (e_m).
 * @param tt a pointer to a TaskTime struct (TaskTime*).
 */
void printTaskTime(TaskTime *tt){
    printf("\n\tTASK TIME: %02d:%02d to %02d:%02d\n", tt->b_h, tt->b_m, tt->e_h, tt->e_m);
}

/**
 * Prints a TaskTime struct's starting fractionary time (b_time) and fractionary ending time (e_time).
 * @param tt a pointer to a TaskTime struct (TaskTime*).
 */
void printFTaskTime(TaskTime *tt){
    printf("\nFractionary task time:\n\tInicio: %f\n\tFim: %f\n", tt->b_time, tt->e_time);
}

#endif