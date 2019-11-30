//
// Created by lazarus on 21/11/19.
//

#include "Biblioteca.h"

//Operacoes por arranjo
void inicializaBiblioArr(TListaTArr *lista){
    lista->biblioteca = (TListaPArr*) malloc(10* sizeof(TListaPArr));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
void insereTextoArr(TListaTArr *lista){
    TListaPArr texto;
    for(int i = 0; i < 10; i++){
        inicializaTextoArr(&texto);
        inserePalavraArr(&texto, 10);
        lista->biblioteca[lista->ultimo] = texto;
        lista->ultimo++;
    }
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

void imprimeBibliotecaArr(TListaTArr *lista){
    for (int i = 0; i < lista->ultimo; i++){
        imprimeTextoArr(&(lista->biblioteca[i]));
        printf("Texto n \n");
    }
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
    int al = rand()%26;
    for(int i = 0; i < tam; i++) {
        al = 1 + rand()%26;
        aux = (TCelulaT *) malloc(sizeof(TCelulaT));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        inicializaTextoLe(&(aux->texto));
        inserePalavraLe(&(aux->texto), al);
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
void imprimeBibliotecaLe(TListaTLe *biblioteca){
    TCelulaT* aux = biblioteca->pPrimeiro->pProx;
    while (aux != NULL){
        imprimeTextoLe(&(aux->texto));
        printf(" Texto %d\n", aux->texto.tam);
        aux = aux->pProx;
    }

}

int tamanhoBibliotecaLe(TListaTLe *lista){
    return lista->tam;
}

void selectionSortBibLe(TListaTLe lista){
    TCelulaT *aux, *aux2;
    TCelulaT* min = lista.pPrimeiro;
    TListaPLe texto, textoaux;

    for (int i = 0; i < lista.tam - 1; i++){
        min = min->pProx;
        texto = min->texto;
        aux = min->pProx;
        aux2 = min;
        for (int j = i + 1; j < lista.tam; j++){
            if (texto.tam > aux->texto.tam){
                texto = aux->texto;
                aux2 = aux;
            }
            aux = aux->pProx;
        }
        textoaux = min->texto;
        min->texto = texto;
        aux2->texto = textoaux;
    }
    imprimeBibliotecaLe(&lista);
}
