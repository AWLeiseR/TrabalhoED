#ifndef _SVGFILE_H
#define _SVGFILE_H

//imprimir o cabecalho do svg
void cabecalho(FILE* arq);

//imprimir o rodape do svg
void rodape(FILE* arq);

//imprimi retangulo
void imprimiRetangulo(FILE* arq,double x,double y,double h, double w, char cor1[],char cor2[]);

//imprimi Circulo
void imprimiCirculo(FILE* arq,double x,double y, double r, char cor1[],char cor2[]);

//imprimi ponto(circulo de raio 1 ou 0)
void imprimiPonto(FILE* arq);

void imprimiLinha(double x1,double y1,double x2, double y2, FILE *arq);

void imprimiRetangulodash(double x, double y, double w, double h, char stroke[], FILE *arq, int res);

void imprimiTexto(double x, double y, char texto[], FILE *arq);

void imprimiSvgbb(ListaFiguras *list,char *dirsaida,char sufixo[],char cor[],char sufixogeo[]);

void imprimiSvg(ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listRad,ListaFiguras *listHid,ListaFiguras *listSem,char saida[]);

#endif