#include"tasktime.c"
#ifndef TAREFA_H
#define TAREFA_H

typedef struct Task{
    char  *name;
    TaskTime *tt;
}Task;

Task* createTask(char *_name, TaskTime *_tt);
Task* removeTask(Task *ta, int op);
void printTask(Task *t);
void printTaskTime(TaskTime *t);

#endif