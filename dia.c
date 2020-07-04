#include"dia.h"

Dia criarDia(enum Dds _d){
    Dia dia;
    dia.l = criarLista();
    dia.d = _d;
    return dia;
}

void printDia(Dia dia){
    printf("- %s - ", getNomeDia(dia.d));
    printLista(dia.l);
}