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
#include <time.h>


void printFuncPalavra(){
    printf(GRN"\n           TAD Palavra!           \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"    |OPERAÇÕES|" RED              "          |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾" RED             "          |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Imprimir palavra" RED"            |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Tamanho da palavra" RED"          |\n" RESET);
    printf(RED "|"RESET BLU" (5)"RESET " Sair" RED"                        |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncTexto(){
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "         |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir palavra" RED"             |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover palavra" RED"             |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Tamanho do texto" RED"            |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Imprime texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (5)"RESET " Ordena Texto" RED"                |\n" RESET);
    printf(RED "|"RESET BLU" (6)"RESET " Sair" RED"                        |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncBiblio(){
    printf(RED "-----------------------------------\n"                          RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "         |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Tamanho da biblioteca" RED"       |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Imprimir a biblioteca" RED"       |\n" RESET);
    printf(RED "|"RESET BLU" (5)"RESET " Ordenar biblioteca" RED"          |\n" RESET);
    printf(RED "|"RESET BLU" (6)"RESET " Sair" RED"                        |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}
void inicializaListas(int opcED, int opcTad, TListaLLe *palavraLe, TListaLArr *palavraArr, TListaPLe *textoLe, TListaPArr *textoArr, TListaTLe *bibliLe, TListaTArr *bibliArr){
    if(opcED == 1){
        if(opcTad == 1) {
            printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
            inicializaPLe(palavraLe);
        }else
        if(opcTad == 2) {
            inicializaTextoLe(textoLe);
            printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
        }
        else
        if(opcTad == 3) {
            inicializaBiblioLe(bibliLe);
            printf(GRN"----> LISTA ENCADEADA!    \n"RESET);
        }
    }else
    if(opcED == 2){

        if(opcTad == 1) {
            inicializaPArr(palavraArr);
            printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
        }else
        if(opcTad == 2) {
            inicializaTextoArr(textoArr, 1);
            printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
        }else
        if(opcTad == 3) {
            inicializaBiblioArr(bibliArr);
            printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
        }
    }

}

void configura(int *opcED, int *opcTad, int *opcQtdTextos, int *minPala, int *maxPala, int *opcOrd){
    do {
        printf(RED "-----------------------------------\n" RESET);
        printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
        printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
        printf(RED"|"RESET"  Escolha o TAD a ser utilizado"RED              "  |\n"RESET);
        printf(RED "|"RESET BLU" (1)"RESET " TAD Palavra" RED"                 |\n" RESET);
        printf(RED "|"RESET BLU" (2)"RESET " TAD Texto" RED"                   |\n" RESET);
        printf(RED "|"RESET BLU" (3)"RESET " TAD Biblioteca" RED"              |\n" RESET);
        printf(RED "|"RESET BLU" (4)"RESET " Sair" RED"                        |\n" RESET);
        printf(RED "-----------------------------------\n"                          RESET);
        printf(BLU "Opção: " RESET);
        scanf("%d", opcTad);

        if(*opcTad > 4 || *opcTad < 1) {
            system("cls");
            printf(YEL"----> Insira uma opção válida!\n" RESET);
        } else
            system("cls");
    }while (*opcTad > 4 || *opcTad < 1);
    if(*opcTad == 1) {
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcED);

            if(*opcED > 2 || *opcED < 1) {
                system("cls");
                printf(YEL"----> Insira uma opção válida!\n" RESET);
            } else
                system("cls");
        } while (*opcED < 1 || *opcED > 2);
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
            printf(RED "|"RESET BLU" (3)"RESET " Ambos" RED"                       |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcOrd);
            system("cls");
            if(*opcOrd > 3 || *opcOrd < 1) {
                system("cls");
                printf(YEL"----> Insira uma opção válida!\n" RESET);
            } else
                system("cls");
        }while (*opcOrd < 1 || *opcOrd > 3);
    } else
    if(*opcTad == 2){
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcED);
            system("cls");
            if(*opcED > 4 || *opcED < 1) {
                system("cls");
                printf(YEL"----> Insira uma opção válida!\n" RESET);
            } else
                system("cls");
        }while (*opcED > 4 || *opcED <1);
        do {
            system("cls");
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET" Quantidade de palavras"RED   "           |\n"RESET);
            printf(RED "-----------------------------------\n" RESET);
            printf(BLU "Quantidade Minima: " RESET);
            scanf("%d", minPala);
            printf(BLU "Quantidade Máxima: " RESET);
            scanf("%d", maxPala);
            system("cls");
            if(*minPala < 1) {
                system("cls");
                printf(YEL"----> Insira uma quantidade válida!\n" RESET);
            }else
                system("cls");
        }while(*minPala < 1);
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcOrd);
            system("cls");
            if (*opcOrd > 2 || *opcOrd < 1) {
                system("cls");
                printf(YEL"----> Insira uma opção válida!\n" RESET);
            } else
                system("cls");
        }while(*opcOrd > 2 || *opcOrd < 1);
    }else
    if(*opcTad == 3){
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcED);
            system("cls");
            if(*opcED > 2 || *opcED < 1) {
                printf(YEL"----> Insira uma opção válida!\n" RESET);
            } else
                system("cls");
        }while (*opcED > 2 || *opcED < 1);
        do {
            system("cls");
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET" Quantidade de palavras"RED   "           |\n"RESET);
            printf(RED "-----------------------------------\n" RESET);
            printf(BLU "Quantidade Minima: " RESET);
            scanf("%d", minPala);
            printf(BLU "Quantidade Máxima: " RESET);
            scanf("%d", maxPala);
            system("cls");
            if(*minPala < 1) {
                system("cls");
                printf(YEL"----> Insira uma quantidade válida!\n" RESET);
            }else
                system("cls");
        }while(*minPala < 1);
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"      Quantidade de textos"RED     "       |\n"RESET);
            printf(RED "-----------------------------------\n" RESET);
            printf(BLU "Quantidade: " RESET);
            scanf("%d", opcQtdTextos);
            system("cls");
            if(*opcQtdTextos < 1) {
                system("cls");
                printf(YEL"----> Insira uma quantidade válida!\n" RESET);
            } else
                system("cls");
        }while (*opcQtdTextos < 1);
        do {
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcOrd);
            system("cls");
            if(*opcOrd > 2 || *opcOrd < 1) {
                printf(YEL"----> Insira uma opção válida!\n" RESET);
                system("cls");
            } else
                system("cls");
        }while(*opcOrd > 2 || *opcOrd < 1);
    }else
    if(*opcTad == 4){
        system("cls");
        printf("\n");
        printf("\n");
        printf(YEL"                     ---FIM DE EXECUCAO!---\n"RESET);
        printf("\n");
        printf("\n");
        exit(1);
    }else {
        printf("\n");
        printf("\n");
        printf(YEL"                         OPCAO INVALIDA!\n"RESET);
        printf(YEL"                     ---FIM DE EXECUCAO!---\n"RESET);
        printf("\n");
        printf("\n");
        exit(1);
    }
}
//
//void printComparacaoAlgOrd(clock_t tempoQuick, clock_t tempoSelect, int qtdMovQ, int qtdMovS, int qtdComQ, int qtdComS){
//    printf(BLU "-------------------------------------------------------------\n"RESET);
//    printf(BLU"|"RESET YEL"  Algoritmos  | N Comp| N Mov|   Tempo  |"RESET);
//    printf(BLU"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾|‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|"RESET);
//    printf(BLU"|              |       |       |          |"RESET);
//    printf(BLU"|"RESET YEL"  QuickSort   "BLU"|          |                |              |"RESET);
//    printf(BLU"|              |       |       |              |"RESET);
//    printf(BLU"|              |       |       |              |"RESET);
//    printf(BLU"|‾‾‾‾‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾| ‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾‾‾‾‾|"RESET);
//    printf(BLU"|              |       |                |              |"RESET);
//    printf(BLU"|"RESET YEL"  SelectSort  "BLU"|              |                |              |"RESET);
//    printf(BLU"|              |       |       |              |"RESET);
//    printf(BLU"|              |       |       |              |"RESET);
//    printf(BLU "-------------------------------------------------------------\n"RESET);
//}

