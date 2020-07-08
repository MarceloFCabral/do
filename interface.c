#include"interface.h"

int getDay(){
    int d = -1;
    while(d < 0 || d > 6){
        printf("Insert a number from 0 to 6 [0 = Sunday, 6 = Saturday]: ");
        scanf("%d", &d);
    }
    return d;
}

char* getName(){
    getchar();
    char *str = (char*) malloc(sizeof(char)*101);
    printf("Insert a name with a maximum of 100 characters: ");
    fgets(str, 101, stdin);
    str[strlen(str)-1] = '\0';
    return str;
}

char* getTT(int op){
    getchar();
    char *str = (char*) malloc(sizeof(char)*6);
    !op ? printf("Insert the starting time: ") : printf("Insert the end time: ");
    fgets(str, 6, stdin);
}

void addTaskCase(Week *s, int op){
    char *name = getName();
    int Day = getDay();
    char *ttI = getTT(0);
    char *ttF = getTT(1);
    addTask(s, ttF, ttI, name, Day, op);
    free(ttI); free(ttF);
}

void excTaskCase(Week *s){
    char *name = getName();
    excTask(s, getDay(), name, 0);
    free(name);
}

void prtTaskCase(Week *s){
    char *name = getName();
    prtTask(s, getDay(), name);
    free(name);
}

void prtWeekTasksCase(Week *s){
    char *name = getName();
    prtTaskWeek(s, name);
    free(name);
}

void swpTasksCase(Week *s){
    printf("First task:\n");
    int d1 = getDay();
    char *name_d1 = getName();
    printf("Second task\n");
    int d2 = getDay();
    char *name_d2 = getName();
    swpTasks(s, d1, d2, name_d1, name_d2);
    free(name_d1); free(name_d2);
}

void cngTaskDayCase(Week *s){
    Task *t = NULL;
    char *name = getName();
    printf("Insert the day that contains the task:\n");
    int src = getDay();
    printf("Insert the day of destination:\n");
    int dest = getDay();
    if( (t = getTask(s, src, name)) != NULL && checkTimeList(t, s->days[dest].l) ){
        cngTaskDay(s, src, dest, name);
    }else{
        printf("Couldn't change the task's day! Conflicting task times or unexistent task.\n");
    }
    free(name);
    getchar();
}