
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"figuras.h"
#include"quadra.h"
#include"semaforo.h"
#include"hidrante.h"
#include"radioBase.h"
 


typedef struct{
    char tipo;
    union{
        Retangulo *retangulo;
        Circulo *circulo;
        Quadra *quadra;
        Hidrante *hidrante;
        Semaforo *semaforo;
        Radio *radio;
    };
}Forma;

typedef struct{
    Forma *forma;
    int ant;
    int prox;
}Item;

typedef struct lista{
    Item* info;
    int primeiro;
    int livre;
    int ultimo;
}ListaFiguras;

ListaFiguras* createLista(int tam_lista){
    printf("lista criada\n");
    int i=0 ;
    ListaFiguras* aux;
    ListaFiguras* lista= malloc(sizeof(ListaFiguras));
    lista->info = malloc(sizeof(Item)*tam_lista);
    lista->livre=0;
    lista->primeiro=-1;
    lista->ultimo=-1;
    aux=lista;
    for(i=0;i<tam_lista;i++){
        aux->info[i].prox=1+i;
    }
    aux->info[tam_lista-1].prox=-1;
    return lista;
}

int lenght(ListaFiguras* list){
    int i=0;
    int primeiro;
    primeiro=list->primeiro;
    ListaFiguras* aux;
    aux=list;
    while(1){
        if(aux->info[aux->primeiro].prox!=-1){
            aux->primeiro=aux->info[aux->primeiro].prox;
            i++;
        }else{
            i++;
            break;
        }        
    }
    list->primeiro=primeiro;
    return i;
}
   

int insert(ListaFiguras* list, Forma* forma,char pTipo){
    Forma* nItem;
    nItem=forma;
    nItem->tipo=pTipo;
    int n;
    int n1;
    int antLivre;
    n1=list->livre;
    antLivre=n1-1;
    n=list->info[list->livre].prox;
    if(list->primeiro==-1){
        list->primeiro=n1;
    }else{
        list->info[antLivre].prox=list->livre;  
    }
    list->info[list->livre].prox=-1;
    list->info[list->livre].forma=nItem;
    list->info[list->livre].ant=list->ultimo;
    list->livre=n;
    list->ultimo=n1;
    return n1;
}
void imprimir(ListaFiguras* list){
    int i=0;
    int primeiro;
    primeiro=list->primeiro;
    while(1){
        if(list->info[list->primeiro].prox!=-1){
            printf("anterior[%d] proximo[%d]\n",list->info[list->primeiro].ant,list->info[list->primeiro].prox);
            list->primeiro=list->info[list->primeiro].prox;
        }else{
            printf("anterior[%d] proximo[%d]\n",list->info[list->primeiro].ant,list->info[list->primeiro].prox); 
            break;
        }
    }
    list->primeiro=primeiro;
}

void delet(ListaFiguras* list, int p){
    int antLivre;
    antLivre=list->livre;
    if(list->primeiro == p && list->ultimo==p){
        list->info[p].prox=list->livre;
        list->primeiro=-1;
        list->ultimo=-1;
    }else if(list->primeiro == p){
        list->info[list->info[p].prox].ant=-1;
        list->primeiro=list->info[p].prox;
        list->info[p].prox=list->livre;
    }else if(list->ultimo==p){
        list->info[p].prox=list->livre;
        list->info[list->info[p].ant].prox=-1;
        list->ultimo=list->info[p].ant;
    }else{
        list->info[list->info[p].prox].ant=list->info[p].ant;
        list->info[list->info[p].ant].prox=list->info[p].prox;
        
    } 
    list->livre=p;   
}

void freeList(ListaFiguras *list){
        free(list->info);
        free(list);    
}


int getFirst(ListaFiguras *list){
    printf("%d",list->primeiro);
    return list->primeiro;
}

int getProx(ListaFiguras *list,int i){
    return list->info[i].prox;
}

char getTipo(ListaFiguras *list, int i){
    return list->info[i].forma->tipo;
}

Circulo* getCirculo(ListaFiguras *list,int i){
    return list->info[i].forma->circulo;
}

Retangulo* getRetangulo(ListaFiguras *list,int i){
    return list->info[i].forma->retangulo;
}

Radio* getRadio(ListaFiguras *list,int i){
    return list->info[i].forma->radio;
}

Hidrante* getHidrante(ListaFiguras *list,int i){
    return list->info[i].forma->hidrante;
}

Quadra *getQuadra(ListaFiguras *list,int i){
    return list->info[i].forma->quadra;
}

Semaforo* getSemaforo(ListaFiguras *list,int i){
    return list->info[i].forma->semaforo;
}

//arrumar
int buscaChar(ListaFiguras* list, char pId[],char pTipo){
    int i=-1;
    int tam;
    int prox=list->primeiro;
    char *id;
    Quadra *qua;
    Radio *ra;
    Semaforo *se;
    Hidrante *hid;
   do{
        switch(pTipo){
            case'q':
            
                qua=getQuadra(list,prox);
                id=getQuadraCep(qua);
                if(strcmp(id,pId)==0){
                    i=prox;
                }
            break;
            case'r':
            ra=getRadio(list,prox);
            id=getRadioId(ra);
            if(strcmp(id,pId)==0){
                    i=prox;
                }
            break;
            case's':
            se=getSemaforo(list,prox);
            id=getSemaforoId(se);
            if(strcmp(id,pId)==0){
                    i=prox;
                }
            break;
            case'h':
            hid=getHidrante(list,prox);
            id=getHidId(hid);
            if(strcmp(id,pId)==0){
                    i=prox;
                }
            break;

        }
        prox=list->info[prox].prox;
    } while(list->info[prox].prox!=-1);
    return i;
}