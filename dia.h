#include"lista.c"

/*declaracao do enum e suas funcoes*/
enum Dds{Dom, Seg, Ter, Qua, Qui, Sex, Sab};

char* getNomeDia(enum Dds d){
    char *nome = (char*) malloc(sizeof(char)*4);
    switch(d){
        case Dom:
            strcpy(nome, "Dom");
            break;
        case Seg:
            strcpy(nome, "Seg");
            break;
        case Ter:
            strcpy(nome, "Ter");
            break;
        case Qua:
            strcpy(nome, "Qua");
            break;
        case Qui:
            strcpy(nome, "Qui");
            break;
        case Sex:
            strcpy(nome, "Sex");
            break;
        case Sab:
            strcpy(nome, "Sab");
            break;
        default:
            printf("Dia invalido!\n");
            break;
    }
    return nome;
}

typedef struct Dia{
    enum Dds d;
    Lista *l;
}Dia;

Dia criarDia(enum Dds _d);
void printDia(Dia dia);