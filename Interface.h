//
// Created by lazarus on 22/11/19.
//

#include "Biblioteca.h"

void interface();
void printFuncPalavra();
void printFuncTexto();
void printFuncBiblio();
int inicializaListas(int opcED, int opcTad, TListaLLe *palavraLe, TListaLArr *palavraArr, TListaPLe *textoLe, TListaPArr *textoArr, TListaTLe *bibliLe, TListaTArr *bibliArr, TListaPLe *textoCopiaLe, TListaPArr *textoCopiaArr, TListaTLe *bibCopiaLe, TListaTArr *bibCopiaArr);
void configura(int *opcED, int *opcTad, int *opcQtdTextos, int *minPala, int *maxPala, int *opcOrd);
