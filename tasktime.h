/**
 * Defines the TaskTime struct and all the function headers related to it.
 * Includes native C libraries dependencies.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#ifndef TASKTIME_H
#define TASKTIME_H

/**
 * struct TaskTime: holds a task's starting hour (b_h), ending hour (e_h), starting minutes (b_m) and
 * ending minutes (e_m).
 * Also holds the starting and ending time as two float variables that facilitate time validation and comparison
 * by storing minutes as a fraction of an hour:
 * b_time = starting hour + starting minutes / 60.
 * e_time = ending hour + ending minutes / 60.
 */
typedef struct TaskTime{
    unsigned int b_h, e_h, b_m, e_m;
    float b_time, e_time;
}TaskTime;

TaskTime* createTaskTime(unsigned int _b_h, unsigned int _b_m, unsigned int _e_h, unsigned int _e_m);
TaskTime* removeTaskTime(TaskTime* tt, int op);
void printTaskTime(TaskTime *tt);
void printTaskTimeTime(TaskTime *tt);

#endif