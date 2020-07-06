#include"interface.h"

int getDia(){
    int d = -1;
    while(d < 0 || d > 6){
        printf("Insira um numero de 0 a 6 [0 = Domingo, 6 = Sabado]: ");
        scanf("%d", &d);
    }
    return d;
}

char* getNome(){
    getchar();
    char *str = (char*) malloc(sizeof(char)*101);
    printf("Insira um nome com ate 100 caracteres: ");
    fgets(str, 101, stdin);
    str[strlen(str)-1] = '\0';
    return str;
}

char* getHo(int op){
    getchar();
    char *str = (char*) malloc(sizeof(char)*6);
    !op ? printf("Insira o horario de inicio: ") : printf("Insira o horario de termino: ");
    fgets(str, 6, stdin);
}

void addTarefaCase(Semana *s){
    char *nome = getNome();
    int dia = getDia();
    char *hoI = getHo(0);
    char *hoF = getHo(1);
    addTarefa(s, hoF, hoI, nome, dia);
    free(hoI); free(hoF);
}

void excTarefaCase(Semana *s){
    char *nome = getNome();
    excTarefa(s, getDia(), nome, 0);
    free(nome);
}

void prtTarefaCase(Semana *s){
    char *nome = getNome();
    prtTarefa(s, getDia(), nome);
    free(nome);
}

void prtTarefaSemanaCase(Semana *s){
    char *nome = getNome();
    prtTarefaSemana(s, nome);
    free(nome);
}

void trcTarefaCase(Semana *s){
    printf("Primeira tarefa:\n");
    int d1 = getDia();
    char *nome_d1 = getNome();
    printf("Segunda tarefa\n");
    int d2 = getDia();
    char *nome_d2 = getNome();
    trcTarefa(s, d1, d2, nome_d1, nome_d2);
    free(nome_d1); free(nome_d2);
}

void trcTarefaDiaCase(Semana *s){
    Tarefa *t = NULL;
    char *nome = getNome();
    printf("Insira o dia que contem a tarefa:\n");
    int src = getDia();
    printf("Insira o dia de destino:\n");
    int dest = getDia();
    if( (t = bscTarefa(s, src, nome)) != NULL && checkTimeLista(t, s->dias[dest].l) ){
        trcTarefaDia(s, src, dest, nome);
    }else{
        printf("Nao foi possivel trocar a tarefa de dia! Horarios conflitantes ou tarefa inexistente!\n");
    }
    free(nome);
    getchar();
}