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

char* getHo(){
    getchar();
    char *str = (char*) malloc(sizeof(char)*6);
    printf("Insira um horario: ");
    fgets(str, 6, stdin);
}