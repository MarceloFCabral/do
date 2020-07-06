#include"tarefa.c"
#ifndef UTIL_C
#define UTIL_C

int checkTime(Tarefa *t1, Tarefa *t2){ //t1 = tarefa a ser inserida na lista. return 0 se horario de t1 ou t2 for invalido, 1 se for valido
    int res = 0;
    Horario *ho1 = t1->ho, *ho2 = t2->ho;
    if( (ho1->i_time > ho1->f_time)                                ||
        (ho1->i_time >= ho2->i_time && ho1->i_time < ho2->f_time)  ||
        (ho1->f_time > ho2->i_time  && ho1->f_time <= ho2->f_time) ||
        (ho1->i_time <= ho2->i_time && ho1->f_time >= ho2->f_time) ){ //tarefa em horario invalido;
        
            res = 0;

    }else if(ho1->i_time < ho2->i_time && ho1->f_time <= ho2->i_time){

            res = -1; //tarefa 1 com horario menor do que a tarefa 2;
    }else{
            res = 1; //tarefa 1 com horario maior do que a tarefa 2;
    }
    return res;
}

int checkTimeLista(Tarefa *t, Lista *l){ //verifica se uma tarefa e inserivel em uma determinada lista (dia)
    int res = 1, i = 0;
    Celula *tmp = l->primeiro->prox;
    for(tmp; tmp != NULL && ( (res = checkTime(t, tmp->t)) != 0 && res != -1); tmp = tmp->prox);
    return res; //se res != 0, e inserivel.
}

int* parseTime(char *time){
    int *res = NULL;
    if(strlen(time) >= 5){
        res = (int*) malloc(sizeof(int)*2);
        char str_h[3] = {'\0', '\0', '\0'};
        char str_m[3] = {'\0', '\0', '\0'};
        for(int i = 0; i < 2; i++){
            str_h[i] = time[i];
            str_m[i] = time[i+3];
        }
        res[0] = atoi(str_h);
        res[1] = atoi(str_m);
    }
    return res;
}

#endif