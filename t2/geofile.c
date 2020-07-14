#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"
#include"texto.h"
#include"svgFile.h"

void leituraGeo(char saidasvg[],char address[],ListaFiguras *listFig,ListaFiguras *listQua,ListaFiguras *listSem,ListaFiguras *listHid,ListaFiguras *listRad){
    Circulo *cir;
    Retangulo *rec;
    Quadra *qua;
    Semaforo *se;
    Hidrante *hidrante;
    Radio *radio;
    Texto *texto;
    FILE* arq;
    FILE *svg;
    //char que recebe o identificador de tipo
    char cfill[20] = "yellow";
    char cstrk[20] = "blue";
    char comando[4];
    //string
    char linha[50];
    char cep[11];
    char i[10];
    //inteiro que recebe o identificador das formas
    int id;
    int numQua,numHid,numSem,numRa;
    int padrao=1000;
    double x,y,w,h,r=5;
    double cw=2.0;
    double rw=3.0;
    double sw;    
    char *line_buf=NULL;
    size_t line_buf_size = 0;
    size_t line_size;
   
    //abre o arquivo svg
    arq=fopen(address,"r");
    //testa se o ponteiro é null
     if(arq==NULL){
        printf("\nNAO ENCONTRADO ARQUIVO %s\n",address);
        perror("");
        exit(1);
    }
   svg=fopen(saidasvg,"w");
   if(svg==NULL){
       printf("\nNAO ENCONTRADO ARQUIVO %s\n",saidasvg);;
        perror("");
        exit(1);
   }
    cabecalho(svg);
    //printf("\t%s\n",address);
    //loop que varre o arquivo .geo
    while(1){
        r=1;
        //pega o comando do arquivo geo
        fscanf(arq,"%s",comando);
        // 'c', circulo
        if(strcmp("c",comando)==0){
            //lea tres doubles responsaveis pelo centro(x,y) e raio depois duas strings responsaveis pelas cores de dentro e da borda
            fscanf(arq,"%d %lf %lf %lf %s %s",&id,&r,&x,&y,cstrk,cfill);
            cir=criaCirculo();
            defineCirculo(cir,id,x,y,r,cstrk,cfill,cw);
            insert(listFig,cir);
            imprimiCirculo(svg,x,y,r,cstrk,cfill);                    
                //printf("%d %lf %lf %lf %s %s\n",id,r,x,y,cstrk,cfill);
        }else if(strcmp("r",comando)==0){//'r',  retangulo               
                //le tquatro doubles responsaveis pel ancora(canto superio esquerdo) e comprimento e altura depois duas strings responsaveis pelas cores de dentro e da borda
                fscanf(arq,"%d %lf %lf %lf %lf %s %s",&id,&w,&h,&x,&y,cstrk,cfill);
                rec=criaRetangulo();
                defineRetangulo(rec,id,x,y,h,w,cstrk,cfill,rw);
                insert(listFig,cir);
                imprimiRetangulo(svg,x,y,w,h,cstrk,cfill);
                //printf("%c %d %lf %lf %lf %lf %s %s\n",forma[id].tipo,forma[id].i,forma[id].w,forma[id].h,forma[id].cx,forma[id].cy,forma[id].borda,forma[id].dentro);
        }else if(strcmp("nx",comando)==0){// 'nx'
        
                //pega o numero do nx  
                fscanf(arq,"%d %d %d %d %d",&padrao,&numQua,&numHid,&numSem,&numRa);
                //printf("\n%d %d %d %d %d\n",padrao,numQua,numHid,numSem,numRa);
                //listFig=createLista(padrao);
                //printf("\n%d\n",listFig);
                //listQua=createLista(numQua);
                //listSem=createLista(numHid);
                //listHid=createLista(numSem);
                
                //listRad=createLista(numRa);
                
        }else if(strcmp("t",comando)==0){//caso for 't',  texto
            
                //pega as coordenadas do texto
                fscanf(arq,"%lf %lf",&x,&y);
                //pega a linha toda de testo
                line_size = getline(&line_buf, &line_buf_size, arq);
                //imprime no arquivo
                imprimiTexto(x,y,line_buf,svg);
        }else if(strcmp("q",comando)==0){
            fscanf(arq,"%s %lf %lf %lf %lf",cep,&x,&y,&w,&h);
            qua=criaQuadra();
            defineQuadra(qua,cep,x,y,w,h,cfill,cstrk,sw);
            insert(listQua,qua);
            
            imprimiRetangulo(svg,x,y,h,w,cstrk,cfill);
            //printf("\nquadra\n");

        }else if(strcmp("h",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            hidrante=criaHidrante();
            defineHidrante(hidrante,i,x,y,cfill,cstrk,sw);
            insert(listHid,hidrante);
            //printf("\nHidrante\n");
            imprimiCirculo(svg,x,y,r,cstrk,cfill);
        }else if(strcmp("s",comando)==0){
            fscanf(arq,"%s %lf %lf",i,&x,&y);
            se=criaSemaforo();
            defineSemaforo(se,i,x,y,cfill,cstrk,sw);
            insert(listSem,se);
           // printf("\nSemafaro\n");
            imprimiCirculo(svg,x,y,r,cstrk,cfill);
        }else if(strcmp("rb",comando)==0){
            fscanf(arq,"%s %lf %lf",&i,&x,&y);
            radio=criaRadio();
            defineRadio(radio,i,x,y,cfill,cstrk,sw);
            insert(listRad,radio);
            //printf("\nRadio-Base\n");
            imprimiCirculo(svg,x,y,r,cstrk,cfill);
        }else if(strcmp("cq",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            //printf("\ncores 1\n");

        }else if(strcmp("ch",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            //printf("\ncores 2\n");

        }else if(strcmp("cr",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            //printf("\ncores 3\n");
                
        }else if(strcmp("cs",comando)==0){
            fscanf(arq,"%s %s %lf", cfill, cstrk, &sw);
            //printf("\ncores 4\n");

        }else if(strcmp("sw",comando)==0){
            fscanf(arq,"%lf %lf",&cw, &rw);
            //printf("\nEspessura\n");

        }
            //testa se esta no final do arquivo
            if (feof(arq)){
                //printf("\nFIM\n");
                break; 
            }                    
        }

        
       
    rodape(svg);
    //fecha o arquivo
    fclose(arq);
    fclose(svg);
    //printf("FIM LEITURA GEO\n");
    //reetorna o ponteiro para formas
    //return void;
//printf("FIM LEITURA GEO\n");
}