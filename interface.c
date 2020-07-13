/**
 * Defines all the functions listed in "interface.h".
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"interface.h"
#ifndef INTERFACE_C
#define INTERFACE_C

/**
 * Asks for and validates user input for a DotW enum.
 * @return a valid DotW enum value.
 */
int getDay(){
    int d = -1;
    while(d < 0 || d > 6){
        printf("Insert a number from 0 to 6 [0 = Sunday, 6 = Saturday]: ");
        scanf("%d", &d);
    }
    return d;
}

/**
 * Asks for user input for a task's name. Dynamically allocates memory for it.
 * @return a pointer to a string containing the task's name.
 */
char* getName(){
    getchar();
    char *str = (char*) malloc(sizeof(char)*101);
    printf("Insert a name with a maximum of 100 characters: ");
    fgets(str, 101, stdin);
    str[strlen(str)-1] = '\0';
    return str;
}

/**
 * Asks for user input for a task's starting and end time.
 * @param op an operation code. If 0, "Insert the starting time (hh:mm): " will be printed.
 * If 1, "Insert the end time (hh:mm): " will be printed instead.
 * @return a string containing the task's unparsed starting or end time.
 */
char* getTT(int op){
    getchar();
    char *str = (char*) malloc(sizeof(char)*6);
    !op ? printf("Insert the starting time (hh:mm): ") : printf("Insert the end time (hh:mm): ");
    fgets(str, 6, stdin);
    return str;
}

/**
 * Asks for user input to add a task to the schedule.
 * @param s a pointer to a Week struct.
 * @param op an operation code. If 0, "Insert the starting time (hh:mm): " will be printed.
 * If 1, "Insert the end time (hh:mm): " will be printed instead.
 */
void addTaskCase(Week *s, int op){
    char *name = getName();
    int day = getDay();
    char *ttB = getTT(0);
    char *ttE = getTT(1);
    addTask(s, ttE, ttB, name, day, op);
    free(ttB); free(ttE);
}

/**
 * Asks for user input to exclude a task from the schedule.
 * @param s a pointer to a Week struct.
 */
void excTaskCase(Week *s){
    char *name = getName();
    excTask(s, getDay(), name, 0);
    free(name);
}

/**
 * Asks for user input to get a task's name and day. Searches for the task by its name in the received day and prints the task's details, if found.
 * @param s a pointer to a Week struct.
 */
void prtTaskCase(Week *s){
    char *name = getName();
    prtTask(s, getDay(), name);
    free(name);
}

/**
 * Asks for user input to get a task's name. Then searches for the task by its name throughout the week and prints the task's details, if found.
 * @param s a pointer to a Week struct.
 */
void prtWeekTasksCase(Week *s){
    char *name = getName();
    prtTaskWeek(s, name);
    free(name);
}

/**
 * Asks for user input to get task 1's name and day. Repeats the process for task 2. Searches for both tasks and, if both are found, swaps their days.
 * @param s a pointer to a Week struct.
 */
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

/**
 * Asks for user input to get a task's name, source day and destination day. Then searches for the task and checks if the task is insertable in
 * the destination day. If the task is found and is insertable, changes the task's day.
 * @param s a pointer to a Week struct.
 */
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

#endif