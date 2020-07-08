#include"task.c"
#ifndef UTIL_C
#define UTIL_C

int checkTime(Task *t1, Task *t2){ //t1 = tarefa a ser inserida na List. return 0 se tt de t1 ou t2 for invalido, 1 se for valido
    int ans = 0;
    TaskTime *tt1 = t1->tt, *tt2 = t2->tt;
    if( (tt1->b_time > tt1->e_time)                                ||
        (tt1->b_time >= tt2->b_time && tt1->b_time < tt2->e_time)  ||
        (tt1->e_time > tt2->b_time  && tt1->e_time <= tt2->e_time) ||
        (tt1->b_time <= tt2->b_time && tt1->e_time >= tt2->e_time) ){ //tarefa em tt invalido;
        
            ans = 0;

    }else if(tt1->b_time < tt2->b_time && tt1->e_time <= tt2->b_time){

            ans = -1; //tarefa 1 com tt menor do que a tarefa 2;
    }else{
            ans = 1; //tarefa 1 com tt maior do que a tarefa 2;
    }
    return ans;
}

int checkTimeList(Task *t, List *l){ //verifica se uma tarefa e inserivel em uma deTueminada List (Day)
    int ans = 1, i = 0;
    Cell *tmp = l->first->next;
    for(tmp; tmp != NULL && ( (ans = checkTime(t, tmp->t)) != 0 && ans != -1); tmp = tmp->next);
    return ans; //se ans != 0, e inserivel.
}

int* parseTime(char *time){
    int *ans = NULL;
    if(strlen(time) >= 5){
        ans = (int*) malloc(sizeof(int)*2);
        char str_h[3] = {'\0', '\0', '\0'};
        char str_m[3] = {'\0', '\0', '\0'};
        for(int i = 0; i < 2; i++){
            str_h[i] = time[i];
            str_m[i] = time[i+3];
        }
        ans[0] = atoi(str_h);
        ans[1] = atoi(str_m);
    }
    return ans;
}

#endif