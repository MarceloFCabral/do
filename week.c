/**
 * Defines all the functions listed in "week.h".
 * @author Marcelo F, Cabral (marcelofc12@gmail.com)
 */

#include"week.h"
#ifndef WEEK_C
#define WEEK_C

/**
 * Creates a Week struct by dynamically allocating memory for it.
 * @return a pointer to the newly allocated Week struct (Week*).
 */
Week* createWeek(){
    Week *s = (Week*) malloc(sizeof(Week));
    s->prev = s->next = NULL;
    for(int i = Sun; i <= Sat; i++){
        s->days[i] = createDay(i);
    }
    return s;
}

/**
 * Prints all the tasks in a week, separated by day.
 * @param s a pointer to a Week struct.
 */
void prtWeek(Week *s){
    printf("=== Week ===\n");
    for(int i = Sun; i <= Sat; i++){
        printDay(s->days[i]);
        printf("\n");
    }
}

/**
 * Prints all the tasks in a certain day of the week.
 * @param s a pointer to a week struct.
 * @param d a valid DotW enum (an integer in the range [0, 6]).
 */
void prtDay(Week *s, enum DotW d){
    printDay(s->days[d]);
}

/**
 * Adds a task to a certain day of the week.
 * @param s a pointer to a Week struct.
 * @param e_tt_str a pointer to the string containing the task's unparsed end time.
 * @param b_tt_str a pointer to the string containing the task's unparsed starting time.
 * @param name a pointer to the string containing the task's name.
 * @param d a valid DotW enum that represents the day of the week to which the task will be added.
 * @param op an operation code. If 1, an "Added task" message, alongside with the task's name and time info, will be displayed.
 * If 0, nothing will be displayed.
 * @return 0, if the task has not been added; 1, if the task has been successfully added.
 */
int addTask(Week *s, char *e_tt_str, char *b_tt_str, char *name, enum DotW d, int op){ // op == 1 -> insercao de novo dado, op == 0 -> carregamento
    int inserted = 0;
    int *b_tt = parseTime(b_tt_str);
    int *e_tt = parseTime(e_tt_str);
    if(b_tt != NULL && e_tt != NULL){
        if(op){printf("--> On %s:\n", getDayName(d));}
        inserted = insertTask(s->days[d].l, createTask(name, createTaskTime(b_tt[0], b_tt[1], e_tt[0], e_tt[1])), op);
    }else{
        printf("Invalid task time!\n");
    }
    return inserted;
}

/**
 * Excludes the first task of a day.
 * @param s a pointer to a Week struct.
 * @param d a valid DotW enum that represents the day of the week from which the task will be removed.
 * @param op an operation code. If 1, returns the removed task.
 * If 0, returns NULL.
 * @return if op == 1, a pointer to the removed Task struct (Task*); if op == 0, NULL.
 */
Task* excTaskB(Week *s, enum DotW d, int op){
    printf("--> On %s:\n", getDayName(d));
    return removeFront(s->days[d].l, op);
}

/**
 * Excludes the last task of a day.
 * @param s a pointer to a Week struct.
 * @param d a valid DotW enum that represents the day of the week from which the task will be removed.
 * @param op an operation code. If 1, returns the removed task.
 * If 0, deallocates cell and task data and returns NULL.
 * @return if op == 1, a pointer to the removed Task struct (Task*); if op == 0, NULL.
 */
Task* excTaskE(Week *s, enum DotW d, int op){
    printf("--> On %s:\n", getDayName(d));
    return removeEnd(s->days[d].l, op);
}

/**
 * Excludes any task of a day.
 * @param s a pointer to a Week struct.
 * @param d a valid DotW enum that represents the day of the week from which the task will be removed.
 * @param name a pointer to the string containing the task's name.
 * @param op an operation code. If 1, returns the removed task.
 * If 0, deallocates cell and task data and returns NULL.
 * @return if op == 1, a pointer to the removed Task struct (Task*); if op == 0, NULL.
 */
Task* excTask(Week *s, enum DotW d, char *name, int op){
    printf("--> On %s:\n", getDayName(d));
    return removeTaskFromList(s->days[d].l, name, op);
}

/**
 * Returns a certain task of a day, if found. Internal use.
 * @param s a pointer to a Week struct.
 * @param d a valid DotW enum that represents the day of the week to which the task has been added.
 * @param name a pointer to the string containing the task's name.
 * @return a pointer to the Task struct (Task*), if found. If not, returns NULL.
 */
Task* getTask(Week *s, enum DotW d, char *name){ //uso inTueno
    return searchForTask(s->days[d].l, name);
}

/**
 * Searches for a task by its name throughout the week and returns the Day struct that contains it, if found.
 * @param s a pointer to a Week struct.
 * @param name a pointer to the string containing the task's name.
 * IMPORTANT: since the returned Day struct contains a valid enum (Sun), it is necessary to check the List pointer's value (List *l) in order to
 * verify if the returned Day is valid.
 * @return a Day struct. If the task has been found in a certain day, day->l != NULL. If not, day->l == NULL.
 */
