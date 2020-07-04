#include"tarefa.c"

typedef struct Celula{
    Tarefa *t;
    struct Celula *ant, *prox;
}Celula;

Celula* criarCelula(Tarefa *ta);
Tarefa* removerCelula(Celula *c, int op);
