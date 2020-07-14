#ifndef __GEOMETRIA_H
#define __GEOMETRIA_H

//retorna 1 se o ponto for interior e 0 se for externo
int pontoInteriorRetangulo(double px, double py, double cx1, double cy1, double cx2, double cy2);
//retorna 1 se o ponto for interior e 0 se for externo
int pontoInternoCirculo(double px, double py, double cx, double cy, double r);
//calcula/retorna distancia entre dois pontos
double distancia (double x1, double y1, double x2, double y2);
//calcula o maior numero ente n1 e n2
double max(double n1,double n2);
//calcula o menor numero ente n1 e n2
double min(double n1,double n2);
//verirfica se ha colisao ou nao, retorna 1 para sim e 0 para nao
int collision(double recX,double recY,double recW,double recH,double cX,double cY,double cR);

#endif