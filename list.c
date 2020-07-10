#include"list.h"
#include"util.c"

List* createList(){
    List *l = (List*) malloc(sizeof(List));
    l->first = l->last = createCell(NULL);
    l->n = 0;
    return l;
}

Cell* removeList(List* l, int op){ //op == 0 -> desalocar List; op != 0 -> retornar List para uso posTueior
    Cell* remov = NULL;
    if(op){ remov = l->first; }
    else{
        Cell *tmp = l->first->next, *tmp2 = NULL;
        while(tmp != l->last){
            tmp2 = tmp->next;
            removeCell(tmp, op);
            tmp = tmp2;
        }
    }
    return remov;
}

Task* removeFront(List *l, int op){ //idem
    Task *remov = NULL;
    if(l->n == 0){
        printf("There are no tasks!");
    }else{
        remov = removeCell(l->first->next, op);
        l->n--;
    }
    return remov;
}

Task* removeEnd(List *l, int op){ //idem
    Task *remov = NULL;
    if(l->n == 0){
        printf("There are no tasks!");
    }else{
        Cell *tmp = l->last;
        l->last = l->last->prev;
        remov = removeCell(tmp, op);
        l->n--;
    }
    return remov;
}

Cell* searchForCell(List *l, char *name){
    Cell *c = NULL;
    for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
        if(strcmp(name, tmp->t->name) == 0){
            c = tmp;
            tmp = l->last;
        }
    }

    if(c == NULL){printf("Couldn't find the cell that contains this task!\n");}
    return c;
}

Task* searchForTask(List *l, char *name){
    Task *t = NULL;
    for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
        if(strcmp(name, tmp->t->name) == 0){
            t = tmp->t;
            tmp = l->last;
        }
    }

    if(t == NULL){printf("Task not found!\n");}
    return t;
}

int insertTask(List *l, Task *ta, int op){ //codigos: 0 -> nao inserido; 1 -> inserido
    int inserido = 0;
    if(ta != NULL){
        if(l->n == 0){
            Cell *c = createCell(ta);
            l->first->next = c;
            c->prev = l->first;
            l->last = c;
            if(op){printf("Added task:"); printTask(ta);}
            inserido = 1;
            l->n++;
        }else{
            Cell *tmp = l->first->next;    
            int i = 0;
            for(i; tmp != NULL && i < l->n; i++){
                Task *tb = tmp->t;
                if( (inserido = checkTime(ta, tb)) == 0){
                    printf("Invalid task time!\n");
                    tmp = NULL;
                }else if(inserido == -1){
                    Cell *c = createCell(ta);
                    c->next = tmp;
                    c->prev = tmp->prev;
                    tmp->prev->next = c;
                    tmp->prev = c;
                    if(op){printf("Added task:"); printTask(ta);}
                    inserido = 1;
                    l->n++;
                    tmp = NULL;
                }else{
                    tmp = tmp->next;
                }
            }

            if(i == l->n && inserido != 0){
                Cell *c = createCell(ta);
                c->prev = l->last;
                l->last = l->last->next = c;
                if(op){printf("Added task:"); printTask(ta);}
                inserido = 1;
                l->n++;
            }
        }
    }
    return inserido;
}

Task* removeTaskFromList(List *l, char *name, int op){ //ATENCAO: retorna null se nao encontrou a tarefa
    Task *t = NULL;
    Cell *c = NULL;
    if( (c = searchForCell(l, name)) != NULL){
        t = removeCell(c, op);
        l->n--;
    }
    return t;
}

void printList(List *l){
    if(l->n == 0){
        printf("There are no tasks!\n");
    }else{
        printf("\nNumber of tasks on this day: %d", l->n);
        for(Cell *tmp = l->first->next; tmp != NULL; tmp = tmp->next){
            printTask(tmp->t);
        }
    }
}

