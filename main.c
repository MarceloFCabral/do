#include"interface.c"

int main(int argc, char* argv[]){
    printf("Bem-vindo 'a agenda semanal \"Do\"\n");
    Semana *s = criarSemana();
    int status = 1;
    while(status){
        int op = -1;
        printf("O que deseja?\n");
        printf("[0] - Sair\n");
        printf("[1] - Visualizar tarefas da semana\n");
        printf("[2] - Visualizar tarefas em um dia da semana\n");
        printf("[3] - Criar uma tarefa\n");
        printf("[4] - Excluir a primeira tarefa de um dia\n");
        printf("[5] - Excluir a ultima tarefa de um dia\n");
        printf("[6] - Excluir outra tarefa de um dia\n");
        printf("[7] - Exibir uma tarefa de um dia semana\n");
        printf("[8] - Buscar e exibir uma tarefa na semana\n");
        printf("[9] - Trocar tarefas em dois dias diferentes da semana\n");
        printf("[10] - Trocar todas as tarefas de dois diferentes da semana\n");
        printf("Insira uma opcao: "); scanf("%d", &op);
        
        switch(op){
            case 0:
                status = 0;
                break;
            case 1:
                prtSemana(s);
                break;
            case 2:
                prtDia(s, getDia());
                break;
            case 3:
                addTarefa(s, getDia(), getNome(), getHo(), getHo());
                break;
            default:
                printf("def\n");
                break;
        }
    }
       /*
                char nome[101]; char hoi[6]; char hof[6];
                int dia = getDia();
                getchar();
                getNome(nome);
                getHo(hoi);
                getchar();
                getHo(hof);
        addTarefa(s, dia, nome, hoi, hof);
                char nome2[101]; char hoi2[6]; char hof2[6];
                int dia2 = getDia();
                getchar();
                getNome(nome2);
                getHo(hoi2);
                getchar();
                getHo(hof2);
        addTarefa(s, dia2, nome2, hoi2, hof2);
        printf("Nome da tarefa na primeira celula = %s\n", s->dias[Dom].l->primeiro->prox->t->nome);
        printf("Nome da tarefa na ultima celula = %s\n", s->dias[Dom].l->ultimo->t->nome);
        prtSemana(s);
        */
    return 0;
}