//
// Created by lazarus on 21/11/19.
//

#include "Biblioteca.h"
#include <stdlib.h>
//Operacoes por arranjo
void inicializaArr(TListaTArr *lista){
    lista->biblioteca = (TListaPArr*) malloc(lista->biblioteca->ultimo * sizeof(TListaPArr));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
void insereTextoArr(TListaPArr *texto, TListaTArr *lista){
    lista->biblioteca[lista->ultimo] = *texto;
    lista->ultimo++;
}
void removeTextoArr(TListaPArr *texto, TListaTArr *lista){
    //n sei como sera
}
int tamanhoBibliotecaArr(TListaTArr *lista){
    return lista->ultimo;
}

//Operacoes por lista encadeada
void inicializaLe(TListaTLe *lista){
    lista->pPrimeiro = (TCelulaT*) malloc(sizeof(TCelulaT));
    lista->pPrimeiro->pProx = NULL;
    lista->pUltimo = lista->pPrimeiro;
}
void insereTextoLe(TListaPLe *texto, TListaTLe *lista){
    TCelulaT *aux;
    aux = (TCelulaT*) malloc(sizeof(TCelulaT));
    lista->pUltimo = aux;
    lista->pUltimo->pProx = NULL;
    lista->pUltimo->texto = *texto;
    lista->tam++;
}
void removeTextoLe(TListaPLe *texto, TListaTLe *lista){
    //n sei como vai ser
}
int tamanhoBibliotecaLe(TListaTLe *lista){
    return lista->tam;
}