Day getTaskWeek(Week *s, char *name){
    Day day = {Sun, NULL};
    int i = Sun;
    for(i; (i <= Sat) && (searchForTask(s->days[i].l, name) == NULL); i++);
    if(i <= 6){day = s->days[i];}
    return day;
}

/**
 * Searches for a task by its name in a certain day and prints its details, if found.
 * @param s a pointer to a Week struct.
 * @param d a valid DotW enum that represents the day of the week to which the task has been added.
 */
void prtTask(Week *s, enum DotW d, char *name){
    printf("--> On %s:", getDayName(d));
    printTask(getTask(s, d, name));
}

/**
 * Searches for a task by its name throughout the week and prints its details, if found.
 * @param s a pointer to a Week struct.
 * @param name a pointer to the string containing the task's name.
 */
void prtTaskWeek(Week *s, char *name){
    Day day = getTaskWeek(s, name);
    if(day.l != NULL){
        printf("--> On %s:", getDayName(day.d));
        printTask(getTask(s, day.d, name));
    }else{
        printf("Task not found!\n");
    }
}

/**
 * Searches for task 1 by its name in day 1, then searches for task 2 by its name in day 2.
 * If both tasks are found, swaps the tasks' days.
 * @param s a pointer to a Week struct.
 * @param d1 a valid DotW enum that represents the day of the week to which task 1 has been added.
 * @param d2 a valid DotW enum that represents the day of the week to which task 2 has been added.
 * @param name_d1 a pointer to the string containing task 1's name.
 * @param name_d2 a pointer to the string containing task 2's name.
 */
void swpTasks(Week *s, enum DotW d1, enum DotW d2, char *name_d1, char *name_d2){
    Cell *c1 = searchForCell(s->days[d1].l, name_d1);
    Cell *c2 = searchForCell(s->days[d2].l, name_d2);
    if(c1 != NULL && c2 != NULL){
        Task *tmp = c1->t;
        c1->t = c2->t;
        c2->t = tmp;
        printf("Tasks swapped!\n");
    }else{
        printf("Error: couldn't swap tasks.\n");
    }
}

/**
 * Swaps all the tasks between two different days.
 * @param s a pointer to a Week struct.
 * @param d1 a valid DotW enum that represents a day of the week.
 * @param d2 a valid DotW enum that represents a day of the week.
 */
void swpLists(Week *s, enum DotW d1, enum DotW d2){
    List *tmp = s->days[d1].l;
    s->days[d1].l = s->days[d2].l;
    s->days[d2].l = tmp;
    printf("Tasks swapped!\n");
}

/**
 * Changes a task's day (removes it from day 1 and adds it to day 2).
 * @param s a pointer to a Week struct.
 * @param src the day that contains the task.
 * @param dest the day that will receive the task.
 * @param name_src the name of the task.
 */
void cngTaskDay(Week *s, enum DotW src, enum DotW dest, char *name_src){
    insertTask(s->days[dest].l, removeTaskFromList(s->days[src].l, name_src, 1), 0) ? printf("Task day changed.\n") : printf("Error: couldn't swap task day\n");
}

//The functions below are responsible for saving and loading a week's data to and from secondary memory.

/**
 * Loads the schedule's week data from secondary memory.
 * IMPORTANT: The data is stored in the "week.txt" file inside the program's folder. If the file is not found, the program
 * will create a new one.
 */
Week* readWeek(){
    FILE *f = fopen("week.txt", "r");
    Week *w = createWeek();
    if(f == NULL){
        printf("Couldn't load a week file. Creating new week file\n");
    }else{
        int day = 0;
        fscanf(f, "%d", &day);
        while(day != -1){
            int n_tasks = 0;
            fscanf(f, "%d", &n_tasks);
            for(int i = 0; i < n_tasks; i++){
                char *name = (char*) malloc(sizeof(char)*101);
                char buf[2]; char b_tt[6]; char e_tt[6];
                
                fgets(buf, 2, f); //discard newline character from previous line

                fgets(name, 101, f);
                name[strlen(name)-1] = '\0';
                fscanf(f, "%s %s", b_tt, e_tt);
                addTask(w, e_tt, b_tt, name, day, 0);
            }
            fscanf(f, "%d", &day);
        }
        printf("Week file loaded!\n");
        fclose(f);
    }
    return w;
}

/**
 * Saves the schedule's data to secondary memory.
 * IMPORTANT: Creates or modifies a "week.txt" file inside the program's folder.
 */
void saveWeek(Week *w){
    printf("Saving changes...\n");
    FILE *f = fopen("week.txt", "w");
    for(int i = Sun; i <= Sat; i++){
        List *l = w->days[i].l;
        fprintf(f, "%d\n", i);
        fprintf(f, "%d\n", l->n);
        for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
            fprintf(f, "%s\n", tmp->t->name);
            fprintf(f, "%02d:%02d\n", tmp->t->tt->b_h, tmp->t->tt->b_m);
            fprintf(f, "%02d:%02d\n", tmp->t->tt->e_h, tmp->t->tt->e_m);
        }
    }
    fprintf(f, "%d", -1);
    fclose(f);
}

#endif