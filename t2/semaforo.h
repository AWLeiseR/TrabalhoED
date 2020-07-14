#ifndef _SEMAFARO_H
#define _SEMAFARO_H
//define um semaforo
typedef void* Semaforo;
//aloca semaforo
Semaforo* criaSemaforo();
//define semaforo
void defineSemaforo(Semaforo *semaforo, char i[], double pX, double pYs, char pCfill[], char pCstrk[],double pSw);
//desloca o semaforo e retorna um ponteiro para o id 
char* deslocaSemaforo(Semaforo *semaforo, double dx, double dy);

double getSemaforoX(Semaforo *se);

double getSemaforoY(Semaforo *se);

char* getSemaforoId(Semaforo *se);

char* getSeamforoCfill(Semaforo *se);

char* getSeamforoCstrk(Semaforo *se);

void setSemaforoX(Semaforo *se, double pX);

void setSemaforoY(Semaforo *se, double pY);

void setSemaforoCfill(Semaforo *se, char pCfill[]);

void setSemaforoCstrk(Semaforo *se, char pCstrk[]);
#endif