//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"
//T-Item
typedef struct {
    TPalavra *texto;
}TBiblioteca;

//Lista encadeada
typedef struct CelulaB{
    struct CelulaB *pProx;
    TBiblioteca biblioteca;
}TCelulaB;

typedef struct {
    TCelulaB *pPrimeiro;
    TCelulaB *pUltimo;
}TListaBLe;

//Arranjo
typedef struct {
    TBiblioteca *biblioteca;
    int primeiro;
    int ultimo;
}TListaBArr;

//Operacoes por arranjo
void inicializaArr(TBiblioteca *biblioteca, TListaBArr *lista);
void insereTextoArr(TBiblioteca *biblioteca, TListaBArr *lista);
void removeTextoArr(TBiblioteca *biblioteca, TListaBArr *lista);
int tamanhoBibliotecaArr(TBiblioteca biblioteca, TListaBArr *lista);

//Operacoes por lista encadeada
void inicializaLe(TBiblioteca *biblioteca, TListaBLe *lista);
void insereTextoLe(TBiblioteca *biblioteca, TListaBLe *lista);
void removeTextoLe(TBiblioteca *biblioteca, TListaBLe *lista);
int tamanhoBibliotecaLe(TBiblioteca biblioteca, TListaBLe *lista);