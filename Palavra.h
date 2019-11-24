//
// Created by lazarus on 21/11/19.
//

//T-Item -----------
typedef struct {
    char letra;
}Tletra;  //O item é uma letra que contem uma letra, não faz muito sentido.

//Lista Encadeada
typedef struct CelulaL{ //celula contendo uma letra
    struct CelulaL *pProx;
    Tletra letra;
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
}TListaLArr;

//Operacoes por Arranjo
void inicializaPArr(TListaLArr *lista);
void insereLetraArr(Tletra letra, TListaLArr *lista);
int removeLetraArr(TListaLArr *lista, int pos);
void imprimePalavraArr(TListaLArr *lista);
int tamanhoPalavraArr(TListaLArr *lista);

//Operacoes por Lista Encadeada
void inicializaPLe(TListaLLe *lista);
void insereLetraLe(TListaLLe *lista, Tletra letra);
void removeLetraLe(Tletra *letra, TCelulaL *celula);
void imprimePalavraLe(TListaLLe *lista);
int tamanhoPalavraLe(TListaLLe *lista);
