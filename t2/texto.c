typedef struct{
    char texto[50];
    double x;
    double y;
}Texto;

Texto* criaTexto(){
    Texto *texto=malloc(sizeof(Texto));
    return texto;
}

void defineTexto(Texto *tex,int i, double x, double y, char texto[]){

}