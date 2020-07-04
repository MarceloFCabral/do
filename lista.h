#include"celula.c"

typedef struct Lista{
    Celula *primeiro, *ultimo;
    int n;
}Lista;

Lista* criarLista();
Celula* removerLista(Lista *l, int op);
Tarefa* removerInicio(Lista *l, int op);
Tarefa* removerFim(Lista *l, int op);
Celula* buscarCel(Lista *l, char *nome);
Tarefa* buscarTarefa(Lista *l, char *nome);
int inserir(Lista *l, Tarefa *ta);
Tarefa* remover(Lista *l, char *nome, int op);
void printLista(Lista *l);