//
// Created by lazarus on 21/11/19.
//


/*
    TPalavra = Tipo palavra
    TCelulaP = Tipo Celula de Palavra (celula contem uma palavra)
    TListaPLe = Tipo Lista de Palavras por Lista Encadeada
    TListaPArr = Tipo Lista de Palavras por Arranjo
 */

#include "Palavra.h"
//T-Item---------
typedef struct {
    Tletra *palavra;
}TPalavra;

//Lista encadeada
typedef struct CelulaP{ //celula contendo uma palavra
    struct CelulaP *pProx;
    TPalavra texto;
}TCelulaP; //celula que vai armazenar palavra. Uma lista de palavras = texto

typedef struct {
    int tam;
    //chave da primeira letra de cada palavra;
    TCelulaP *pPrimeiro;
    TCelulaP *pUltimo;
}TListaPLe; //Tipo Lista de Palavras por Lista Encadeada (TListaPLe)

//Arranjo
typedef struct {
    TPalavra *texto;
    int primeiro;
    int ultimo;
}TListaPArr; //Arranjo de Palavras = texto

//Operacoes por arranjo
void inicializaTextoArr(TListaPArr *lista);
void inserePalavraArr(TPalavra *palavra, TListaPArr *lista);
void removePalavraArr(TPalavra *palavra, TListaPArr *lista);
void imprimeTextoArr(TListaLArr *letras,TListaPArr *listaPalavra);
int tamanhoTextoArr(TListaPArr *lista);

//Operacoes por Lista encadeada
void inicializaTextoLe(TListaPLe *lista);
void inserePalavraLe(TPalavra *texto, TListaPLe *lista);
void removePalavraLe(TPalavra *texto, TListaPLe *lista);
void imprimeTextoLe(TListaLLe *listaLLe, TListaPLe *lista);
int tamanhoTextoLe(TPalavra texto, TListaPLe *lista);
