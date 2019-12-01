//
// Created by lazarus on 21/11/19.
//

/*
    TCelulaP = Tipo Celula de Palavra (celula contem uma palavra)
    TListaPLe = Tipo Lista de Palavras por Lista Encadeada = texto por lista encadeada
    TListaPArr = Tipo Lista de Palavras por Arranjo = texto por arranjo
 */

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
void inserePalavraArr(TListaPArr *lista, int tam);
void removePalavraArr(TListaPArr *lista);
void imprimeTextoArr(TListaPArr *listaPalavra);
int tamanhoTextoArr(TListaPArr *lista);
void selectionSortArr(TListaPArr texto);
void quicksortTextoArr(TListaPArr texto);
void ordenaTextoArr(int Esq, int Dir, TListaPArr *A);
void particaoTextoArr (int Esq, int Dir, int *i, int *j, TListaPArr *A);
void criaCopiaTextoArr(TListaPArr* lista, TListaPArr* listacopia);

//Operacoes por Lista encadeada
void inicializaTextoLe(TListaPLe *lista);
void inserePalavraLe(TListaPLe *lista, int tam);
void removePalavraLe(TListaPLe *lista);
void imprimeTextoLe(TListaPLe *lista);
int tamanhoTextoLe(TListaPLe *lista);
void quicksortTexto(TListaPLe texto);
void ordenaTexto(TCelulaP* esq, TCelulaP* dir, TListaPLe *texto, double* comp);
void particaoTexto(TCelulaP* esq, TCelulaP* dir, TCelulaP** ii, TCelulaP** jj, TListaPLe* texto, double* comp);
void trocaTexto(TCelulaP* i, TCelulaP* j);
void selectionSort (TListaPLe texto);
void criaCopiaTextoLe (TListaPLe* lista, TListaPLe* listacopia);
