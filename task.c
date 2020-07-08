#include"task.h"
#ifndef TAREFA_C
#define TAREFA_C

//ATENCAO: retorna NULL caso tt seja invalido
Task* createTask(char* _name, TaskTime *_tt){
    Task *ta = NULL;
    if(_tt != NULL){
        ta = (Task*) malloc(sizeof(Task));
        ta->name = _name;
        ta->tt = _tt;
    }
    return ta;
}

//ATENCAO: op == 0 -> desalocar tarefa; op != 0 -> retornar tarefa para uso posTueior
Task* removeTask(Task *ta, int op){
    Task *remov = NULL;
    if(ta != NULL){
        if(op){ remov = ta; }
        else{
            //free(ta->name); AVALIAR: se name for alocado dinamicamente, usar free. Caso contrario, nao usar.
            removeTaskTime(ta->tt, op);
            free(ta);
        }
    }
    return remov;
}

void printTask(Task *t){
    if(t != NULL){
        printf("\n\tname: %s", t->name);
        printTaskTime(t->tt);
    }
}

void printTaskTime(Task *t){
    if(t != NULL){
        printTaskTimeTime(t->tt);
    }
}

#endif