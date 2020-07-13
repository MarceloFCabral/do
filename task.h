/**
 * Defines the Task struct and all the function headers related to it.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"tasktime.c"
#ifndef TASK_H
#define TASK_H

/**
 * struct Task: holds a task's name (name) and a pointer to a TaskTime struct (tt).
 */
typedef struct Task{
    char  *name;
    TaskTime *tt;
}Task;

Task* createTask(char *_name, TaskTime *_tt);
Task* removeTask(Task *ta, int op);
void printTask(Task *t);
void printTaskTime(TaskTime *t);

#endif