#ifndef _RADIOBASE_H
#define _RADIOBASE_H
typedef void* Radio;
//aloca um radio
Radio* criaRadio();
//define uma torre radio
void defineRadio(Radio *radio,char i[], double pX,double pY, char pCfill[], char pCstrk[],double pSw);
//desloca radio e retorna um ponteiro para o id
char* deslocaRadio(Radio *radio, double dx, double dy);

double getRadioX(Radio *radio);

double getRadioY(Radio *radio);

char* getRadioId(Radio *radio);

char* getRadioCfill(Radio *radio);

char* getRadioCstrk(Radio *radio);

void setRadioX(Radio *ra, double pX);

void setRadioY(Radio *ra, double pY);

void setRadioCfill(Radio *ra, char pCfill[]);

void setRadioCstrk(Radio *ra, char pCstrk[]);
#endif