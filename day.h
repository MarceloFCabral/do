#include"list.c"

/*declaracao do enum e suas funcoes*/
enum DotW{Sun, Mon, Tue, Wed, Thu, Fri, Sat};

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
            break;
    }
    return name;
}

typedef struct Day{
    enum DotW d;
    List *l;
}Day;

Day createDay(enum DotW _d);
void printDay(Day Day);