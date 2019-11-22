//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"
#include <stdlib.h>
#include <stdio.h>

//Operacoes por Arranjo
void inicializaPArr(TListaPArr *lista){
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
    lista->palavra->letra = (char*) malloc(45* sizeof(char));
}
void insereLetraArr(char letra, TListaPArr *lista, int i){
    lista->palavra->letra[i] = letra;
    lista->ultimo++;
    lista->palavra->primLetra = lista->palavra->letra[0];
}
int removeLetraArr(TListaPArr *lista, int pos){
    if(pos <= lista->ultimo) {
        for (int i = pos + 1; i < lista->ultimo; i++) {
            lista->palavra->letra[i - 1] = lista->palavra->letra[i];
        }
        lista->ultimo--;
        return 1;
    } else
        return 0;
}
void imprimePalavraArr(TListaPArr *lista){
        printf("%s",lista->palavra->letra);
        printf(" ");
}
int tamanhoPalavraArr(TListaPArr *lista){
    return lista->ultimo;
}

//-------------------------------------------------------------------------------------


//Operacoes por Lista Encadeada


void inicializaPLe(TCelulaP *celula, TListaPLe *lista){
    lista->pPrimeiro = (TCelulaP*) malloc(sizeof(TCelulaP));
    lista->pUltimo = lista->pPrimeiro;
    lista->pUltimo->pProx = NULL;
}
void insereLetraLe(TCelulaP *celula, TListaPLe *lista, char letra){
    TCelulaP *aux;
    aux = (TCelulaP*) malloc(sizeof(TCelulaP));
    aux->pProx = NULL;
    lista->pUltimo->pProx = aux;
    lista->pUltimo = lista->pUltimo->pProx; //faz a ligação entre celulas
    *lista->pUltimo->palavra.letra = letra; //insere a letra
    lista->pPrimeiro->pProx->palavra.primLetra = *lista->pPrimeiro->pProx->palavra.letra; //armazena a primeira letra
    lista->tam++;

}
void removeLetraLe(TPalavra *palavra, TCelulaP *celula){
    //nao sei se e pra remover uma letra inserida e procurar pela primeira ocorrencia
    //nao sei se e pra remover uma posicao especifica
    //nao sei se e pra remover a ultima/primeira letra
}
void imprimePalavraLe(TListaPLe *lista){
    TCelulaP *aux;
    aux = lista->pPrimeiro->pProx;
    while(aux->pProx != NULL){
        printf("%c", *aux->palavra.letra);
        aux = aux->pProx;
    }
    printf(" ");
}
int tamanhoPalavraLe(TListaPLe *lista){
    return lista->tam;
}
