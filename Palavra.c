//
// Created by lazarus on 21/11/19.
//

#include "Palavra.h"


//Operacoes por Arranjo
void inicializaPArr(TListaLArr *palavra){
    palavra->primeiro = 0;
    palavra->ultimo = palavra->primeiro;
    palavra->letra = (Tletra*) malloc(45* sizeof(char));
}
void insereLetraArr(TListaLArr *lista){
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
    lista->pPrimeiro->indice = -1;
    lista->pUltimo->pProx = NULL;
    lista->pPrimeiro->pAnte = NULL;
    lista->tam = 0;
}
void insereLetraLe(TListaLLe *lista){
    TCelulaL *aux;
    int tam = rand()%10;
    for(int i = 0; i < 10; i++){
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
void removeLetraLe(Tletra *letra, TCelulaL *celula){
    //nao sei se e pra remover uma letra inserida e p+rocurar pela primeira ocorrencia
    //nao sei se e pra remover uma posicao especifica
    //nao sei se e pra remover a ultima/primeira letra
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

void ordena(TCelulaL* esq, TCelulaL* dir, TListaLLe *lista){
    TCelulaL* i;
    TCelulaL* j;
    particao(esq, dir, &i, &j, lista);
    printf("indice i: %c ", i->letra);
    printf("indice j : %c ", j->letra);

    if(esq->indice < j->indice) ordena(esq, j, lista);
    if(dir->indice > i->indice) ordena(i, dir, lista);
}


void quicksort(TListaLLe *lista){
    ordena(lista->pPrimeiro->pProx, lista->pUltimo, lista);
}

void particao(TCelulaL* esq, TCelulaL* dir, TCelulaL** ii, TCelulaL** jj, TListaLLe* lista){
    char pivo;
    int cont1, cont2;
    cont1 = esq->indice;
    cont2 = dir->indice;
    TCelulaL* aux = lista->pPrimeiro->pProx;
    TCelulaL* i = esq;
    TCelulaL* j = dir;
    int tam = (cont1 + cont2)/2;
    for(int k = 1; k < (tam); k++)
        aux = aux->pProx;
    pivo = aux->letra.letra;
    printf("pivo: %c", pivo);
    do{
        while(i->letra.letra < pivo) {i = i->pProx; cont1++;}
        while (j->letra.letra > pivo){ j = j->pAnte; cont2--;}
        if(cont1 <= cont2){
            troca(i, j);
            i = i->pProx;
            cont1++;
            cont2--;
            j = j->pAnte;
        }
    }while(cont1 <= cont2);
    *ii = i;
    *jj = j;
}

void troca(TCelulaL* i, TCelulaL* j){
    char aux;
    aux = i->letra.letra;
    i->letra.letra = j->letra.letra;
    j->letra.letra = aux;
}
