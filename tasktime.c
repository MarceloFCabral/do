#include"tasktime.h"
#ifndef HORARIO_C
#define HORARIO_C

TaskTime* createTaskTime(unsigned int _b_h, unsigned int _b_m, unsigned int _e_h, unsigned int _e_m){
    TaskTime *tt = NULL;
    if( (_b_h > 23 || _e_h > 23 || _b_m > 59 || _e_m > 59) ){ //se ttra/minutos possuem valores invalidos
        printf("Erro! TaskTime invalido.\n");
    }else{
        tt = (TaskTime*) malloc(sizeof(TaskTime));
        tt->b_h = _b_h;
        tt->b_m = _b_m;
        tt->e_h = _e_h;
        tt->e_m = _e_m;
        tt->b_time = (float)_b_h + (float)_b_m / 60;
        tt->e_time = (float)_e_h + (float)_e_m / 60;
    }
    return tt;
}

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

void printTaskTime(TaskTime *tt){
    printf("\n\tTASK TIME: %02d:%02d to %02d:%02d\n", tt->b_h, tt->b_m, tt->e_h, tt->e_m);
}

void printTaskTimeTime(TaskTime *tt){
    printf("\nFractionary task time:\n\tInicio: %f\n\tFim: %f\n", tt->b_time, tt->e_time);
}

#endif