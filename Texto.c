//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"
#include <stdlib.h>
#include <stdio.h>

//Operacoes por arranjo

void inicializaTextoArr(TListaPArr *lista){
    lista->texto = (TPalavra*) malloc(45*sizeof(TPalavra));
    lista->primeiro = 0;
    lista->ultimo = 0;
}
void inserePalavraArr(TPalavra *texto, TListaPArr *lista){
    lista->texto[lista->ultimo] = *texto;
    lista->ultimo++;
}
void removePalavraArr(TPalavra *texto, TListaPArr *lista){
    //nao sei como vai ser a remoção
}
void imprimeTextoArr(TListaLArr *letras,TListaPArr *listaPalavra){ //muito provavel que ta errado, mas vida que segue. Depois arruma
    for (int i = listaPalavra->primeiro; i < listaPalavra->ultimo; ++i) {
        imprimePalavraArr(letras);
    }
    printf("\n");
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
void inserePalavraLe(TPalavra *texto, TListaPLe *lista){
    TCelulaP *aux = NULL;
    aux = (TCelulaP*) malloc(sizeof(TCelulaP));
    aux->pProx = NULL;
    aux->texto = *texto;
    lista->pUltimo->pProx = aux;
    lista->pUltimo = aux;
    lista->tam++;

}
void removePalavraLe(TPalavra *texto, TListaPLe *lista){
    //nao sei como vai ser o criterio de remocao
}
void imprimeTextoLe(TListaLLe *listaLLe, TListaPLe *lista){
    TCelulaP *aux = lista->pPrimeiro;
    while(aux->pProx != NULL){
        imprimePalavraLe(listaLLe);
        aux = aux->pProx;
    }
}
int tamanhoTextoLe(TPalavra texto, TListaPLe *lista){
    return lista->tam;
}

