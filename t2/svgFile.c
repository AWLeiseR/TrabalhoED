#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"

//imprimir o cabecalho do svg
void cabecalho(FILE* arq){
    fprintf(arq,"<svg>");
}

//imprimir o rodape do svg
void rodape(FILE* arq){
    fprintf(arq,"<svg>");
}

//imprimi retangulo
void imprimiRetangulo(FILE* arq,double x,double y,double h, double w, char cor1[],char cor2[]){
    fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"  stroke=\"%s\" fill=\"%s\" stroke-width=\"2\" />",x,y,w,h,cor1,cor2);
}

//imprimi Circulo
void imprimiCirculo(FILE* arq,double x,double y, double r, char cor1[],char cor2[]){

    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,r,cor1,cor2);
}

//imprimi ponto(circulo de raio 1 ou 0)
void imprimiPonto(FILE* arq,double x,double y,char cor1[],char cor2[]){
    fprintf(arq,"<circle cx=\"%lf\" cy=\"%lf\" r=\"1\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,cor1,cor2);
}

void imprimiLinha(double x1,double y1,double x2, double y2, FILE *arq){
   fprintf(arq," <line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" />",x1,y1,x2,y2);
}

void imprimiRetanguloDash(double x, double y, double w, double h, char stroke[], FILE *arq, int res){
    if(res)
        fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-dasharray=\"5\" stroke-width:\"2\" />",x,y,w,h,stroke);
    else
     fprintf(arq,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width:\"2\" />",x,y,w,h,stroke);
}

void imprimiTexto(double x, double y, char texto[], FILE *arq){
    fprintf(arq,"<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>",x,y,texto);
}

void imprimiSvgbb(ListaFiguras *list,char *dirsaida,char sufixo[],char cor[],char sufixogeo[]){
    FILE *svg;
    Circulo *cir;
    Retangulo *rec;
    char *saida;
    int j;
    int prox=getFirst(list);
    double x,y,w,h,r;
    char tipo;
    char *borda,*dentro;
   
    saida=(char *) malloc((strlen(dirsaida)+strlen(sufixo)+strlen(sufixogeo)+7)*sizeof(char));

    sprintf(saida,"%s/%s-%s.svg",dirsaida,sufixogeo,sufixo);

    svg=fopen(saida,"w");
    if(svg==NULL){
        perror("");
        exit(1);
    }

    fprintf(svg,"<svg>");

    while(prox!=-1){
        switch (getTipo(list,prox)){
            case 'c':
                cir=getCirculo(list,prox);
                x=getCirculoX(cir);
                y=getCirculoY(cir);
                r=getCirculoR(cir);
                borda=getCirculoCstrk(cir);
                dentro=getCirculoCfill(cir);
                fprintf(svg,"<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />",x,y,r,borda,dentro);
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\"  fill=\"none\" stroke=\"%s\" stroke-width:\"1\" />",x-r,y-r,r*2,r*2,cor);
                break;

            case 'r':
                rec=getRetangulo(list,prox);
                x=getRetanguloX(rec);
                y=getRetanguloY(rec);
                h=getRetanguloH(rec);                    
                w=getRetanguloW(rec);
                borda=getRetanguloCstrk(rec);
                dentro=getRetanguloCfill(rec);
                fprintf(svg,"<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\"  stroke-width:\"2\" />",x,y,w,h,borda,dentro);
                fprintf(svg,"<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width\"2\" />",x+(w/2),y+(h/2),w/2,h/2,cor);
                break;
                }
        prox=getProx(list,prox);        
    }
    fprintf(svg,"</svg>");

    fclose(svg);
}

void imprimiSvg(ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listRad,ListaFiguras *listHid,ListaFiguras *listSem,char saida[]){
    FILE *svg;
    svg=fopen(saida,"w");
    int fig,qua,rad,hid,sem;
    fig=lenght(listFig);
    qua=lenght(listQua);
    rad=lenght(listRad);
    hid=lenght(listHid);
    sem=lenght(listSem);
    if(svg==NULL){
        perror("");
        exit(1);
    }
    
    cabecalho(svg);

}