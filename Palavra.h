//
// Created by lazarus on 21/11/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//T-Item -----------
typedef struct {
    char letra;
}Tletra;  //O item é uma letra que contem uma letra, não faz muito sentido.

//Lista Encadeada
typedef struct CelulaL{ //celula contendo uma letra
    struct CelulaL *pProx, *pAnte; //duplamente encadeada
    Tletra letra;
    int indice;
}TCelulaL;

typedef struct {
    int tam;
    char primeiraletra;
    TCelulaL *pPrimeiro;
    TCelulaL *pUltimo;
}TListaLLe;

//Arranjo
typedef struct {
    Tletra *letra;
    char primeiraletra;
    int primeiro;
    int ultimo;
}TListaLArr; //Palavra

//Operacoes por Arranjo
void inicializaPArr(TListaLArr *lista);
void insereLetraArr(TListaLArr *lista);
void removeLetraArr(TListaLArr *lista);
void imprimePalavraArr(TListaLArr *lista);
int tamanhoPalavraArr(TListaLArr *lista);

//Operacoes por Lista Encadeada
void inicializaPLe(TListaLLe *lista);
void insereLetraLe(TListaLLe *lista);
void removeLetraLe(TListaLLe *celula);
void imprimePalavraLe(TListaLLe *lista);
int tamanhoPalavraLe(TListaLLe *lista);
