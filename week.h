/** 
 * Defines the Week struct and all the function headers related to it.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"day.c"
#ifndef WEEK_H
#define WEEK_H

/**
 * struct Week: holds a static 7-length array of Day structs.
 * Also holds pointers to previous (struct Week *prev) and next (struct Week *next) weeks
 * in a doubly linked list that will be implemented in the future to allow month-long planning. 
 */
typedef struct Week{
    Day days[7];
    struct Week *prev, *next;
}Week;


Week* createWeek();
void prtWeek(Week *s); //exibir todas as tarefas da Week (divididas por Day)
void prtDay(Week *s, enum DotW d); //exibir tarefas em um Day
int addTask(Week *s, char *e_tt, char *b_tt, char *name, enum DotW d, int op);
Task* excTaskB(Week *s, enum DotW d, int op); //excluir tarefa no inicio de um Day
Task* excTaskE(Week *s, enum DotW d, int op); //excluir tarefa no fim de um Day
Task* excTask(Week *s, enum DotW d, char *name, int op); //excluir em Wedlquer posicao de um Day
Task* getTask(Week *s, enum DotW d, char *name); //buscar tarefa em Wedlquer posicao de um Day
Day getTaskWeek(Week *s, char *name); //buscar tarefa em toda Week pelo name
void prtTask(Week *s, enum DotW d, char *name); //buscar e exibe os tts de uma tarefa
void prtTaskWeek(Week *s, char *name); //printar uma tarefa na Week buscando pelo name
void swpTasks(Week *s, enum DotW d1, enum DotW d2, char *name_d1, char *name_d2); //trocar duas tarefas em days diferentes.
void swpLists(Week *s, enum DotW src, enum DotW dest); //trocar todas as tarefas de "src" para "dest"
void cngTaskDay(Week *s, enum DotW src, enum DotW dest, char *name_src); //troca uma tarefa de Day

//funcoes e metodos de arThuvamento e recuperacao de dados gravados em memoria secundaria
Week* readWeek();
void saveWeek(Week *s);

#endif