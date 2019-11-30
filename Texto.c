//
// Created by lazarus on 21/11/19.
//

#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"
#include "Texto.h"
#include <time.h>

//Operacoes por arranjo

void inicializaTextoArr(TListaPArr *lista){
    lista->palavra = (TListaLArr*) malloc(10*sizeof(TListaLArr));
    lista->primeiro = 0;
    lista->ultimo = 0;
}
void inserePalavraArr(TListaPArr *lista, int tam){
    inicializaTextoArr(lista);
    TListaLArr palavra;
    for(int i = 0; i < tam; i++){
        inicializaPArr(&palavra);
        insereLetraArr(&palavra);
        lista->palavra[lista->ultimo] = palavra;
        lista->ultimo++;
    }
}
void removePalavraArr(TListaPArr *lista){
    if(lista->ultimo > 0){
        printf(YEL"----> Palavra removida: " RESET);
        imprimePalavraArr(&lista->palavra[lista->ultimo-1]);
        lista->ultimo--;
        printf("\n");
    } else
        printf(YEL"----> Não é possível remover!\n" RESET);
}
void imprimeTextoArr(TListaPArr *listaPalavra){ //muito provavel que ta errado, mas vida que segue. Depois arruma
    for (int i = listaPalavra->primeiro; i < listaPalavra->ultimo; i++) {
        imprimePalavraArr(&listaPalavra->palavra[i]);
    }
}
int tamanhoTextoArr(TListaPArr *lista){
    return lista->ultimo;
}

void selectionSortArr(TListaPArr texto){
    int min, i, j;
    TListaLArr aux;
    for(i = 0; i < texto.ultimo - 1; i++){
        min = i;
        for(j = i + 1; j < texto.ultimo; j++)
            if (texto.palavra[min].primeiraletra > texto.palavra[j].primeiraletra)
                min = j;
        aux = texto.palavra[i];
        texto.palavra[i] = texto.palavra[min];
        texto.palavra[min] = aux;
    }
    imprimeTextoArr(&texto);
}

void quicksortTextoArr(TListaPArr textoo)
{
    ordenaTextoArr(0, textoo.ultimo - 1, &textoo);
    imprimeTextoArr(&textoo);
}

void ordenaTextoArr(int esq, int dir, TListaPArr *texto){
    int i, j;
    particaoTextoArr(esq, dir, &i, &j, texto);

    if (esq < j) ordenaTextoArr(esq, j, texto);
    if (i < dir) ordenaTextoArr(i, dir, texto);
}

void particaoTextoArr(int esq, int dir, int* i, int* j, TListaPArr* texto){
    char pivo;
    TListaLArr aux;
    *i = esq; *j = dir;
    pivo = texto->palavra[(esq + dir)/2].primeiraletra;
    do{
        while(pivo > texto->palavra[*i].primeiraletra) (*i)++;
        while(pivo < texto->palavra[*j].primeiraletra) (*j)--;
        if (*i <= *j){
            aux = texto->palavra[*i]; texto->palavra[*i] = texto->palavra[*j]; texto->palavra[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
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
    inicializaTextoLe(lista);
    TCelulaP *aux = NULL;
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        aux = (TCelulaP*) malloc(sizeof(TCelulaP));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        inicializaPLe(&(aux->palavra));
        insereLetraLe(&(aux->palavra)); //gera palavras aleatorias
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        lista->tam++;
        aux->indice = lista->tam;
    }
}
void removePalavraLe(TListaPLe *lista){
    TCelulaP *aux;
    if(lista->tam > 0) {
        aux = lista->pUltimo;
        lista->pUltimo = lista->pUltimo->pAnte;
        lista->pUltimo->pProx = NULL;
        printf(YEL"----> Palavra removida: " RESET);
        imprimePalavraLe(&aux->palavra); //n sei se vai funcionar
        printf("\n");
        lista->tam--;
        free(aux);
    } else
        printf(YEL"----> Não é possível remover!\n"RESET);
}
void imprimeTextoLe(TListaPLe *lista){
    TCelulaP *aux = lista->pPrimeiro->pProx;
    while(aux != NULL){
        imprimePalavraLe(&aux->palavra);
        aux = aux->pProx;
    }
}
int tamanhoTextoLe(TListaPLe *lista){
    return lista->tam;
}

void ordenaTexto(TCelulaP* esq, TCelulaP* dir, TListaPLe *texto, double *comp){
    TCelulaP *i, *j;
    particaoTexto(esq, dir, &i, &j, texto, comp);


    if(esq->indice < j->indice) ordenaTexto(esq, j, texto, comp);
    if(dir->indice > i->indice) ordenaTexto(i, dir, texto, comp);
}


void quicksortTexto(TListaPLe texto){
    double comp;
    comp = 0;
    ordenaTexto(texto.pPrimeiro->pProx, texto.pUltimo, &texto, &comp);
    printf("\n\n comp: %lf\n", comp);
    imprimeTextoLe(&texto);
}

void particaoTexto(TCelulaP* esq, TCelulaP* dir, TCelulaP** ii, TCelulaP** jj, TListaPLe* texto, double *comp){
    int pivo;
    int cont1, cont2;
    TCelulaP* i;
    TCelulaP* j;
    cont1 = esq->indice;
    cont2 = dir->indice;
    TCelulaP* aux = texto->pPrimeiro->pProx;
    i = esq;
    j = dir;
    for(int k = 1; k < ((int)(i->indice + j->indice)/2); k++)
        aux = aux->pProx;
    pivo = aux->palavra.primeiraletra;
    printf("pivo: %c ", pivo);
    do{
        while(i->palavra.primeiraletra < pivo) {i = i->pProx; cont1++; (*comp)++;}
        while (j->palavra.primeiraletra > pivo){ j = j->pAnte; cont2--; (*comp)++;}

        (*comp)++;
        if(cont1 <= cont2){
            trocaTexto(i, j);
            i = i->pProx;
            cont1++;
            cont2--;
            j = j->pAnte;
        }
    }while(cont1 <= cont2);
    *comp = *comp * 2;
    *ii = i;
    *jj = j;
}

void trocaTexto(TCelulaP* i, TCelulaP* j){
    TListaLLe aux;
    aux = i->palavra;
    i->palavra = j->palavra;
    j->palavra = aux;
}

void selectionSort(TListaPLe texto){
    imprimeTextoLe(&texto);
    printf("%d", texto.tam);
    TCelulaP *aux, *aux2;
    TCelulaP* min = texto.pPrimeiro;

    TListaLLe palavra, palavraaux;
    for (int i = 0; i < texto.tam - 1; i++){
        min = min->pProx;
        palavra = min->palavra;
        aux = min->pProx;
        aux2 = min;
        for (int j = i + 1; j < texto.tam; j++){
            if (palavra.primeiraletra > aux->palavra.primeiraletra){
                palavra = aux->palavra;
                aux2 = aux;
            }
            aux = aux->pProx;
        }
        palavraaux = min->palavra;
        min->palavra = palavra;
        aux2->palavra = palavraaux;
    }
    printf("\n");
    imprimeTextoLe(&texto);
}
