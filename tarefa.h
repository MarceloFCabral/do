#include"horario.c"
#ifndef TAREFA_H
#define TAREFA_H

typedef struct Tarefa{
    char  *nome;
    Horario *ho;
}Tarefa;

Tarefa* criarTarefa(char *_nome, Horario *_ho);
Tarefa* removerTarefa(Tarefa *ta, int op);
void printTarefa(Tarefa *t);
void printTarefaTime(Tarefa *t);

#endif