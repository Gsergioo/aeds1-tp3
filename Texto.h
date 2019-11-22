//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"

typedef struct {
    TPalavra *palavra;
}TTexto;

typedef struct CelulaT{
    struct CelulaT *pProx;
    TTexto texto;
}TCelulaT;

typedef struct {
    TTexto *texto;
    int primeiro;
    int ultimo;
}TListaT;

void inicializaTexto(TTexto *texto);
void inserePalavra(TTexto *texto);
void removePalavra(TTexto *texto);
void imprimeTexto(TTexto texto);
int tamanhoTexto(TTexto texto);