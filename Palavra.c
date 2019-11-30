//
// Created by lazarus on 21/11/19.
//

#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"
#include "Palavra.h"


//Operacoes por Arranjo
void inicializaPArr(TListaLArr *palavra){
    palavra->primeiro = 0;
    palavra->ultimo = palavra->primeiro;
    palavra->letra = (Tletra*) malloc(45* sizeof(char));
}
void insereLetraArr(TListaLArr *lista){
    inicializaPArr(lista);
    int tam = 1+rand()%44;
    for(int i = 0; i < tam; i++){
        lista->letra[i].letra = 'a' + rand()%26;
        lista->ultimo++;
    }
}

void removeLetraArr(TListaLArr *lista){
    if(lista->ultimo > 0){
        printf(YEL"----> Letra removida! " RESET "%c\n", lista->letra[lista->ultimo-1].letra);
        lista->ultimo--;
    } else
        printf(YEL"----> Não é possível remover!\n" RESET);
}

void imprimePalavraArr(TListaLArr *lista){
    for (int i = 0; i < lista->ultimo; i++)
        printf("%c", lista->letra[i].letra);
    printf(" ");
}

int tamanhoPalavraArr(TListaLArr *lista){
    return lista->ultimo;
}

//-------------------------------------------------------------------------------------                                          h
                                                                                                                               //e
//Operacoes por Lista Encadeada                                                                                                  l
                                                                                                                               //p
                                                                                                                               //!
void inicializaPLe(TListaLLe *lista){
    lista->pPrimeiro = (TCelulaL*) malloc(sizeof(TCelulaL));
    lista->pUltimo = lista->pPrimeiro;
    lista->pPrimeiro->indice = -1;
    lista->pUltimo->pProx = NULL;
    lista->pPrimeiro->pAnte = NULL;
    lista->tam = 0;
}
void insereLetraLe(TListaLLe *lista){
    inicializaPLe(lista);
    TCelulaL *aux;
    int tam = rand()%45;
    for(int i = 0; i < tam; i++){
        aux = (TCelulaL*) malloc(sizeof(TCelulaL));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = lista->pUltimo->pProx; //faz a ligação entre celulas
        lista->pUltimo->letra.letra = 'a' + rand()%26; //insere a letra
        if(lista->pPrimeiro->pProx == lista->pUltimo)   lista->primeiraletra = lista->pPrimeiro->pProx->letra.letra ; //armazena a primeira letra
        lista->tam++;
        lista->pUltimo->indice = lista->tam;
    }
}
void removeLetraLe(TListaLLe *lista){
    TCelulaL *aux;
    if(lista->tam > 0) {
        aux = lista->pUltimo;
        lista->pUltimo = lista->pUltimo->pAnte;
        lista->pUltimo->pProx = NULL;
        printf(YEL"----> Letra removida: " RESET "%c\n",aux->letra.letra);
        free(aux);
        lista->tam--;
    } else
        printf(YEL"----> Não é possível remover!\n"RESET);
}
void imprimePalavraLe(TListaLLe *lista){
    TCelulaL *aux;
    aux = lista->pPrimeiro->pProx;
    while(aux != NULL){
        printf("%c", aux->letra.letra);
        aux = aux->pProx;
    }
    printf(" ");
}
int tamanhoPalavraLe(TListaLLe *lista){
    return lista->tam;
}

