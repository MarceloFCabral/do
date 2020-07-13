/**
 * Defines the Day of the Week (DotW) enum. 
 * Defines the Day struct and all the function headers related to it.
 * @author Marcelo F. Cabral (marcelofc12@gmail.com)
 */

#include"list.c"
#ifndef DAY_H
#define DAY_H

/**
 * enum DotW: facilitates the comprehension of code when referring to numeric values associated to days of the week.
 * 0 is Sunday, 1 is Monday, ... , 6 is Saturday.
 */
enum DotW{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

/**
 * Translates a valid enum DotW into a string.
 * @param d an integer, ideally inside the interval [0, 6],
 * @return the corresponding day of the week's name string.
 */
char* getDayName(enum DotW d){
    char *name = (char*) malloc(sizeof(char)*4);
    switch(d){
        case Sun:
            strcpy(name, "Sun");
            break;
        case Mon:
            strcpy(name, "Mon");
            break;
        case Tue:
            strcpy(name, "Tue");
            break;
        case Wed:
            strcpy(name, "Wed");
            break;
        case Thu:
            strcpy(name, "Thu");
            break;
        case Fri:
            strcpy(name, "Fri");
            break;
        case Sat:
            strcpy(name, "Sat");
            break;
        default:
            printf("Invalid day!\n");
            free(name);
            break;
    }
    return name;
}

/**
 * struct Day: holds a DotW enum that represents which day of the week the current struct is associated to,
 * aswell as a pointer to a List struct.
 */
typedef struct Day{
    enum DotW d;
    List *l;
}Day;

Day createDay(enum DotW _d);
void printDay(Day Day);

#endif