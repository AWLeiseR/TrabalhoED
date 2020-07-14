#ifndef __LEITURA_H
#define __LEITURA_H




//le o arquivo o geo e coleta os valores e retorna um ponterio para o vetor de formas
Formas *leituraGeo(char address[],Formas *forma,int *nx,FILE *arq3,FILE *svgsemconsulta);
//le o arquivo query e chama as funçoes de processamento
void leituraQry(char pathqry[],char pathsaida[], Formas forma[],int nx,char sufixogeo[],char sufixoqry[],FILE *arq3);

#endif