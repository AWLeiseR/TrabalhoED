#ifndef _QUADRA_H
#define _QUADRA_H
typedef void* Quadra;

Quadra* criaQuadra();

//define uma quadrass
void defineQuadra(Quadra *quadra, char pCep[],double pX, double pY, double pW, double pH,char pCfill[], char pCstrk[],double pSw);
//muda a cor do stroke e retorna um ponteiro para o cep
char* mudarCor(Quadra *quadra, char cstrk[]);
//desloca a quadra e retorna um ponteiro para cep
char* deslocaQuadra(Quadra *quadra, double dx, double dy);

double getQuadraX(Quadra *qua);

double getQuadraY(Quadra *qua);

double getQuadraH(Quadra *qua);

double getQuadraW(Quadra *qua);

char* getQuadraCep(Quadra *qua);

char* getQuadraCfill(Quadra *qua);

char* getQuadraCstrk(Quadra *qua);

void setQuadraX(Quadra *qua, double pX);

void setQuadraY(Quadra *qua, double pY);

void setQuadraCfill(Quadra *qua, char pCfill[]);

void setQuadraCstrk(Quadra *qua, char pCstrk[]);


#endif