#include"week.h"

Week* createWeek(){
    Week *s = (Week*) malloc(sizeof(Week));
    s->prev = s->next = NULL;
    for(int i = Sun; i <= Sat; i++){
        s->days[i] = createDay(i);
    }
    return s;
}

void prtWeek(Week *s){
    printf("=== Week ===\n");
    for(int i = Sun; i <= Sat; i++){
        printDay(s->days[i]);
        printf("\n");
    }
}

void prtDay(Week *s, enum DotW d){
    printDay(s->days[d]);
}

int addTask(Week *s, char *e_tt_str, char *b_tt_str, char *name, enum DotW d, int op){ // op == 1 -> insercao de novo dado, op == 0 -> carregamento
    int inserted = 0;
    int *b_tt = parseTime(b_tt_str);
    int *e_tt = parseTime(e_tt_str);
    if(b_tt != NULL && e_tt != NULL){
        if(op){printf("--> Em %s:\n", getDayName(d));}
        inserted = insert(s->days[d].l, createTask(name, createTaskTime(b_tt[0], b_tt[1], e_tt[0], e_tt[1])), op);
    }else{
        printf("Invalid task time!\n");
    }
    return inserted;
}

Task* excTaskB(Week *s, enum DotW d, int op){
    printf("--> Em %s:\n", getDayName(d));
    return removeFront(s->days[d].l, op);
}

Task* excTaskE(Week *s, enum DotW d, int op){
    printf("--> Em %s:\n", getDayName(d));
    return removeEnd(s->days[d].l, op);
}

Task* excTask(Week *s, enum DotW d, char *name, int op){
    printf("--> Em %s:\n", getDayName(d));
    return remove(s->days[d].l, name, op);
}

Task* getTask(Week *s, enum DotW d, char *name){ //uso inTueno
    return searchForTask(s->days[d].l, name);
}

Day getTaskWeek(Week *s, char *name){ //ATENCAO: diferente das outras funcoes de busca, esta funcao retorna o Day, e nao a tarefa.
    Day day = {Sun, NULL}; //o enum é válido, portanto é NECESSÁRIO checar se Day->l != NULL
    int i = Sun;
    for(i; (i <= Sat) && (searchForTask(s->days[i].l, name) == NULL); i++);
    if(i <= 6){day = s->days[i];}
    return day;
}

void prtTask(Week *s, enum DotW d, char *name){
    printf("--> Em %s:", getDayName(d));
    printTask(getTask(s, d, name));
}

void prtTaskWeek(Week *s, char *name){
    Day Day = getTaskWeek(s, name);
    if(Day.l != NULL){
        printf("--> Em %s:", getDayName(Day.d));
        printTask(getTask(s, Day.d, name));
    }else{
        printf("Task nao encontrada na Week!\n");
    }
}

void swpTasks(Week *s, enum DotW d1, enum DotW d2, char *name_d1, char *name_d2){
    Cell *c1 = searchForCell(s->days[d1].l, name_d1);
    Cell *c2 = searchForCell(s->days[d2].l, name_d2);
    if(c1 != NULL && c2 != NULL){
        Task *tmp = c1->t;
        c1->t = c2->t;
        c2->t = tmp;
        printf("Troca realizada!\n");
    }else{
        printf("Nao foi possivel trocar!\n");
    }
}

void swpLists(Week *s, enum DotW d1, enum DotW d2){
    List *tmp = s->days[d1].l;
    s->days[d1].l = s->days[d2].l;
    s->days[d2].l = tmp;
    printf("Troca realizada!\n");
}

void cngTaskDay(Week *s, enum DotW src, enum DotW dest, char *name_src){
    insert(s->days[dest].l, remove(s->days[src].l, name_src, 1), 0) ? printf("Troca realizada!\n") : printf("Nao foi possivel realizar a troca!\n");
}

//funcoes de leitura e gravacao em memoria secundaria
//leitura
Week* readWeek(){
    FILE *f = fopen("Week.txt", "r");
    Week *s = createWeek();
    if(f == NULL){
        printf("Nao foi possivel encontrar uma Week. Criando nova Week\n");
    }else{
        int Day = 0;
        fscanf(f, "%d", &Day);
        while(Day != -1){
            int n_tarefas = 0;
            fscanf(f, "%d", &n_tarefas);
            for(int i = 0; i < n_tarefas; i++){
                char *name = (char*) malloc(sizeof(char)*101);
                char b_tt[6]; char e_tt[6];
                fscanf(f, "%s %s %s", name, b_tt, e_tt);
                addTask(s, e_tt, b_tt, name, Day, 0);
            }
            fscanf(f, "%d", &Day);
        }
        printf("Week carregada!\n");
        fclose(f);
    }
    return s;
}

//escrita
void saveWeek(Week *s){
    printf("Salvando Week...\n");
    FILE *f = fopen("Week.txt", "w");
    for(int i = Sun; i <= Sat; i++){
        List *l = s->days[i].l;
        fprintf(f, "%d\n", i);
        fprintf(f, "%d\n", l->n);
        for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
            fprintf(f, "%s\n", tmp->t->name);
            fprintf(f, "%02d:%02d\n", tmp->t->tt->b_h, tmp->t->tt->b_m);
            fprintf(f, "%02d:%02d\n", tmp->t->tt->e_h, tmp->t->tt->e_m);
        }
    }
    fprintf(f, "%d", -1);
    fclose(f);
}