#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#ifndef HORARIO_H
#define HORARIO_H

typedef struct Horario{
    unsigned int i_h, f_h, i_m, f_m;
    float i_time, f_time;
}Horario;

Horario* criarHorario(unsigned int ih, unsigned int im, unsigned int fh, unsigned int fm);
Horario* removerHorario(Horario* ho, int op);
void printHorario(Horario *ho);
void printHorarioTime(Horario *ho);

#endif