/**
 * Defines all the functions listed in "day.h".
 * @author Marcelo F, Cabral (marcelofc12@gmail.com)
 */

#include"day.h"
#ifndef DAY_C
#define DAY_C

/**
 * Creates a Day struct by statically allocating memory for it.
 * The choice for static allocation here is due to the fact that days of the week are an immutable set of elements
 * that will be present until the end of the program's execution.
 * @param _d a valid DotW enum.
 * @return a Day struct.
 */
Day createDay(enum DotW _d){
    Day day;
    day.l = createList();
    day.d = _d;
    return day;
}

/**
 * Prints all the tasks of a certain day.
 * @param day a Day struct.
 */
void printDay(Day day){
    printf("- %s - ", getDayName(day.d));
    printList(day.l);
}

#endif