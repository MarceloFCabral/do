#include"dia.c"

typedef struct Semana{
    Dia dias[7];
    struct Semana *ant, *prox; //ponteiros serao usados em atualizacao para permitir o uso de meses;
}Semana;

Semana* criarSemana();
void prtSemana(Semana *s); //exibir todas as tarefas da semana (divididas por dia)
void prtDia(Semana *s, enum Dds d); //exibir tarefas em um dia
int addTarefa(Semana *s, enum Dds d, char *nome, char *horario_i, char *horario_f);
Tarefa* excTarefaI(Semana *s, enum Dds d, int op); //excluir tarefa no inicio de um dia
Tarefa* excTarefaF(Semana *s, enum Dds d, int op); //excluir tarefa no fim de um dia
Tarefa* excTarefa(Semana *s, enum Dds d, char *nome, int op); //excluir em qualquer posicao de um dia
Tarefa* bscTarefa(Semana *s, enum Dds d, char *nome); //buscar tarefa em qualquer posicao de um dia
Dia bscTarefaSemana(Semana *s, char *nome); //buscar tarefa em toda semana pelo nome
void prtTarefa(Semana *s, enum Dds d, char *nome); //buscar e exibe os horarios de uma tarefa
void prtTarefaSemana(Semana *s, char *nome); //printar uma tarefa na semana buscando pelo nome
void trcTarefa(Semana *s, enum Dds src, enum Dds dest, char *nome_src, char *nome_dest); //trocar duas tarefas em dias diferentes.
void trcLista(Semana *s, enum Dds src, enum Dds dest); //trocar todas as tarefas de "src" para "dest"