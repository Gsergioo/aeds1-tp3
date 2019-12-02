//
// Created by lazarus on 21/11/19.
//

#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"
#include "Texto.h"
#include <time.h>

//Operacoes por arranjo

void inicializaTextoArr(TListaPArr *lista, int qtdPalavras){
    lista->palavra = (TListaLArr*) malloc(qtdPalavras*sizeof(TListaLArr));
    lista->primeiro = 0;
    lista->ultimo = 0;
}
void inserePalavraArr(TListaPArr *lista, int min, int max){
    int intervalo = min + rand()%(max+1-min);
    inicializaTextoArr(lista, intervalo);
    TListaLArr palavra;
    for(int i = 0; i < intervalo; i++){
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
void imprimeTextoArr(TListaPArr *listaPalavra){
    if(listaPalavra->ultimo <= 50) {
        for (int i = 0; i < listaPalavra->ultimo; i++) {
            imprimePalavraArr(&listaPalavra->palavra[i]);
        }
    } else {
        for (int i = 0; i < 50; i++) {
            imprimePalavraArr(&listaPalavra->palavra[i]);
        }
        printf("[...]\n");
    }
}
int tamanhoTextoArr(TListaPArr *lista){
    return lista->ultimo;
}

void selectionSortTextoArr(TListaPArr texto){
    if(texto.ultimo != 0) {
        double comp = 0, mov = 0;
        int min, i, j;
        clock_t tempo;
        TListaLArr aux;

        tempo = clock();
        for (i = 0; i < texto.ultimo - 1; i++) {
            min = i;
            for (j = i + 1; j < texto.ultimo; j++) {
                comp++;
                if (texto.palavra[min].primeiraletra > texto.palavra[j].primeiraletra) {
                    min = j;
                }
            }
            aux = texto.palavra[i];
            texto.palavra[i] = texto.palavra[min];
            texto.palavra[min] = aux;
            mov++;
        }
        tempo = clock() - tempo;

        system("clear");
        imprimeTextoArr(&texto);
        printf("\n");
        printf(YEL"\n-----------------> SelectionSort Arranjo <-----------------\n");
        printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n", comp);
        printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n", mov);
        printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n", ((double) tempo) / CLOCKS_PER_SEC);
    }else
        printf(YEL"----> Nada a ordenar!\n"RESET);
}

void quicksortTextoArr(TListaPArr textoo)
{
    double comp, mov;
    clock_t tempo;

    tempo = clock();
    ordenaTextoArr(0, textoo.ultimo - 1, &textoo, &comp, &mov);
    tempo = clock() - tempo;

    system("clear");
    imprimeTextoArr(&textoo);
    printf(YEL"\n-----------------> QuickSort Arranjo <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);

}

void ordenaTextoArr(int esq, int dir, TListaPArr *texto, double* comp, double* mov){
    int i, j;
    particaoTextoArr(esq, dir, &i, &j, texto, comp, mov);

    (*comp)++;
    if (esq < j)
        ordenaTextoArr(esq, j, texto, comp, mov);
    (*comp)++;
    if (i < dir)
        ordenaTextoArr(i, dir, texto, comp, mov);
}

void particaoTextoArr(int esq, int dir, int* i, int* j, TListaPArr* texto, double* comp, double* mov){
    char pivo;
    TListaLArr aux;
    *i = esq; *j = dir;
    pivo = texto->palavra[(esq + dir)/2].primeiraletra;
    do{
        (*comp)++;
        while(pivo > texto->palavra[*i].primeiraletra) {
            (*i)++;
            (*comp)++;
        }

        (*comp)++;
        while(pivo < texto->palavra[*j].primeiraletra) {
            (*j)--;
            (*comp)++;
        }

        (*comp)++;
        if (*i <= *j){
            (*mov)++;
            aux = texto->palavra[*i];
            texto->palavra[*i] = texto->palavra[*j]; texto->palavra[*j] = aux;
            (*i)++;
            (*j)--;
        }
        (*comp)++;
    }while(*i <= *j);
}

void criaCopiaTextoArr(TListaPArr* lista, TListaPArr* listacopia){
    inicializaTextoArr(listacopia, lista->ultimo);
    for (int i = 0; i < lista->ultimo; i++){
        listacopia->palavra[i] = lista->palavra[i];
        listacopia->ultimo = lista->ultimo;
    }
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
void inserePalavraLe(TListaPLe *lista, int min, int max){
    inicializaTextoLe(lista);
    TCelulaP *aux = NULL;
    int intervalo = min + rand()%(max - min + 1);
    for(int i = 0; i < intervalo; i++){
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
        imprimePalavraLe(&aux->palavra);
        printf("\n");
        lista->tam--;
        free(aux);
    } else
        printf(YEL"----> Não é possível remover!\n"RESET);
}
void imprimeTextoLe(TListaPLe *lista){
    TCelulaP *aux = lista->pPrimeiro->pProx;
    if(lista->tam <= 50) {
        while (aux != NULL) {
            imprimePalavraLe(&aux->palavra);
            aux = aux->pProx;
        }
    } else{
        int i = 0;
        while (i != 50) {
            imprimePalavraLe(&aux->palavra);
            aux = aux->pProx;
            i++;
        }
        printf("[...]\n");
    }
}
int tamanhoTextoLe(TListaPLe *lista){
    return lista->tam;
}

void ordenaTexto(TCelulaP* esq, TCelulaP* dir, TListaPLe *texto, double *comp, double* mov){
    TCelulaP *i, *j;
    particaoTexto(esq, dir, &i, &j, texto, comp, mov);

    (*comp)++;
    if(esq->indice < j->indice)
        ordenaTexto(esq, j, texto, comp, mov);
    (*comp)++;
    if(dir->indice > i->indice)
        ordenaTexto(i, dir, texto, comp, mov);
}


void quicksortTextoLe(TListaPLe texto){
    double comp = 0, mov = 0;
    clock_t tempo;

    tempo = clock();
    ordenaTexto(texto.pPrimeiro->pProx, texto.pUltimo, &texto, &comp, &mov);//tava sem o &mov
    tempo = clock() - tempo;

    system("clear");
    imprimeTextoLe(&texto);
    printf(YEL"\n-----------------> QuickSort Lista Encadeada <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);
}

void particaoTexto(TCelulaP* esq, TCelulaP* dir, TCelulaP** ii, TCelulaP** jj, TListaPLe* texto, double *comp, double* mov){
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
    do{
        (*comp)++;
        while(i->palavra.primeiraletra < pivo) {
            i = i->pProx; cont1++;
            (*comp)++;
        }
        (*comp)++;
        while (j->palavra.primeiraletra > pivo){
            j = j->pAnte; cont2--;
            (*comp)++;
        }

        (*comp)++;
        if(cont1 <= cont2){
            trocaTexto(i, j);
            (*mov)++;
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

void selectionSortTextoLe(TListaPLe texto){
    double comp = 0, mov = 0;
    clock_t tempo;
    TCelulaP *aux, *aux2;
    TCelulaP* min = texto.pPrimeiro;

    TListaLLe palavra, palavraaux;

    tempo = clock();
    for (int i = 0; i < texto.tam - 1; i++){
        min = min->pProx;
        palavra = min->palavra;
        aux = min->pProx;
        aux2 = min;
        for (int j = i + 1; j < texto.tam; j++){
            comp++;
            if (palavra.primeiraletra > aux->palavra.primeiraletra){
                palavra = aux->palavra;
                aux2 = aux;
            }
            aux = aux->pProx;
        }
        palavraaux = min->palavra;
        min->palavra = palavra;
        aux2->palavra = palavraaux;
        mov++;
    }
    tempo = clock() - tempo;

    system("clear");
    imprimeTextoLe(&texto);
    printf(YEL"\n-----------------> SelectionSort Lista Encadeada<-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);
}

void criaCopiaTextoLe(TListaPLe* lista, TListaPLe* listacopia){
    inicializaTextoLe(listacopia);
    listacopia->tam = lista->tam;
    TCelulaP *aux, *aux2;
    aux2 = lista->pPrimeiro->pProx;
    while(aux2 != NULL){
        aux = (TCelulaP*)malloc(sizeof(TCelulaP));
        aux->palavra = aux2->palavra;
        aux->indice = aux2->indice;
        aux->pProx = NULL;
        aux->pAnte = listacopia->pUltimo;
        listacopia->pUltimo->pProx = aux;
        listacopia->pUltimo = aux;
        aux2 = aux2->pProx;
    }
}
