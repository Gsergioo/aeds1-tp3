//
// Created by lazarus on 21/11/19.
//

#include "Biblioteca.h"
#include <stdlib.h>
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"
//Operacoes por arranjo
void inicializaBiblioArr(TListaTArr *lista){
    lista->biblioteca = (TListaPArr*) malloc(lista->biblioteca->ultimo * sizeof(TListaPArr));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
void insereTextoArr(TListaTArr *lista){
//    lista->biblioteca[lista->ultimo] = *texto;
//    lista->ultimo++;
    printf("Inserida!");
}
void removeTextoArr(TListaTArr *lista){
    if(lista->ultimo > 0){
        printf(YEL"----> Texto removido: " RESET);
        imprimeTextoArr(&lista->biblioteca[lista->ultimo]);
        lista->ultimo--;
    } else
        printf(YEL"----> Não é possível remover!" RESET);
}
int tamanhoBibliotecaArr(TListaTArr *lista){
    return lista->ultimo;
}

//Operacoes por lista encadeada
void inicializaBiblioLe(TListaTLe *lista){
    lista->pPrimeiro = (TCelulaT*) malloc(sizeof(TCelulaT));
    lista->pPrimeiro->pProx = NULL;
    lista->pPrimeiro->pAnte = NULL;
    lista->pUltimo = lista->pPrimeiro;
    lista->tam = 0;
    lista->pPrimeiro->indice = -1;
}
void insereTextoLe(TListaTLe *lista, int tam, int tam2){
    TCelulaT *aux;
    for(int i = 0; i < tam; i++) {
        aux = (TCelulaT *) malloc(sizeof(TCelulaT));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        inicializaTextoLe(&(aux->texto));
        inserePalavraLe(&(aux->texto), tam2);
        lista->tam++;
        aux->indice = lista->tam;
    }
}
void removeTextoLe(TListaTLe *lista){
    if(lista->tam > 0) {
        TCelulaT *aux;
        aux = lista->pUltimo;
        lista->pUltimo = lista->pUltimo->pAnte;
        printf(YEL"----> Último texto removido!" RESET);
        free(aux);
    } else{
        printf(YEL"----> Não é possível remover!" RESET);
    }
}
int tamanhoBibliotecaLe(TListaTLe *lista){
    return lista->tam;
}