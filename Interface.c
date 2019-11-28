//
// Created by lazarus on 22/11/19.
//

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>


void printFuncPalavra(){
    printf(GRN"\n           TAD Palavra!           \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"    |OPERAÇÕES|" RED              "          |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾" RED             "          |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Imprimir palavra" RED"            |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Tamanho da palavra" RED"          |\n" RESET);
    printf(RED "|"RESET BLU" (5)"RESET " Sair" RED"          |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncTexto(int *tamTexto){
    printf(GRN"\n            TAD Texto!            \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU " Insira o tamanho dos textos: "RESET);
    scanf("%d", tamTexto);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "        |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir palavra" RED"                 |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover palavra" RED"                 |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Tamanho do texto" RED"          |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Sair" RED"          |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncBiblio(int *tamBiblio){
    printf(GRN"\n          TAD Biblioteca!          \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU " Insira o tamanho da biblioteca: ");
    scanf("%d", tamBiblio);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "        |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED             "              |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Tamanho da biblioteca" RED"       |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Sair" RED"          |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}
//---------------------------------------------------------------------------------------------

void interface(){
    int opcTad = 0;
    int opcED = 0;
    int opcQtdTextos = 0;
    int opcQtdPalavr = 0;
    int opcOrd = 0;

    int tamTexto;
    int tamBibli;

    int opcOperacao = 0;

    //-----palavra
    Tletra letra;
    TListaLLe palavraLe;
    TListaLArr palavraArr;

    //-----texto
    TListaPLe textoLe;
    TListaPArr textoArr;

    //-----biblioteca
    TListaTLe bibliLe;
    TListaTArr bibliArr;


    system("clear");
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
    printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED"|"RESET"  Escolha o TAD a ser utilizado"RED              "  |\n"RESET);
    printf(RED "|"RESET BLU" (1)"RESET " TAD Palavra" RED"                 |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " TAD Texto" RED"                   |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " TAD Biblioteca" RED"              |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);
    scanf("%d",&opcTad);
    system("clear");


    system("clear");
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
    printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);
    scanf("%d", &opcED);
    system("clear");


    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
    printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED"|"RESET"  Escolha a quantidade de palavras"RED   "   |\n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU "Tamanho: " RESET);
    scanf("%d",&opcQtdPalavr);
    system("clear");



    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
    printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED"|"RESET"  Escolha a quantidade de textos"RED     "   |\n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU "Tamanho: " RESET);
    scanf("%d",&opcQtdTextos);
    system("clear");


    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
    printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);
    scanf("%d",&opcOrd);
    system("clear");

    //-----------inicializacao das estruturas---------------

    if(opcED == 1){
        if(opcTad == 1) {
            printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
            inicializaPLe(&palavraLe);
        }else
            if(opcTad == 2) {
                inicializaTextoLe(&textoLe);
                printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
            }
            else
                if(opcTad == 3) {
                    inicializaBiblioLe(&bibliLe);
                    printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
                }
    }else
        if(opcED == 2){

            if(opcTad == 1) {
                inicializaPArr(&palavraArr);
                printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
            }else
            if(opcTad == 2) {
                inicializaTextoArr(&textoArr);
                printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
            }else
            if(opcTad == 3) {
                inicializaBiblioArr(&bibliArr);
                printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
            }
        }


//---------------------------------------------------------------------------------------------
do {
    switch (opcTad) {
        case 1: {//tad palavra
            if (opcED == 1) { //lista encadeada
                printFuncPalavra();
                scanf("%d", &opcOperacao);
                if (opcOperacao == 1) { //inserir letra LE
                    insereLetraLe(&palavraLe);
                } else if (opcOperacao == 2) { //remover letra LE
                    int pos = 0;
                    printf("Posicao a ser removida: ");
                    scanf("%d", &pos);
                    if (pos <= palavraLe.tam && palavraLe.tam > 0)
                        printf("Removidah!");
                        //removeLetraLe(&palavraLe, pos);
                    else
                        printf("Nao é possivel remover!");
                } else if (opcOperacao == 3) {
                    imprimePalavraLe(&palavraLe);
                    break;
                } else if(opcOperacao == 4){
                    printf("%d", tamanhoPalavraLe(&palavraLe));
                    break;
                }else if(opcOperacao == 5){
                    system("clear");
                }else {
                    printf("Invalido");
                    break;
                }
            } else if (opcED == 2) {//arranjo
                printFuncPalavra();
                scanf("%d", &opcOperacao);
                if (opcOperacao == 1) { //inserir letra LE
                    insereLetraArr(&palavraArr);
                    //imprimePalavraArr(&palavraArr);
                    break;
                } else if (opcOperacao == 2) { //remover letra LE
                    int pos = 0;
                    printf("Posicao a ser removida: ");
                    scanf("%d", &pos);
                    if (pos <= palavraArr.ultimo && palavraArr.ultimo > 0)
                        printf("Removidah!");
                        //removeLetraLe(&palavraLe, pos);
                    else
                        printf("Nao é possivel remover!");
                } else if (opcOperacao == 3) {
                    imprimePalavraArr(&palavraArr);
                } else if (opcOperacao == 4) {
                    printf("%d", tamanhoPalavraArr(&palavraArr));
                } else if (opcOperacao == 5) {
                    break;
                } else {
                    printf("Invalido");
                    break;
                }
            }
                break;
            }
            case 2: {//tad texto
                printFuncTexto(&tamTexto);
                scanf("%d", &opcOperacao);
                if (opcOperacao == 1) {
                    printf("1");
                } else if (opcOperacao == 2) {
                    printf("2");
                } else if (opcOperacao == 3) {
                    printf("3");
                } else
                    printf("Invalido");
            }
            case 3: {//tad biblioteca
                printFuncBiblio(&tamBibli);
            }
        }
    }while (opcED != 0);
}