//---------------------------------------------------------------------------------------------

void interface(){
    system("cls");
    int opcTad = 0; //qual tad a ser utilizado
    int opcED = 0;  //qual estrutura de dados
    int opcQtdTextos = 0; //quantidade de textos -> biblioteca
    //int opcQtdPalavr = 0; //quantidade de palavras -> texto
    int opcOrd = 0;      //qual alg de orde
    int opcOperacao = 0; //operacao do tad

    int maxTamPalav = 0;// vai servir pra poder o usuario
    int minTamPalav = 0;// inserir o intervalo da qtd de palavras

    clock_t tempoQuick = 0, tempoSelect = 0;
    int qtdMovQ = 0, qtdMovS = 0, qtdComQ = 0;
    int qtdComS = 0;

    //printComparacaoAlgOrd(tempoQuick, tempoSelect, qtdMovQ, qtdMovS, qtdComQ, qtdComS);

    //TADs originais
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

    //TADs Copia para ordenacao
    //-----texto
    TListaPArr textoCopiaArr;
    TListaPLe textoCopiaLe;

    //-----biblioteca
    TListaTArr biblioCopiaArr;
    TListaTLe biblioCopiaLe;

    configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);


    inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
    do {
        switch (opcTad) {
            case 1: {//tad palavra
                if (opcED == 1) { //lista encadeada
                    printFuncPalavra();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) { //inserir letra LE
                        insereLetraLe(&palavraLe);
                        printf(YEL"----> Letras inseridas!"RESET);
                        system("cls");
                    } else if (opcOperacao == 2) { //remover letra LE
                        system("cls");
                        removeLetraLe(&palavraLe);
                    } else if (opcOperacao == 3) { //imprimir
                        system("cls");
                        printf(YEL"----> Palavra: "RESET);
                        imprimePalavraLe(&palavraLe);
                        break;
                    } else if(opcOperacao == 4){ //tamanho
                        system("cls");
                        printf(YEL"----> Tamanho da palavra: "RESET"%d\n", tamanhoPalavraLe(&palavraLe));
                        break;
                    }else if(opcOperacao == 5){ //sair
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    }else {
                        system("cls");
                        printf(YEL"----> Invalido"RESET);
                        break;
                    }
                } else if (opcED == 2) {//arranjo
                    printFuncPalavra();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) { //inserir
                        insereLetraArr(&palavraArr);
                        printf(YEL"----> Letras inseridas!"RESET);
                        system("cls");
                    } else if (opcOperacao == 2) { //remover
                        system("cls");
                        removeLetraArr(&palavraArr);
                    } else if (opcOperacao == 3) {
                        system("cls");
                        printf(YEL"----> Palavra: "RESET);
                        imprimePalavraArr(&palavraArr);
                    } else if (opcOperacao == 4) {
                        system("cls");
                        printf(YEL"----> Tamanho da palavra: "RESET" %d\n", tamanhoPalavraArr(&palavraArr));
                        break;
                    } else if (opcOperacao == 5) {
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    } else {
                        system("cls");
                        printf(YEL"----> Invalido"RESET);
                        break;
                    }
                }
                break;
            }
            case 2: {//tad texto
                if(opcED == 1) { //lista encadeada
                    printFuncTexto();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) {
                        system("cls");
                        inserePalavraLe(&textoLe, minTamPalav, maxTamPalav);
                        criaCopiaTextoLe(&textoLe, &textoCopiaLe);
                        printf(YEL"----> Palavra inserida!\n"RESET);
                    } else if (opcOperacao == 2) {
                        system("cls");
                        removePalavraLe(&textoLe);
                    } else if (opcOperacao == 3) {
                        system("cls");
                        printf(YEL"----> Tamanho do texto: "RESET"%d\n", tamanhoTextoLe(&textoLe));
                    }else if(opcOperacao == 4){
                        system("cls");
                        printf(YEL"----> Texto: "RESET);
                        imprimeTextoLe(&textoLe);
                        printf("\n");
                    } else if(opcOperacao == 5) {
                        system("cls");
                        if(opcOrd == 1){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortTextoLe(textoCopiaLe);
                            printf("\n");
                        } else
                            if(opcOrd == 2){
                                printf(YEL"----> Texto Ordenado: "RESET);
                                quicksortTextoLe(textoCopiaLe);
                                printf("\n");
                            }else{
                                printf(YEL"----> Texto Ordenado: "RESET);
                                selectionSortTextoLe(textoCopiaLe);
                                printf("\n");
                                printf(YEL"----> Texto Ordenado: "RESET);
                                quicksortTextoLe(textoCopiaLe);
                                printf("\n");
                            }
                    }else if(opcOperacao == 6) {
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    }
                }else if(opcED == 2){ //arranjo
                    printFuncTexto();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) {
                        system("cls");
                        inserePalavraArr(&textoArr, minTamPalav, maxTamPalav);
                        criaCopiaTextoArr(&textoArr, &textoCopiaArr);
                        printf(YEL"----> Palavra inserida!\n"RESET);
                    } else if (opcOperacao == 2) {
                        system("cls");
                        removePalavraArr(&textoArr);
                    } else if (opcOperacao == 3) {
                        system("cls");
                        printf(YEL"----> Tamanho do texto: "RESET"%d\n", tamanhoTextoArr(&textoArr));
                    } else if(opcOperacao == 4) {
                        system("cls");
                        printf(YEL"----> Texto: "RESET);
                        imprimeTextoArr(&textoArr);
                        printf("\n");
                    } else if(opcOperacao == 5){
                        if(opcOrd == 1){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortTextoArr(textoCopiaArr);
                            printf("\n");
                        } else
                        if(opcOrd == 2){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortTextoArr(textoCopiaArr);
                            printf("\n");
                        }else{
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortTextoArr(textoCopiaArr);
                            printf("\n");
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortTextoArr(textoCopiaArr);
                            printf("\n");
                        }
                    } else if(opcOperacao == 6){
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    }else {
                        system("cls");
                        printf("Invalido");
                        break;
                    }
                }
                break;
            }
            case 3: {//tad biblioteca
                if(opcED == 1){
                    printFuncBiblio();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) {
                        system("cls");
                        insereTextoLe(&bibliLe, opcQtdTextos, minTamPalav, maxTamPalav);
                        criaCopiaBibLe(&bibliLe, &biblioCopiaLe);
                        printf(YEL"----> Texto inserido!\n"RESET);
                    } else if (opcOperacao == 2) {
                        system("cls");
                        removeTextoLe(&bibliLe);
                    } else if (opcOperacao == 3) {
                        system("cls");
                        printf(YEL"----> Tamanho da biblioteca: "RESET"%d\n", tamanhoBibliotecaLe(&bibliLe));
                    } else if(opcOperacao == 4) {
                        system("cls");
                        imprimeBibliotecaLe(&bibliLe);
                    } else if(opcOperacao == 5) {
                        if(opcOrd == 1){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortBibLe(biblioCopiaLe);
                            printf("\n");
                        } else
                        if(opcOrd == 2){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortBibLe(biblioCopiaLe);
                            printf("\n");
                        }else{
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortBibLe(biblioCopiaLe);
                            printf("\n");
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortBibLe(biblioCopiaLe);
                            printf("\n");
                        }
                    } else if(opcOperacao == 6){
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    }
                } else
                if(opcED == 2){
                    printFuncBiblio();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) {
                        system("cls");
                        insereTextoArr(&bibliArr, opcQtdTextos, minTamPalav, maxTamPalav);
                        criaCopiaBibArr(&bibliArr, &biblioCopiaArr);
                        printf(YEL"----> Texto inserido!\n"RESET);
                    } else if (opcOperacao == 2) {
                        system("cls");
                        removeTextoArr(&bibliArr);
                    } else if (opcOperacao == 3) {
                        system("cls");
                        printf(YEL"----> Tamanho da biblioteca: "RESET"%d\n", tamanhoBibliotecaArr(&bibliArr));
                    } else if(opcOperacao == 4) {
                        system("cls");
                        imprimeBibliotecaArr(&bibliArr);
                    } else if(opcOperacao == 5) {
                        system("cls");
                        if(opcOrd == 1){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortBibArr(biblioCopiaArr);
                            printf("\n");
                        } else
                        if(opcOrd == 2){
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortBibArr(biblioCopiaArr);
                            printf("\n");
                        }else{
                            printf(YEL"----> Texto Ordenado: "RESET);
                            selectionSortBibArr(biblioCopiaArr);
                            printf("\n");
                            printf(YEL"----> Texto Ordenado: "RESET);
                            quicksortBibArr(biblioCopiaArr);
                            printf("\n");
                        }
                    } else if(opcOperacao == 6){
                        system("cls");
                        configura(&opcED, &opcTad, &opcQtdTextos, &minTamPalav, &maxTamPalav, &opcOrd);
                        inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
                        break;
                    }
                }
                    break;
            }
            default:{
                printf("\n");
                printf("\n");
                printf(YEL"                         OPCAO INVALIDA!\n"RESET);
                printf(YEL"                     ---FIM DE EXECUCAO!---\n"RESET);
                exit(1);
            }
        }
    }while (opcED != 0);
}
