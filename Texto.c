//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>

//Operacoes por arranjo

void inicializaTextoArr(TListaPArr *lista){
    lista->palavra = (TListaLArr*) malloc(lista->ultimo*sizeof(TListaLArr));
    lista->primeiro = 0;
    lista->ultimo = 0;
}
void inserePalavraArr(TListaLArr *palavra, TListaPArr *lista){
    lista->palavra = palavra;
    lista->ultimo++;
}
void removePalavraArr(TListaLArr *palavra, TListaPArr *lista){
    //nao sei como vai ser a remoção
}
void imprimeTextoArr(TListaPArr *listaPalavra){ //muito provavel que ta errado, mas vida que segue. Depois arruma
    for (int i = listaPalavra->primeiro; i < listaPalavra->ultimo; i++) {
        imprimePalavraArr(listaPalavra->palavra);
    }
}
int tamanhoTextoArr(TListaPArr *lista){
    return lista->ultimo;
}

//----------------------------------------------------------

//Operacoes por Lista encadeada

void inicializaTextoLe(TListaPLe *lista){
    lista->pPrimeiro = (TCelulaP*)malloc(sizeof(TCelulaP));
    lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->pProx = NULL;
    lista->tam = 0;
}
void inserePalavraLe(TListaLLe *texto, TListaPLe *lista){
    TCelulaP *aux = NULL;
    aux = (TCelulaP*) malloc(sizeof(TCelulaP));
    aux->pProx = NULL;
    aux->palavra = *texto;
    lista->pUltimo->pProx = aux;
    lista->pUltimo = aux;
    lista->tam++;

}
void removePalavraLe(TListaLLe *texto, TListaPLe *lista){
    //nao sei como vai ser o criterio de remocao
}
void imprimeTextoLe(TListaPLe *lista){
    TCelulaP *aux = lista->pPrimeiro;
    while(aux->pProx != NULL){
        imprimePalavraLe(&aux->palavra);
        aux = aux->pProx;
    }
}
int tamanhoTextoLe(TListaPLe *lista){
    return lista->tam;
}

