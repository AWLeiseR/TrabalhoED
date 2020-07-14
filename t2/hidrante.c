#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char id[10];
    double x;
    double y;
    double sw;
    char cfill[20];
    char cstrk[20];
}Hidrante;


Hidrante* criaHidrante(){
    Hidrante *hid=malloc(sizeof(Hidrante));
    return hid;
}

void defineHidrante(Hidrante* hidrante, char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw){
    strcpy(hidrante->id,i);
    hidrante->x=pX;
    hidrante->y=pY;
    strcpy(hidrante->cfill,pCfill);
    strcpy(hidrante->cstrk,pCstrk);
    hidrante->sw=pSw;
}

char* deslocaHidrante(Hidrante *hidrante, double dx, double dy){
    
        hidrante->x=hidrante->x+dx;
        hidrante->y=hidrante->y+dy;

        return hidrante->id;
}

double getHidX(Hidrante *hid){
    return hid->x;
}

double getHidY(Hidrante *hid){
    return hid->y;
}

char* getHidId(Hidrante *hid){
    return hid->id;
}
char* getHidCfill(Hidrante *hid){
    return hid->cfill;
}

char* getHidCstrk(Hidrante *hid){
    return hid->cstrk;
}

void setHidX(Hidrante *hid, double pX){
    hid->x=pX;
}

void setHidY(Hidrante *hid, double pY){
    hid->y=pY;
}

void setHidCfill(Hidrante *hid, char pCfill[]){
    strcpy(hid->cfill,pCfill);
}

void setHidCstrk(Hidrante *hid, char pCstrk[]){
    strcpy(hid->cstrk,pCstrk);
}