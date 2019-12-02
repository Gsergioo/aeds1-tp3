//
// Created by lazarus on 21/11/19.
//


#include "Palavra.h"
//Lista encadeada
typedef struct CelulaP{ //celula contendo uma palavra
    struct CelulaP *pProx, *pAnte;
    TListaLLe palavra; //cada celula tem uma palavra pra um conjunto de celulas se tornar um texto
    int indice;
}TCelulaP; //celula que vai armazenar palavra. Uma lista de palavras = texto

typedef struct {
    int tam;
    //chave da primeira letra de cada palavra;
    TCelulaP *pPrimeiro;
    TCelulaP *pUltimo;
}TListaPLe; //Lista de celulas contendo palavras = texto por lista encadeada

//Arranjo
typedef struct {
    TListaLArr *palavra;
    int primeiro;
    int ultimo;
}TListaPArr; //Arranjo de Palavras = texto

//Operacoes por arranjo
void inicializaTextoArr(TListaPArr *lista, int qtdPalavras);
void inserePalavraArr(TListaPArr *lista, int min, int max);
void removePalavraArr(TListaPArr *lista);
void imprimeTextoArr(TListaPArr *listaPalavra);
int tamanhoTextoArr(TListaPArr *lista);
void selectionSortTextoArr(TListaPArr texto, int flag);
void quicksortTextoArr(TListaPArr texto, int flag);
void ordenaTextoArr(int Esq, int Dir, TListaPArr *A, double* comp, double* mov);
void particaoTextoArr (int Esq, int Dir, int *i, int *j, TListaPArr *A, double* comp, double* mov);
void criaCopiaTextoArr(TListaPArr* lista, TListaPArr* listacopia);

//Operacoes por Lista encadeada
void inicializaTextoLe(TListaPLe *lista);
void inserePalavraLe(TListaPLe *lista, int min, int max);
void removePalavraLe(TListaPLe *lista);
void imprimeTextoLe(TListaPLe *lista);
int tamanhoTextoLe(TListaPLe *lista);
void quicksortTextoLe(TListaPLe texto, int flag);
void ordenaTexto(TCelulaP* esq, TCelulaP* dir, TListaPLe *texto, double* comp, double* mov);
void particaoTexto(TCelulaP* esq, TCelulaP* dir, TCelulaP** ii, TCelulaP** jj, TListaPLe* texto, double* comp, double* mov);
void trocaTexto(TCelulaP* i, TCelulaP* j);
void selectionSortTextoLe(TListaPLe texto, int flag);
void criaCopiaTextoLe (TListaPLe* lista, TListaPLe* listacopia);
