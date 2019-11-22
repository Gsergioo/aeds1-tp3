//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"
//T-Item---------
typedef struct {
    TPalavra *palavra;
}TTexto;

//Lista encadeada
typedef struct CelulaT{
    struct CelulaT *pProx;
    TTexto texto;
}TCelulaT;

typedef struct {
    TCelulaP *pPrimeiro;
    TCelulaP *pUltimo;
}TListaTLe;

//Arranjo
typedef struct {
    TTexto *texto;
    int primeiro;
    int ultimo;
}TListaTArr;

//Operacoes por arranjo
void inicializaTextoArr(TTexto *texto, TListaTArr *lista);
void inserePalavraArr(TTexto *texto, TListaTArr *lista);
void removePalavraArr(TTexto *texto, TListaTArr *lista);
void imprimeTextoArr(TTexto texto, TListaTArr *lista);
int tamanhoTextoArr(TTexto texto, TListaTArr *lista);

//Operacoes por Lista encadeada
void inicializaTextoLe(TTexto *texto, TListaTLe *lista);
void inserePalavraLe(TTexto *texto, TListaTLe *lista);
void removePalavraLe(TTexto *texto, TListaTLe *lista);
void imprimeTextoLe(TTexto texto, TListaTLe *lista);
int tamanhoTextoLe(TTexto texto, TListaTLe *lista);
