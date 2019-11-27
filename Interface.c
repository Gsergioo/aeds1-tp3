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

#include "Interface.h"
#include <stdio.h>
#include <stdlib.h>


void printFuncPalavra(){
    printf(GRN"    Você escolheu o TAD Palavra!    \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"    |OPERAÇÕES|" RED              "          |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾" RED             "          |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover letra" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " " RED"                            |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncTexto(){
    printf(GRN"    Você escolheu o TAD Texto!    \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "        |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED             "              |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir palavra" RED"                 |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover palavra" RED"                   |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " alguma coisa" RED"              |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncBiblio(){
    printf(GRN"    Você escolheu o TAD Biblioteca!    \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "        |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED             "              |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir texto" RED"               |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover texto" RED"                   |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Deus é mais" RED"       |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}

void interface(){
    int opcTad = 0;
    int opcQtdTextos = 0;
    int opcQtdPalavr = 0;
    int opcOrd = 0;

    int opcOperacao = 0;

    system("clear");
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |MENU|" RED             "              |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED             "              |\n" RESET);
    printf(RED"|"RESET"  Escolha o TAD a ser utilizado"RED              "  |\n"RESET);
    printf(RED "|"RESET BLU" (1)"RESET " TAD Palavra" RED"                 |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " TAD Texto" RED"                   |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " TAD Biblioteca" RED"              |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);
    scanf("%d",&opcTad);
    system("clear");


    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |MENU|" RED      "              |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED      "              |\n" RESET);
    printf(RED"|"RESET"  Escolha a quantidade de palavras"RED   "   |\n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU "Tamanho: " RESET);
    scanf("%d",&opcQtdPalavr);
    system("clear");



    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |MENU|" RED      "              |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED      "              |\n" RESET);
    printf(RED"|"RESET"  Escolha a quantidade de textos"RED     "   |\n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU "Tamanho: " RESET);
    scanf("%d",&opcQtdTextos);
    system("clear");


    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |MENU|" RED             "              |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾" RED             "              |\n" RESET);
    printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);
    scanf("%d",&opcOrd);
    system("clear");

//---------------------------------------------------------------------------------------------

    switch (opcTad){
        case 1:{
            printFuncPalavra();
            scanf("%d", &opcOperacao);
            if(opcOperacao == 1){
                printf("1");
            }else if(opcOperacao == 2){
                printf("2");
            }else if(opcOperacao == 3){
                printf("3");
            }else
                printf("Invalido");
            break;
        }
        case 2:{
            printFuncTexto();
            scanf("%d", &opcOperacao);
            if(opcOperacao == 1){
                printf("1");
            }else if(opcOperacao == 2){
                printf("2");
            } else if(opcOperacao == 3){
                printf("3");
            }else
                printf("Invalido");
        }
        case 3:{
            printFuncTexto();
        }
    }

}