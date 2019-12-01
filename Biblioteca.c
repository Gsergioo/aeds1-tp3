//
// Created by lazarus on 21/11/19.
//

#include "Biblioteca.h"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

//Operacoes por arranjo
void inicializaBiblioArr(TListaTArr *lista){
    lista->biblioteca = (TListaPArr*) malloc(10* sizeof(TListaPArr));
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}
void insereTextoArr(TListaTArr *lista, int qtdPalavras, int qtdTexto){
    TListaPArr texto;
    inicializaBiblioArr(lista);
    for(int i = 0; i < qtdTexto; i++){
        inicializaTextoArr(&texto, qtdPalavras);
        inserePalavraArr(&texto, qtdPalavras);
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
    for (int i = 0; i < lista->ultimo; i++){
        printf(YEL"----> Texto"RESET " %d!\n",i+1);
        imprimeTextoArr(&(lista->biblioteca[i]));
        printf("\n");
    }
}

void selectionSortBibArr(TListaTArr lista){
    int min, i, j;
    TListaPArr aux;
    for(i = 0; i < lista.ultimo - 1; i++){
        min = i;
        for(j = i + 1; j < lista.ultimo; j++)
            if (lista.biblioteca[min].ultimo > lista.biblioteca[j].ultimo)
                min = j;
        aux = lista.biblioteca[i];
        lista.biblioteca[i] = lista.biblioteca[min];
        lista.biblioteca[min] = aux;
    }
    imprimeBibliotecaArr(&lista);
}

void quicksortBibArr(TListaTArr lista)
{
    ordenaBibArr(0, lista.ultimo - 1, &lista);
    imprimeBibliotecaArr(&lista);
}

void ordenaBibArr(int esq, int dir, TListaTArr *lista){
    int i, j;
    particaoBibArr(esq, dir, &i, &j, lista);

    if (esq < j) ordenaBibArr(esq, j, lista);
    if (i < dir) ordenaBibArr(i, dir, lista);
}

void particaoBibArr(int esq, int dir, int* i, int* j, TListaTArr* lista){
    char pivo;
    TListaPArr aux;
    *i = esq; *j = dir;
    pivo = lista->biblioteca[(esq + dir)/2].ultimo;
    do{
        while(pivo > lista->biblioteca[*i].ultimo) (*i)++;
        while(pivo < lista->biblioteca[*j].ultimo) (*j)--;
        if (*i <= *j){
            aux = lista->biblioteca[*i]; lista->biblioteca[*i] = lista->biblioteca[*j]; lista->biblioteca[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
}

void criaCopiaBibArr(TListaTArr* lista, TListaTArr* listacopia){
    inicializaBiblioArr(listacopia);
    for (int i = 0; i < lista->ultimo; i++){
        listacopia->biblioteca[i] = lista->biblioteca[i];
        listacopia->ultimo = lista->ultimo;
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
    inicializaBiblioLe(lista);
    //int al;
    for(int i = 0; i < tam2; i++) {
        //al = 1 + rand()%26;
        aux = (TCelulaT *) malloc(sizeof(TCelulaT));
        aux->pProx = NULL;
        aux->pAnte = lista->pUltimo;
        lista->pUltimo->pProx = aux;
        lista->pUltimo = aux;
        inicializaTextoLe(&(aux->texto));
        inserePalavraLe(&(aux->texto), tam);
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
    while (aux != NULL){
        printf(YEL"----> Texto"RESET " %d!\n",i);
        imprimeTextoLe(&(aux->texto));
        aux = aux->pProx;
        i++;
        printf("\n");
    }
    if(biblioteca->tam == 0)
        printf(YEL"----> Não há textos! :(\n"RESET);

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

void ordenaBibLe(TCelulaT* esq, TCelulaT* dir, TListaTLe *lista, double *comp){
    TCelulaT *i, *j;
    particaoBibLe(esq, dir, &i, &j, lista, comp);


    if(esq->indice < j->indice) ordenaBibLe(esq, j, lista, comp);
    if(dir->indice > i->indice) ordenaBibLe(i, dir, lista, comp);
}


void quicksortBibLe(TListaTLe lista){
    double comp;
    comp = 0;
    ordenaBibLe(lista.pPrimeiro->pProx, lista.pUltimo, &lista, &comp);
    printf("\n\n comp: %lf\n", comp);
    imprimeBibliotecaLe(&lista);
}

void particaoBibLe(TCelulaT* esq, TCelulaT* dir, TCelulaT** ii, TCelulaT** jj, TListaTLe* lista, double *comp){
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
    printf("pivo: %d ", pivo);
    do{
        while(i->texto.tam < pivo) {i = i->pProx; cont1++; (*comp)++;}
        while (j->texto.tam > pivo){ j = j->pAnte; cont2--; (*comp)++;}

        (*comp)++;
        if(cont1 <= cont2){
            trocaBibLe(i, j);
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

void trocaBibLe(TCelulaT* i, TCelulaT* j){
    TListaPLe aux;
    aux = i->texto;
    i->texto = j->texto;
    j->texto = aux;
}
