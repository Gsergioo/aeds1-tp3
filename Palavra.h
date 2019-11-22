//
// Created by lazarus on 21/11/19.
//

//T-Item -----------
typedef struct {
    char *letra;
    char primLetra;
}TPalavra;

//Lista Encadeada
typedef struct CelulaP{
    struct CelulaP *pProx;
    TPalavra palavra;
}TCelulaP;

typedef struct {
    int tam;
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
void inicializaPArr(TListaPArr *lista);
void insereLetraArr(char letra, TListaPArr *lista, int i);
int removeLetraArr(TListaPArr *lista, int pos);
void imprimePalavraArr(TListaPArr *lista);
int tamanhoPalavraArr(TListaPArr *lista);

//Operacoes por Lista Encadeada
void inicializaPLe(TCelulaP *celula, TListaPLe *lista);
void insereLetraLe(TCelulaP *celula, TListaPLe *lista, char letra);
void removeLetraLe(TPalavra *palavra, TCelulaP *celula);
void imprimePalavraLe(TListaPLe *lista);
int tamanhoPalavraLe(TListaPLe *lista);