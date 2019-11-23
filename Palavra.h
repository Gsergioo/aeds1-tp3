//
// Created by lazarus on 21/11/19.
//

//T-Item -----------
typedef struct {
    char letra;
}Tletra;  //O item é uma letra que contem uma letra, não faz muito sentido.

//Lista Encadeada
typedef struct CelulaP{
    struct CelulaP *pProx;
    Tletra letra;
}TCelulaP;

typedef struct {
    int tam;
    char primeiraletra;
    TCelulaP *pPrimeiro;
    TCelulaP *pUltimo;
}TListaPLe;

//Arranjo
typedef struct {
    Tletra *letra;
    char primeiraletra;
    int primeiro;
    int ultimo;
}TListaPArr;

//Operacoes por Arranjo
void inicializaPArr(TListaPArr *lista);
void insereLetraArr(Tletra letra, TListaPArr *lista);
int removeLetraArr(TListaPArr *lista, int pos);
void imprimePalavraArr(TListaPArr *lista);
int tamanhoPalavraArr(TListaPArr *lista);

//Operacoes por Lista Encadeada
void inicializaPLe(TListaPLe *lista);
void insereLetraLe(TListaPLe *lista, Tletra letra);
void removeLetraLe(Tletra *letra, TCelulaP *celula);
void imprimePalavraLe(TListaPLe *lista);
int tamanhoPalavraLe(TListaPLe *lista);
