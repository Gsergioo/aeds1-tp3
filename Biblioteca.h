//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"
//T-Item num tem mais kkkjjjjj
/*
typedef struct {
    TPalavra *texto;
}TBiblioteca;
*/
//Lista encadeada
typedef struct CelulaB{
    struct CelulaB *pProx;
    TListaPLe texto;
}TCelulaT;

typedef struct {
    int tam;
    TCelulaT *pPrimeiro;
    TCelulaT *pUltimo;
}TListaTLe;

//Arranjo
typedef struct {
    TListaPArr *biblioteca;
    int primeiro;
    int ultimo;
}TListaTArr;

//Operacoes por arranjo
void inicializaBiblioArr(TListaTArr *lista);
void insereTextoArr(TListaPArr *texto, TListaTArr *lista);
void removeTextoArr(TListaPArr *texto, TListaTArr *lista);
int tamanhoBibliotecaArr(TListaTArr *lista);

//Operacoes por lista encadeada
void inicializaBiblioLe(TListaTLe *lista);
void insereTextoLe(TListaPLe *texto, TListaTLe *lista);
void removeTextoLe(TListaPLe *texto, TListaTLe *lista);
int tamanhoBibliotecaLe(TListaTLe *lista);