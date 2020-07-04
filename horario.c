#include"horario.h"
#ifndef HORARIO_C
#define HORARIO_C

Horario* criarHorario(unsigned int ih, unsigned int im, unsigned int fh, unsigned int fm){
    Horario *ho = NULL;
    if( (ih > 23 || fh > 23 || im > 59 || fm > 59) ){ //se hora/minutos possuem valores invalidos
        printf("Erro! Horario invalido.\n");
    }else{
        ho = (Horario*) malloc(sizeof(Horario));
        ho->i_h = ih;
        ho->i_m = im;
        ho->f_h = fh;
        ho->f_m = fm;
        ho->i_time = (float)ih + (float)im / 60;
        ho->f_time = (float)fh + (float)fm / 60;
    }
    return ho;
}

Horario* removerHorario(Horario* ho, int op){
    Horario *remov = NULL;
    if(ho != NULL){
        if(op){ remov = ho; }
        else{
            free(ho);
        }
    }
    return remov;
}

void printHorario(Horario *ho){
    printf("\n\tHORARIO: %02d:%02d a %02d:%02d\n", ho->i_h, ho->i_m, ho->f_h, ho->f_m);
}

void printHorarioTime(Horario *ho){
    printf("\nTempo fracionario do horario:\n\tInicio: %f\n\tFim: %f\n", ho->i_time, ho->f_time);
}

#endif