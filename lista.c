#include"lista.h"
#include"util.c"

Lista* criarLista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->primeiro = l->ultimo = criarCelula(NULL);
    l->n = 0;
    return l;
}

Celula* removerLista(Lista* l, int op){ //op == 0 -> desalocar lista; op != 0 -> retornar lista para uso posterior
    Celula* remov = NULL;
    if(op){ remov = l->primeiro; }
    else{
        Celula *tmp = l->primeiro->prox, *tmp2 = NULL;
        while(tmp != l->ultimo){
            tmp2 = tmp->prox;
            removerCelula(tmp, op);
            tmp = tmp2;
        }
    }
    return remov;
}

Tarefa* removerInicio(Lista *l, int op){ //idem
    Tarefa *remov = NULL;
    if(l->n == 0){
        printf("Nao ha tarefas!");
    }else{
        remov = removerCelula(l->primeiro->prox, op);
        l->n--;
    }
    return remov;
}

Tarefa* removerFim(Lista *l, int op){ //idem
    Tarefa *remov = NULL;
    if(l->n == 0){
        printf("Nao ha tarefas!");
    }else{
        Celula *tmp = l->ultimo;
        l->ultimo = l->ultimo->ant;
        remov = removerCelula(tmp, op);
        l->n--;
    }
    return remov;
}

Celula* buscarCel(Lista *l, char *nome){
    Celula *c = NULL;
    for(Celula *tmp = l->primeiro->prox; tmp != NULL; tmp = tmp->prox){
        if(strcmp(nome, tmp->t->nome) == 0){
            c = tmp;
            tmp = l->ultimo;
        }
    }

    if(c == NULL){printf("Celula que contem esta tarefa nao encontrada!\n");}
    return c;
}

Tarefa* buscarTarefa(Lista *l, char *nome){
    Tarefa *t = NULL;
    for(Celula *tmp = l->primeiro->prox; tmp != NULL; tmp = tmp->prox){
        if(strcmp(nome, tmp->t->nome) == 0){
            t = tmp->t;
            tmp = l->ultimo;
        }
    }

    if(t == NULL){printf("Tarefa nao encontrada!\n");}
    return t;
}

int inserir(Lista *l, Tarefa *ta, int op){ //codigos: 0 -> nao inserido; 1 -> inserido
    int inserido = 0;
    if(ta != NULL){
        if(l->n == 0){
            Celula *c = criarCelula(ta);
            l->primeiro->prox = c;
            c->ant = l->primeiro;
            l->ultimo = c;
            if(op){printf("Tarefa inserida:"); printTarefa(ta);}
            inserido = 1;
            l->n++;
        }else{
            Celula *tmp = l->primeiro->prox;    
            int i = 0;
            for(i; tmp != NULL && i < l->n; i++){
                Tarefa *tb = tmp->t;
                if( (inserido = checkTime(ta, tb)) == 0){
                    printf("Horario invalido!\n");
                    tmp = NULL;
                }else if(inserido == -1){
                    Celula *c = criarCelula(ta);
                    c->prox = tmp;
                    c->ant = tmp->ant;
                    tmp->ant->prox = c;
                    tmp->ant = c;
                    if(op){printf("Tarefa inserida:"); printTarefa(ta);}
                    inserido = 1;
                    l->n++;
                    tmp = NULL;
                }else{
                    tmp = tmp->prox;
                }
            }

            if(i == l->n && inserido != 0){
                Celula *c = criarCelula(ta);
                c->ant = l->ultimo;
                l->ultimo = l->ultimo->prox = c;
                if(op){printf("Tarefa inserida:"); printTarefa(ta);}
                inserido = 1;
                l->n++;
            }
        }
    }
    return inserido;
}

Tarefa* remover(Lista *l, char *nome, int op){ //ATENCAO: retorna null se nao encontrou a tarefa
    Tarefa *t = NULL;
    Celula *c = NULL;
    if( (c = buscarCel(l, nome)) != NULL){
        t = removerCelula(c, op);
        l->n--;
    }
    return t;
}

void printLista(Lista *l){
    if(l->n == 0){
        printf("Nao ha tarefas.\n");
    }else{
        printf("\nNumero de tarefas: %d", l->n);
        for(Celula *tmp = l->primeiro->prox; tmp != NULL; tmp = tmp->prox){
            printTarefa(tmp->t);
        }
    }
}

