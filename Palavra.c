//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"
#include <stdlib.h>
#include <stdio.h>

//Operacoes por Arranjo
void inicializaPArr(TListaLArr *palavra){
    palavra->letra = (Tletra*) malloc(45 * sizeof(Tletra));
    palavra->primeiro = 0;
    palavra->ultimo = palavra->primeiro;
}

void insereLetraArr(TListaLArr *lista){ //Cria palavras aleatorias
    int tam = rand()%44;
    for(int i = 0; i < tam; i++){
        lista->letra[i].letra = 'a' + rand()%26;
        lista->ultimo++;
    }
}

int removeLetraArr(TListaLArr *lista, int pos){
    if(pos <= lista->ultimo && pos >= lista->primeiro) {
        for (int i = pos + 1; i < lista->ultimo; i++) {
            lista->letra[i - 1] = lista->letra[i];
        }
        lista->ultimo--;
        return 1;
    } else
        return 0;
}
void imprimePalavraArr(TListaLArr *lista){
    for (int i = 0; i < lista->ultimo; i++)
        printf("%c", lista->letra[i].letra);
    printf(" ");
}

int tamanhoPalavraArr(TListaLArr *lista){
    return lista->ultimo;
}

//-------------------------------------------------------------------------------------


//Operacoes por Lista Encadeada


void inicializaPLe(TListaLLe *lista){
    lista->pPrimeiro = (TCelulaL*) malloc(sizeof(TCelulaL));
    lista->pUltimo = lista->pPrimeiro;
    lista->pUltimo->pProx = NULL;
    lista->tam = 0;
}

void insereLetraLe(TListaLLe *lista){ //Cria palavras aleatorias
    TCelulaL *aux;
    int tam = rand()%45;
    for(int i = 0; i < tam; i++){
        aux = (TCelulaL*) malloc(sizeof(TCelulaL));
        aux->pProx = NULL;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = lista->pUltimo->pProx; //faz a ligação entre celulas
        lista->pUltimo->letra.letra = 'a' + rand()%26; //insere a letra
    }
    lista->primeiraletra = lista->pPrimeiro->pProx->letra.letra ; //armazena a primeira letra
    lista->tam++;
}

void removeLetraLe(Tletra *letra, TCelulaL *celula){
    //nao sei se e pra remover uma letra inserida e procurar pela primeira ocorrencia
    //nao sei se e pra remover uma posicao especifica
    //nao sei se e pra remover a ultima/primeira letra
}
void imprimePalavraLe(TListaLLe *lista){
    TCelulaL *aux;
    aux = lista->pPrimeiro->pProx;
    while(aux->pProx != NULL){
        printf("%c", aux->letra.letra);
        aux = aux->pProx;
    }
    printf(" ");
}
int tamanhoPalavraLe(TListaLLe *lista){
    return lista->tam;
}
