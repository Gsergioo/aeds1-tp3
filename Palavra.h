//
// Created by lazarus on 21/11/19.
//

//T-Item -----------
typedef struct {
    char letra;
}TPalavra;

//Lista Encadeada
typedef struct CelulaP{
    struct CelulaP *pProx;
    TPalavra letra;
}TCelulaP;

typedef struct {
    TCelulaP *pPrimeiro;
    TCelulaP *pUltimo;
}TListaPLe;

//Arranjo
typedef struct {
    TPalavra *palavra;
    int primeiro;
    int ultimo;
}TListaPArr;

//Operacoes por Arranjo
void inicializaPArr(TPalavra *palavra, TListaPArr *lista);
void insereLetraArr(TPalavra *palavra, TListaPArr *lista);
void removeLetraArr(TPalavra *palavra, TListaPArr *lista);
void imprimePalavraArr(TPalavra palavra, TListaPArr *lista);
int tamanhoPalavraArr(TPalavra palavra, TListaPArr *lista);

//Operacoes por Lista Encadeada
void inicializaPLe(TPalavra *palavra, TCelulaP *celula);
void insereLetraLe(TPalavra *palavra, TCelulaP *celula);
void removeLetraLe(TPalavra *palavra, TCelulaP *celula);
void imprimePalavraLe(TPalavra palavra, TCelulaP *celula);
int tamanhoPalavraLe(TPalavra palavra, TCelulaP *celula);