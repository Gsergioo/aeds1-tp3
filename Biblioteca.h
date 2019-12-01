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
    struct CelulaB *pProx, *pAnte;
    int indice;
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
void insereTextoArr(TListaTArr *lista, int qtdPalavras, int qtdTexto);
void removeTextoArr(TListaTArr *lista);
int tamanhoBibliotecaArr(TListaTArr *lista);
void imprimeBibliotecaArr(TListaTArr* lista);
void selectionSortBibArr(TListaTArr lista);
void quicksortBibArr(TListaTArr lista);
void ordenaBibArr(int esq, int dir, TListaTArr *lista);
void particaoBibArr(int esq, int dir, int* i, int* j, TListaTArr* lista);
void criaCopiaBibArr(TListaTArr* lista, TListaTArr* listacopia);

//Operacoes por lista encadeada
void inicializaBiblioLe(TListaTLe *lista);
void insereTextoLe(TListaTLe *lista, int tam, int tam2);
void removeTextoLe(TListaTLe *lista);
int tamanhoBibliotecaLe(TListaTLe *lista);
void imprimeBibliotecaLe(TListaTLe *biblioteca);
void selectionSortBibLe(TListaTLe lista);
void quicksortBibLe(TListaTLe lista);
void ordenaBibLe(TCelulaT* esq, TCelulaT* dir, TListaTLe *texto, double* comp);
void particaoBibLe(TCelulaT* esq, TCelulaT* dir, TCelulaT** ii, TCelulaT** jj, TListaTLe* texto, double* comp);
void trocaBibLe(TCelulaT* i, TCelulaT* j);
void criaCopiaBibLe (TListaTLe* lista, TListaTLe* listacopia);

