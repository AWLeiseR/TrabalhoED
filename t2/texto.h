#ifndef _TEXTO_H
#define _TEXTO_H

typedef void* Texto;

Texto* criaTexto();

void defineTexto(Texto *tex,int i, double x, double y, char texto[]);

#endif