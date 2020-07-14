#ifndef __STRUCTS_H
#define __STRUCTS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct com todas as especificações das formas
typedef struct {
    //identificador
    int i;
    //char q identifica o tipo
    char tipo;
    //coordenada x
    double cx;
    //coordenada y
    double cy;
    //width
    double w;
    //heigth
    double h;
    //raio
    double r;
    //cor de preenchimeto
    char dentro[20];
    //cor de das bordas
    char borda[20];
}Formas;

#endif