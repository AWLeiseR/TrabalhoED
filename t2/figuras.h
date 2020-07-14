#ifndef _FIGURAS_H
#define _FIGURAS_H
typedef void* Circulo;
//aloca o circulo
Circulo* criaCirculo();

//declaração de retangulo
typedef void* Retangulo;
//aloca um retangulo
Retangulo* criaRetangulo();
//define circulo
void defineCirculo(Circulo circulo,int i,double pX,double pY, double pR,char pStroke[], char pFill[],double pStrokeWidth);
//define um retangulo
void defineRetangulo(Retangulo rec, double i, double pX, double pY, double pH, double pW, char pStroke[], char pFill[], double pStrokeWidth);
//desloca a figura(circ) em x e y
void deslocaCirculo(double dx, double dy);
//desloca a figura (rec) em x e y
void deslocaRetangulo(double dx, double dy);
//verifica sobreposição das figuras
//circulo com circulo
int sobreposicaoCirculoCirculo(double x1, double y1, double r1, double x2, double y2,double r2,char cor[],FILE *arq3);
//Circulo e retangulo
int sobreposicaoCirculoRetangulo(double x1, double y1, double r1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);
//retangulo com retangulo
int sobreposicaoRetanguloRetangulo(double x1, double y1, double h1, double w1, double x2, double y2,double h2,double w2,char cor[],FILE *arq3);
//gets and sets
int getCirculoId(Circulo *cir);

double getCirculoX(Circulo *cir);

double getCirculoY(Circulo *cir);

double getCirculoR(Circulo *cir);

char* getCirculoCfill(Circulo *cir);

char* getCirculoCstrk(Circulo *cir);

double getRetanguloX(Retangulo *rec);

double getRetanguloY(Retangulo *rec);

double getRetanguloW(Retangulo *rec);

double getRetanguloH(Retangulo *rec);

int getRetanguloId(Retangulo *rec);

char* getRetanguloCfill(Retangulo *rec);

char* getRetanguloCstrk(Retangulo *rec);

#endif