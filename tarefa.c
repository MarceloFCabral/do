#include"tarefa.h"
#ifndef TAREFA_C
#define TAREFA_C

//ATENCAO: retorna NULL caso horario seja invalido
Tarefa* criarTarefa(char* _nome, Horario *_ho){
    Tarefa *ta = NULL;
    if(_ho != NULL){
        ta = (Tarefa*) malloc(sizeof(Tarefa));
        ta->nome = _nome;
        ta->ho = _ho;
    }
    return ta;
}

//ATENCAO: op == 0 -> desalocar tarefa; op != 0 -> retornar tarefa para uso posterior
Tarefa* removerTarefa(Tarefa *ta, int op){
    Tarefa *remov = NULL;
    if(ta != NULL){
        if(op){ remov = ta; }
        else{
            //free(ta->nome); AVALIAR: se nome for alocado dinamicamente, usar free. Caso contrario, nao usar.
            removerHorario(ta->ho, op);
            free(ta);
        }
    }
    return remov;
}

void printTarefa(Tarefa *t){
    if(t != NULL){
        printf("\n\tNOME: %s", t->nome);
        printHorario(t->ho);
    }
}

void printTarefaTime(Tarefa *t){
    if(t != NULL){
        printHorarioTime(t->ho);
    }
}

#endif