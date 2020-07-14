#ifndef __ESCRITASVG_H
#define __ESCRITASVG_H

//cria e imprime o svg obedecendo o comando bb
void criaSvgbb(Formas forma[],char *dirsaida,char sufixo[],char cor[],int nx,char sufixogeo[]);
//imprime no arquivo svg uma linha
void criaLinha(double x1,double y1,double x2, double y2,FILE *arq3);
//imprime no arquivo svg um circulo
void criaCirculo(double x, double y ,char cor[],FILE *arq3);
//imprime no arquivo svg uma linha de  texto
void criaTexto(double x, double y, char texto[], FILE *arq3);
//imprime no arquivo svg um retangulo pontilhado
void criaRetangulodash(double x, double y, double w, double h, char stroke[], FILE *arq3, int res);
// imprime svg inicial
void criaSvg(Formas aux[],FILE *arq3,int nx);

#endif