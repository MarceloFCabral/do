#include"interface.c"

int main(int argc, char* argv[]){
    printf("Bem-vindo 'a agenda semanal \"Do\"\n");
    Semana *s = readSemana();
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
        printf("[11] - Trocar uma tarefa de dia\n");
        printf("[12] - Salvar semana\n");
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
                addTarefaCase(s, 1); //infelizmente foi necessario encapsular a funcao addTarefa de "semana.c". O mesmo serve para demais funcoes com "Case" no fim
                break;
            case 4:
                excTarefaI(s, getDia(), 0);
                break;
            case 5:
                excTarefaF(s, getDia(), 0);
                break;
            case 6:
                excTarefaCase(s);
                break;
            case 7:
                prtTarefaCase(s);
                break;
            case 8:
                prtTarefaSemanaCase(s);
                break;
            case 9:
                trcTarefaCase(s);
                break;
            case 10:
                trcLista(s, getDia(), getDia());
                break;
            case 11:
                trcTarefaDiaCase(s);
                break;
            case 12:
                saveSemana(s);
                break;
            default:
                printf("Opcao invalida\n");
                getchar();
                break;
        }
    }
    return 0;
}