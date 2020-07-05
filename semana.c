#include"semana.h"

Semana* criarSemana(){
    Semana *s = malloc(sizeof(Semana));
    s->ant = s->prox = NULL;
    for(int i = Dom; i <= Sab; i++){
        s->dias[i] = criarDia(i);
    }
    return s;
}

void prtSemana(Semana *s){
    printf("=== Semana ===\n");
    for(int i = Dom; i <= Sab; i++){
        printDia(s->dias[i]);
        printf("\n");
    }
}

void prtDia(Semana *s, enum Dds d){
    printDia(s->dias[d]);
}

int addTarefa(Semana *s, char *horario_f, char *horario_i, char *nome, enum Dds d){
    int inserido = 0;
    int *hi = parseTime(horario_i);
    int *hf = parseTime(horario_f);
    if(hi != NULL && hf != NULL){
        printf("--> Em %s:\n", getNomeDia(d));
        inserido = inserir(s->dias[d].l, criarTarefa(nome, criarHorario(hi[0], hi[1], hf[0], hf[1])));
    }else{
        printf("Horario inserido e invalido!\n");
    }
    return inserido;
}

Tarefa* excTarefaI(Semana *s, enum Dds d, int op){
    printf("--> Em %s:\n", getNomeDia(d));
    return removerInicio(s->dias[d].l, op);
}

Tarefa* excTarefaF(Semana *s, enum Dds d, int op){
    printf("--> Em %s:\n", getNomeDia(d));
    return removerFim(s->dias[d].l, op);
}

Tarefa* excTarefa(Semana *s, enum Dds d, char *nome, int op){
    printf("--> Em %s:\n", getNomeDia(d));
    return remover(s->dias[d].l, nome, op);
}

Tarefa* bscTarefa(Semana *s, enum Dds d, char *nome){
    return buscarTarefa(s->dias[d].l, nome);
}

Dia bscTarefaSemana(Semana *s, char *nome){ //ATENCAO: diferente das outras funcoes de busca, esta funcao retorna o DIA, e nao a tarefa.
    Dia dia = {0, NULL}; //o enum é válido, portanto é NECESSÁRIO checar se dia->l != NULL
    int i = Dom;
    for(i; (i <= Sab) && (buscarTarefa(s->dias[i].l, nome) == NULL); i++);
    if(i <= 6){dia = s->dias[i];}
    return dia;
}

void prtTarefa(Semana *s, enum Dds d, char *nome){
    printf("--> Em %s:", getNomeDia(d));
    printTarefa(bscTarefa(s, d, nome));
}

void prtTarefaSemana(Semana *s, char *nome){
    Dia dia = bscTarefaSemana(s, nome);
    if(dia.l != NULL){
        printf("--> Em %s:", getNomeDia(dia.d));
        printTarefa(bscTarefa(s, dia.d, nome));
    }else{
        printf("Tarefa nao encontrada na semana!\n");
    }
}

void trcTarefa(Semana *s, enum Dds d1, enum Dds d2, char *nome_d1, char *nome_d2){
    Celula *c1 = buscarCel(s->dias[d1].l, nome_d1);
    Celula *c2 = buscarCel(s->dias[d2].l, nome_d2);
    if(c1 != NULL && c2 != NULL){
        Tarefa *tmp = c1->t;
        c1->t = c2->t;
        c2->t = tmp;
    }else{
        printf("Nao foi possivel trocar!\n");
    }
}

void trcLista(Semana *s, enum Dds d1, enum Dds d2){
    Lista *tmp = s->dias[d1].l;
    s->dias[d1].l = s->dias[d2].l;
    s->dias[d2].l = tmp;
}

void trcTarefaDia(Semana *s, enum Dds src, enum Dds dest, char *nome_src){
    inserir(s->dias[dest].l, remover(s->dias[src].l, nome_src, 1));
}