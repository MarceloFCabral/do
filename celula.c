#include"celula.h"

Celula* criarCelula(Tarefa *ta){
    Celula *newCel = NULL;
    newCel = (Celula*) malloc(sizeof(Celula));
    newCel->t = ta;
    newCel->ant = newCel->prox = NULL;
    return newCel;
}

Tarefa* removerCelula(Celula *c, int op){ //0 -> desalocar tarefa; op != 0 -> retornar tarefa para uso posterior
    Tarefa *remov = NULL;
    if(c != NULL){
        if(c->ant != NULL){c->ant->prox = c->prox;}
        if(c->prox != NULL){c->prox->ant = c->ant;}
        c->ant = c->prox = NULL;
        printf("Tarefa removida:");
        printTarefa(c->t);
        remov = removerTarefa(c->t, op);
        free(c);
    }
    return remov;
}