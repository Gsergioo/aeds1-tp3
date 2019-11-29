//
// Created by lazarus on 21/11/19.
//

#include "Texto.h"


//Operacoes por arranjo

void inicializaTextoArr(TListaPArr *lista){
    lista->palavra = (TListaLArr*) malloc(10*sizeof(TListaLArr));
    lista->primeiro = 0;
    lista->ultimo = 0;
}
void inserePalavraArr(TListaPArr *lista){
    TListaLArr palavra;
    int tam = 0 + rand()%100; // Gera o tamanho aleatorio do texto
    for(int i = 0; i < 10; i++){
        inicializaPArr(&palavra);
        insereLetraArr(&palavra);
        lista->palavra[lista->ultimo] = palavra;
        lista->ultimo++;
    }
}
void removePalavraArr(TListaLArr *palavra, TListaPArr *lista){
    //nao sei como vai ser a remoção
}
void imprimeTextoArr(TListaPArr *listaPalavra){ //muito provavel que ta errado, mas vida que segue. Depois arruma
    for (int i = listaPalavra->primeiro; i < listaPalavra->ultimo; i++) {
        imprimePalavraArr(&(listaPalavra->palavra[i]));
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
    lista->pPrimeiro->pAnte = NULL;
    lista->tam = 0;
    lista->pPrimeiro->indice = -1;
}
void inserePalavraLe(TListaPLe *lista, int tam){
    TCelulaP *aux = NULL;
    for(int i = 0; i <= tam; i++){
        aux = (TCelulaP*) malloc(sizeof(TCelulaP));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        inicializaPLe(&(aux->palavra));
        insereLetraLe(&aux->palavra); //gera palavras aleatorias
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        lista->tam++;
        aux->indice = lista->tam;
    }
}
void removePalavraLe(TListaLLe *texto, TListaPLe *lista){
    //nao sei como vai ser o criterio de remocao
}
void imprimeTextoLe(TListaPLe *lista){
    TCelulaP *aux = lista->pPrimeiro->pProx;
    while(aux->pProx != NULL){
        imprimePalavraLe(&aux->palavra);
        aux = aux->pProx;
    }
}
int tamanhoTextoLe(TListaPLe *lista){
    return lista->tam;
}

void ordenaTexto(TCelulaP* esq, TCelulaP* dir, TListaPLe *texto){
    TCelulaP *i, *j;
    particaoTexto(esq, dir, &i, &j, texto);

    if(esq->indice < j->indice) ordenaTexto(esq, j, texto);
    if(dir->indice > i->indice) ordenaTexto(i, dir, texto);
}


void quicksortTexto(TListaPLe* texto){
    ordenaTexto(texto->pPrimeiro->pProx, texto->pUltimo, texto);
}

void particaoTexto(TCelulaP* esq, TCelulaP* dir, TCelulaP** ii, TCelulaP** jj, TListaPLe* texto){
    int pivo;
    int cont1, cont2;
    cont1 = esq->indice;
    cont2 = dir->indice;
    TCelulaP* aux = texto->pPrimeiro->pProx;
    TCelulaP* i = esq;
    TCelulaP* j = dir;
    for(int k = 1; k < ((int)(i->indice + j->indice)/2); k++)
        aux = aux->pProx;
    pivo = aux->palavra.primeiraletra;
    printf("pivo: %c ", pivo);
    do{
        while(i->palavra.primeiraletra < pivo) {i = i->pProx; cont1++;}
        while (j->palavra.primeiraletra > pivo){ j = j->pAnte; cont2--;}
        if(cont1 <= cont2){
            trocaTexto(i, j);
            i = i->pProx;
            cont1++;
            cont2--;
            j = j->pAnte;
        }
    }while(cont1 <= cont2);
    *ii = i;
    *jj = j;
}

void trocaTexto(TCelulaP* i, TCelulaP* j){
    TListaLLe aux;
    aux = i->palavra;
    i->palavra = j->palavra;
    j->palavra = aux;
}
