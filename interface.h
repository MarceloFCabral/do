/**
 * Declares all the headers for functions related to user interaction (through the command line).
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"week.c"
#ifndef INTERFACE_H
#define INTERFACE_H

int getDay();
char* getName();
char* getTT();
void addTaskCase(Week *w, int op);
void excTaskCase(Week *w);
void prtTaskCase(Week *w);
void prtWeekTasksCase(Week *w);
void swpTasksCase(Week *w);
void cngTaskDayCase(Week *w);

#endif