/**
 * Defines useful functions that perform tasks such as parsing strings and validating data.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"task.c"
#ifndef UTIL_C
#define UTIL_C

/**
 * Checks for conflict (overlapping) between two task's time information. Also checks if both tasks' starting time (b_time) are lesser than the end time (e_time).
 * @param t1 a pointer to a Task struct (if used inside a list insertion function, this should point to the task to be inserted)
 * @param t2 a pointer to a Task struct (if used inside a list insertion function, this should point to an already inserted task)
 * @return 0, if the tasks overlap eachother in time or have invalid starting and end times; 1 if t1 happens later; -1 if t1 happens earlier.
 */
int checkTime(Task *t1, Task *t2){
    int ans = 0;
    TaskTime *tt1 = t1->tt, *tt2 = t2->tt;
    if( (tt1->b_time > tt1->e_time || tt2->b_time > tt2->e_time)   ||
        (tt1->b_time >= tt2->b_time && tt1->b_time < tt2->e_time)  ||
        (tt1->e_time > tt2->b_time  && tt1->e_time <= tt2->e_time) ||
        (tt1->b_time <= tt2->b_time && tt1->e_time >= tt2->e_time) ){
        
            ans = 0;

    }else if(tt1->b_time < tt2->b_time && tt1->e_time <= tt2->b_time){

            ans = -1;
    }else{
            ans = 1;
    }
    return ans;
}

/**
 * Checks if a task is insertable in a certain list (Day).
 * @param t a pointer to a Task struct.
 * @param l a pointer to a List struct.
 * @return 0, if not insertable; != 0, if insertable.
 */
int checkTimeList(Task *t, List *l){ //verifica se uma tarefa e inserivel em uma deTueminada List (Day)
    int ans = 1, i = 0;
    Cell *tmp = l->first->next;
    for(tmp; tmp != NULL && ( (ans = checkTime(t, tmp->t)) != 0 && ans != -1); tmp = tmp->next);
    return ans;
}

/**
 * Parses a string in the hh:mm format into two integers (hours and minutes), if the passed string has a length equal to or greater than 5.
 * @param time a string in the hh:mm format.
 * @return a pointer to the parsed integers.
 */
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