#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#ifndef HORARIO_H
#define HORARIO_H

typedef struct TaskTime{
    unsigned int b_h, e_h, b_m, e_m;
    float b_time, e_time;
}TaskTime;

TaskTime* createTaskTime(unsigned int _b_h, unsigned int _b_m, unsigned int _e_h, unsigned int _e_m);
TaskTime* removeTaskTime(TaskTime* tt, int op);
void printTaskTime(TaskTime *tt);
void printTaskTimeTime(TaskTime *tt);

#endif