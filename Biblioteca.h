//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"

typedef struct {
    TTexto *texto;
}TBiblioteca;

typedef struct CelulaB{
    struct CelulaB *pProx;
    TBiblioteca biblioteca;
}TCelulaB;

typedef struct {
    TBiblioteca *biblioteca;
    int primeiro;
    int ultimo;
}TListaB;

void inicialzia(TBiblioteca *biblioteca);
void insereTexto(TBiblioteca *biblioteca);
void removeTexto(TBiblioteca *biblioteca);
int tamanhoBiblioteca(TBiblioteca biblioteca);