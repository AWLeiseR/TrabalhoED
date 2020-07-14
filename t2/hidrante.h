#ifndef _HIDRANTE_H
#define _HIDRANTE_H
typedef void* Hidrante;

Hidrante* criaHidrante();

//define hidrante
void defineHidrante(Hidrante* hidrante, char i[], double pX, double pY, char pCfill[], char pCstrk[],double pSw);

//desloca hidrante e retorna um ponteiro para o id
char* deslocaHidrante(Hidrante *hidrante, double dx, double dy);

double getHidX(Hidrante *hid);

double getHidY(Hidrante *hid);

char* getHidId(Hidrante *hid);

char* getHidCfill(Hidrante *hid);

char* getHidCstrk(Hidrante *hid);

void setHidX(Hidrante *hid, double pX);

void setHidY(Hidrante *hid, double pY);

void setHidCfill(Hidrante *hid, char pCfill[]);

void setHidCstrk(Hidrante *hid, char pCstrk[]);
#endif