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
void leArquivo(FILE *arq){
    printf("Lido");
}
void interface(){
    FILE *arq = NULL;
    int opcTad = 0;
    int opcTam = 0;
    int opcOrd = 0;
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
    printf(RED"|"RESET"  Escolha o tamanho da entrada"RED       "   |\n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU "Tamanho: " RESET);
    scanf("%d",&opcTam);
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
}