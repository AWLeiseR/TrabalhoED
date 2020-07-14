#include<stdlib.h>
#include<string.h>
#include <stdio.h>
typedef struct{
    char id[30];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Radio;

Radio* criaRadio(){
    Radio *radio=malloc(sizeof(radio));
}
void defineRadio(Radio *radio,char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw){
    
    strcpy(radio->id,i);
    radio->x=pX;
    radio->y=pY;
     strcpy(radio->cfill,pCfill);
    strcpy(radio->cstrk,pCstrk);
    radio->sw=pSw;
}

char* deslocaRadio(Radio *radio, double dx, double dy){
    radio->x=radio->x+dx;
    radio->y=radio->y+dy;

    return radio->id;
}

char* getRadioId(Radio *radio){
    return radio->id;
}

double getRadioX(Radio *radio){
    return radio->x;
}

double getRadioY(Radio *radio){
    return radio->y;
}

char* getRadioCfill(Radio *radio){
    return radio->cfill;
}

char* getRadioCstrk(Radio *radio){
    return radio->cstrk;
}

void setRadioX(Radio *radio, double pX){
    radio->x=pX;
}

void setRadioY(Radio *radio, double pY){
    radio->y=pY;
}

void setRadioCfill(Radio *radio, char pCfill[]){
    strcpy(radio->cfill,pCfill);
}

void setRadioCstrk(Radio *radio, char pCstrk[]){
    strcpy(radio->cstrk,pCstrk);
}