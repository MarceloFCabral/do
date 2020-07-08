#include"day.h"

Day createDay(enum DotW _d){
    Day day;
    day.l = createList();
    day.d = _d;
    return day;
}

void printDay(Day day){
    printf("- %s - ", getDayName(day.d));
    printList(day.l);
}