//
// Created by lazarus on 22/11/19.
//

#include "Biblioteca.h"

void interface();
void printFuncPalavra();
void printFuncTexto(int *tamTexto);
void printFuncBiblio(int *tamBiblio);
void inicializaListas(int opcED, int opcTad, TListaLLe *palaLe, TListaLArr *palaArr, TListaPLe *texLe, TListaPArr *texArr, TListaTLe *bibLe, TListaTArr *bibArr);
void configura(int *opcED, int *opcTad, int *opcQtdTextos, int *opcQtdPalavr, int *opcOrd);