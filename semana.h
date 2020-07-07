#include"dia.c"

typedef struct Semana{
    Dia dias[7];
    struct Semana *ant, *prox; //ponteiros serao usados em atualizacao para permitir o uso de meses;
}Semana;

//funcoes e metodos de administracao de dados da semana
Semana* criarSemana();
void prtSemana(Semana *s); //exibir todas as tarefas da semana (divididas por dia)
void prtDia(Semana *s, enum Dds d); //exibir tarefas em um dia
int addTarefa(Semana *s, char *horario_f, char *horario_i, char *nome, enum Dds d, int op);
Tarefa* excTarefaI(Semana *s, enum Dds d, int op); //excluir tarefa no inicio de um dia
Tarefa* excTarefaF(Semana *s, enum Dds d, int op); //excluir tarefa no fim de um dia
Tarefa* excTarefa(Semana *s, enum Dds d, char *nome, int op); //excluir em qualquer posicao de um dia
Tarefa* bscTarefa(Semana *s, enum Dds d, char *nome); //buscar tarefa em qualquer posicao de um dia
Dia bscTarefaSemana(Semana *s, char *nome); //buscar tarefa em toda semana pelo nome
void prtTarefa(Semana *s, enum Dds d, char *nome); //buscar e exibe os horarios de uma tarefa
void prtTarefaSemana(Semana *s, char *nome); //printar uma tarefa na semana buscando pelo nome
void trcTarefa(Semana *s, enum Dds d1, enum Dds d2, char *nome_d1, char *nome_d2); //trocar duas tarefas em dias diferentes.
void trcLista(Semana *s, enum Dds src, enum Dds dest); //trocar todas as tarefas de "src" para "dest"
void trcTarefaDia(Semana *s, enum Dds src, enum Dds dest, char *nome_src); //troca uma tarefa de dia

//funcoes e metodos de arquivamento e recuperacao de dados gravados em memoria secundaria
Semana* readSemana();
void saveSemana(Semana *s);