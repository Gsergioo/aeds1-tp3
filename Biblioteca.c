//
// Created by lazarus on 21/11/19.
//

#include "Biblioteca.h"
#include <time.h>

//Operacoes por arranjo
void inicializaBiblioArr(TListaTArr *lista, int qtdTextos){
    lista->biblioteca = (TListaPArr*) malloc(qtdTextos * sizeof(TListaPArr));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
void insereTextoArr(TListaTArr *lista,  int qtdtexto, int min, int max){
    TListaPArr texto;
    inicializaBiblioArr(lista, qtdtexto);
    for(int i = 0; i < qtdtexto; i++){
        inicializaTextoArr(&texto, qtdtexto);
        inserePalavraArr(&texto, min, max);
        lista->biblioteca[lista->ultimo] = texto;
        lista->ultimo++;
    }
}
void removeTextoArr(TListaTArr *lista){
    if(lista->ultimo > 0){
        printf(YEL"----> Último texto removido!\n" RESET);
        imprimeTextoArr(&lista->biblioteca[lista->ultimo]);
        lista->ultimo--;
    } else
        printf(YEL"----> Não é possível remover!\n" RESET);
}
int tamanhoBibliotecaArr(TListaTArr *lista){
    return lista->ultimo;
}

void imprimeBibliotecaArr(TListaTArr *lista){
    if(lista->ultimo <= 50){
        for (int i = 0; i < lista->ultimo; i++) {
            printf(YEL"----> Texto"RESET " %d!\n", i + 1);
            imprimeTextoArr(&(lista->biblioteca[i]));
            printf("\n");
        }
    } else {
        for (int i = 0; i < 50; i++) {
            printf(YEL"----> Texto"RESET " %d!\n", i + 1);
            imprimeTextoArr(&(lista->biblioteca[i]));
            printf("\n");
        }
        printf("[...]\n");
    }
}

void selectionSortBibArr(TListaTArr lista, int flag){
    double comp = 0, mov = 0;
    int min, i, j;
    clock_t tempo;
    TListaPArr aux;
    tempo = clock();
    for(i = 0; i < lista.ultimo - 1; i++){
        min = i;
        for(j = i + 1; j < lista.ultimo; j++)
            if (lista.biblioteca[min].ultimo > lista.biblioteca[j].ultimo){
                min = j;
                comp++;
            }
        aux = lista.biblioteca[i];
        lista.biblioteca[i] = lista.biblioteca[min];
        lista.biblioteca[min] = aux;
        mov++;
    }
    tempo = clock() - tempo;

    if(flag) {
        system("clear");
        printf(YEL"----> Texto Ordenado: "RESET);
        imprimeBibliotecaArr(&lista);
    }
    printf(YEL"\n-----------------> SelectionSort Arranjo <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf!\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf!\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos!\n",((double)tempo)/CLOCKS_PER_SEC);
}

void quicksortBibArr(TListaTArr lista, int flag)
{
    double comp = 0, mov = 0;
    clock_t  tempo;

    tempo = clock();
    ordenaBibArr(0, lista.ultimo - 1, &lista, &comp, &mov);
    tempo = clock() - tempo;

    if(flag) {
        system("clear");
        printf(YEL"----> Texto Ordenado: "RESET);
        imprimeBibliotecaArr(&lista);
    }
    printf(YEL"\n-----------------> QuickSort Arranjo <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);
}

void ordenaBibArr(int esq, int dir, TListaTArr *lista, double* comp, double* mov){
    int i, j;
    particaoBibArr(esq, dir, &i, &j, lista, comp,  mov);

    (*comp)++;
    if (esq < j)
        ordenaBibArr(esq, j, lista, comp, mov);
    (*comp)++;
    if (i < dir)
        ordenaBibArr(i, dir, lista, comp, mov);
}

void particaoBibArr(int esq, int dir, int* i, int* j, TListaTArr* lista, double* comp, double* mov){
    char pivo;
    TListaPArr aux;
    *i = esq; *j = dir;
    pivo = lista->biblioteca[(esq + dir)/2].ultimo;
    do{
        (*comp)++; //verificacao antes de entrar no while
        while(pivo > lista->biblioteca[*i].ultimo){
            (*i)++; (*comp)++;
        }

        (*comp)++; //verificacao antes de entrar no while
        while(pivo < lista->biblioteca[*j].ultimo){
            (*j)--; (*comp)++;
        }

        (*comp)++;
        if (*i <= *j){
            (*mov)++;
            aux = lista->biblioteca[*i];
            lista->biblioteca[*i] = lista->biblioteca[*j];
            lista->biblioteca[*j] = aux;
            (*i)++;
            (*j)--;
        }
        (*comp)++; //comparacao do while
    }while(*i <= *j);
}

void criaCopiaBibArr(TListaTArr* lista, TListaTArr* listacopia, int qtdTexto){
    inicializaBiblioArr(listacopia, qtdTexto);
    for (int i = 0; i < lista->ultimo; i++){
        listacopia->biblioteca[i] = lista->biblioteca[i];
        listacopia->ultimo = lista->ultimo;
    }
}


//----------------------------------------------------------------------------------

//Operacoes por lista encadeada
void inicializaBiblioLe(TListaTLe *lista){
    lista->pPrimeiro = (TCelulaT*) malloc(sizeof(TCelulaT));
    lista->pPrimeiro->pProx = NULL;
    lista->pPrimeiro->pAnte = NULL;
    lista->pUltimo = lista->pPrimeiro;
    lista->tam = 0;
    lista->pPrimeiro->indice = -1;
}
void insereTextoLe(TListaTLe *lista, int qtdtexto, int min, int max){
    TCelulaT *aux;
    inicializaBiblioLe(lista);
    for(int i = 0; i < qtdtexto; i++) {
        aux = (TCelulaT *) malloc(sizeof(TCelulaT));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        inicializaTextoLe(&(aux->texto));
        inserePalavraLe(&(aux->texto), min, max);
        lista->tam++;
        aux->indice = lista->tam;
    }
}
void removeTextoLe(TListaTLe *lista){
    if(lista->tam > 0) {
        TCelulaT *aux;
        aux = lista->pUltimo;
        lista->pUltimo = lista->pUltimo->pAnte;
        printf(YEL"----> Texto"RESET" (%d)", lista->tam);
        printf(YEL" removido!\n" RESET);
        lista->tam--;
        lista->pUltimo->pProx = NULL;
        free(aux);
    } else{
        printf(YEL"----> Não é possível remover!\n" RESET);
    }
}
void imprimeBibliotecaLe(TListaTLe *biblioteca){
    TCelulaT* aux = biblioteca->pPrimeiro->pProx;
    int i = 1;
    if(biblioteca->tam <= 50) {
        while (aux != NULL) {
            printf(YEL" ----> Texto "RESET"%d!\n", i);
            imprimeTextoLe(&(aux->texto));
            aux = aux->pProx;
            i++;
            printf("\n");
        }
    } else{
        while (i != 50) {
            printf(YEL" ----> Texto "RESET"%d!\n", i);
            imprimeTextoLe(&(aux->texto));
            aux = aux->pProx;
            i++;
            printf("\n");
        }
        printf("[...]\n");
    }
    if(biblioteca->tam == 0)
        printf(YEL"----> Não há textos! :(\n"RESET);

}

int tamanhoBibliotecaLe(TListaTLe *lista){
    return lista->tam;
}

void selectionSortBibLe(TListaTLe lista, int flag){
    double comp = 0, mov = 0;
    clock_t tempo;
    TCelulaT *aux, *aux2;
    TCelulaT* min = lista.pPrimeiro;
    TListaPLe texto, textoaux;

    tempo = clock();
    for (int i = 0; i < lista.tam - 1; i++){
        min = min->pProx;
        texto = min->texto;
        aux = min->pProx;
        aux2 = min;
        for (int j = i + 1; j < lista.tam; j++){
            comp++;
            if (texto.tam > aux->texto.tam){
                texto = aux->texto;
                aux2 = aux;
            }
            aux = aux->pProx;
        }
        textoaux = min->texto;
        min->texto = texto;
        aux2->texto = textoaux;
        mov++;
    }
    tempo = clock() - tempo;

    if(flag) {
        system("clear");
        printf(YEL"----> Texto Ordenado: "RESET);
        imprimeBibliotecaLe(&lista);
    }
    printf(YEL"\n-----------------> SelectionSort Lista Encadeada <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);
}

void ordenaBibLe(TCelulaT* esq, TCelulaT* dir, TListaTLe *lista, double *comp, double* mov){
    TCelulaT *i, *j;
    particaoBibLe(esq, dir, &i, &j, lista, comp, mov);

    (*comp)++;
    if(esq->indice < j->indice)
        ordenaBibLe(esq, j, lista, comp, mov);

    (*comp)++;
    if(dir->indice > i->indice)
        ordenaBibLe(i, dir, lista, comp, mov);
}


void quicksortBibLe(TListaTLe lista, int flag){
    double comp = 0, mov = 0;
    clock_t tempo;

    tempo = clock();
    ordenaBibLe(lista.pPrimeiro->pProx, lista.pUltimo, &lista, &comp, &mov);
    tempo = clock() - tempo;

    if(flag) {
        system("clear");
        printf(YEL"----> Texto Ordenado: "RESET);
        imprimeBibliotecaLe(&lista);
    }
    printf(YEL"\n-----------------> QuickSort Lista Encadeada <-----------------\n");
    printf(YEL"----> Numero de comparacoes: "RESET"%.0lf\n",comp);
    printf(YEL"----> Numero de movimentacoes: "RESET"%.0lf\n",mov);
    printf(YEL"----> Tempo de execucao: "RESET"%lf segundos\n",((double)tempo)/CLOCKS_PER_SEC);
}

void particaoBibLe(TCelulaT* esq, TCelulaT* dir, TCelulaT** ii, TCelulaT** jj, TListaTLe* lista, double *comp, double* mov){
    int pivo;
    int cont1, cont2;
    TCelulaT* i;
    TCelulaT* j;
    cont1 = esq->indice;
    cont2 = dir->indice;
    TCelulaT* aux = lista->pPrimeiro->pProx;
    i = esq;
    j = dir;
    for(int k = 1; k < ((int)(i->indice + j->indice)/2); k++)
        aux = aux->pProx;
    pivo = aux->texto.tam;
//    printf("pivo: %d ", pivo);
    do{
        (*comp)++; //conta como verificacao entrando no while ou nao
        while(i->texto.tam < pivo) {
            i = i->pProx; cont1++;
            (*comp)++;
        }
        (*comp)++; //conta como verificacao entrando no while ou nao
        while (j->texto.tam > pivo){
            j = j->pAnte; cont2--;
            (*comp)++;
        }

        (*comp)++; //conta como comparacao entrando no if ou nao
        if(cont1 <= cont2){
            (*mov)++;
            trocaBibLe(i, j);
            i = i->pProx;
            cont1++;
            cont2--;
            j = j->pAnte;
        }
        (*comp)++; //verificar se vai rodar de novo
    }while(cont1 <= cont2);
    *ii = i;
    *jj = j;
}

void trocaBibLe(TCelulaT* i, TCelulaT* j){
    TListaPLe aux;
    aux = i->texto;
    i->texto = j->texto;
    j->texto = aux;
}

void criaCopiaBibLe(TListaTLe* lista, TListaTLe* listacopia, int qtdTexto){
    inicializaBiblioLe(listacopia);
    listacopia->tam = lista->tam;
    TCelulaT *aux, *aux2;
    aux2 = lista->pPrimeiro->pProx;
    while(aux2 != NULL){
        aux = (TCelulaT*)malloc(sizeof(TCelulaT));
        aux->texto= aux2->texto;
        aux->indice = aux2->indice;
        aux->pProx = NULL;
        aux->pAnte = listacopia->pUltimo;
        listacopia->pUltimo->pProx = aux;
        listacopia->pUltimo = aux;
        aux2 = aux2->pProx;
    }
}
