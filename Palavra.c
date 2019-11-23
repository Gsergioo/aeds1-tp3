//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"
#include <stdlib.h>
#include <stdio.h>

//Operacoes por Arranjo
void inicializaPArr(TListaPArr *palavra){
    palavra->primeiro = 0;
    palavra->ultimo = palavra->primeiro;
    palavra->letra = (char*) malloc(45* sizeof(char));
}
void insereLetraArr(Tletra letra, TListaPArr *lista){
    if(lista->ultimo != 45){
        lista->letra[lista->ultimo] = letra;
        lista->ultimo++;
    }
    if(lista->ultimo - 1 == 0){
        lista->primeiraletra = letra.letra;
    }
}
int removeLetraArr(TListaPArr *lista, int pos){
    if(pos <= lista->ultimo && pos >= lista->primeiro) {
        for (int i = pos + 1; i < lista->ultimo; i++) {
            lista->letra[i - 1] = lista->letra[i];
        }
        lista->ultimo--;
        return 1;
    } else
        return 0;
}
void imprimePalavraArr(TListaPArr *lista){
    for (int i = 0; i < lista->ultimo; i++)
        printf("%c", lista->letra[i].letra);
    printf(" ");
}

int tamanhoPalavraArr(TListaPArr *lista){
    return lista->ultimo;
}

//-------------------------------------------------------------------------------------


//Operacoes por Lista Encadeada


void inicializaPLe(TListaPLe *lista){
    lista->pPrimeiro = (TCelulaP*) malloc(sizeof(TCelulaP));
    lista->pUltimo = lista->pPrimeiro;
    lista->pUltimo->pProx = NULL;
    lista->tam = 0;
}
void insereLetraLe(TListaPLe *lista, Tletra letra){
    TCelulaP *aux;
    aux = (TCelulaP*) malloc(sizeof(TCelulaP));
    aux->pProx = NULL;
    lista->pUltimo->pProx = aux;
    lista->pUltimo = lista->pUltimo->pProx; //faz a ligação entre celulas
    lista->pUltimo->letra = letra; //insere a letra
    lista->primeiraletra = lista->pPrimeiro->pProx->letra.letra ; //armazena a primeira letra
    lista->tam++;

}
void removeLetraLe(Tletra *letra, TCelulaP *celula){
    //nao sei se e pra remover uma letra inserida e procurar pela primeira ocorrencia
    //nao sei se e pra remover uma posicao especifica
    //nao sei se e pra remover a ultima/primeira letra
}
void imprimePalavraLe(TListaPLe *lista){
    TCelulaP *aux;
    aux = lista->pPrimeiro->pProx;
    while(aux->pProx != NULL){
        printf("%c", aux->letra.letra);
        aux = aux->pProx;
    }
    printf(" ");
}
int tamanhoPalavraLe(TListaPLe *lista){
    return lista->tam;
}
