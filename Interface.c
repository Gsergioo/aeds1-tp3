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
    printf(RED "|"RESET BLU" (5)"RESET " Sair" RED"                        |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}


void printFuncTexto(int *tamTexto){
    printf(GRN"\n            TAD Texto!            \n"RESET);
    printf(RED "-----------------------------------\n" RESET);
    printf(BLU " Insira o tamanho dos textos: "RESET);
    scanf("%d", tamTexto);
    printf(RED "-----------------------------------\n" RESET);
    printf(RED "|        " BLU"     |OPERAÇÕES|" RED              "         |\n" RESET);
    printf(RED "|        " BLU"     ‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
    printf(RED "|"RESET BLU" (1)"RESET " Inserir palavra" RED"             |\n" RESET);
    printf(RED "|"RESET BLU" (2)"RESET " Remover palavra" RED"             |\n" RESET);
    printf(RED "|"RESET BLU" (3)"RESET " Tamanho do texto" RED"            |\n" RESET);
    printf(RED "|"RESET BLU" (4)"RESET " Ordena Texto" RED"                |\n" RESET);
    printf(RED "|"RESET BLU" (5)"RESET " Sair" RED"                        |\n" RESET);
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
    printf(RED "|"RESET BLU" (4)"RESET " Sair" RED"                        |\n" RESET);
    printf(RED "-----------------------------------\n"                          RESET);
    printf(BLU "Opção: " RESET);


}
void inicializaListas(int opcED, int opcTad,TListaLLe *palavraLe, TListaLArr *palavraArr, TListaPLe *textoLe, TListaPArr *textoArr, TListaTLe *bibliLe, TListaTArr *bibliArr){
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
            inicializaTextoArr(textoArr);
            printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
        }else
        if(opcTad == 3) {
            inicializaBiblioArr(bibliArr);
            printf(GRN"\n----> ARRANJO/VETOR!    \n"RESET);
        }
    }

}

void configura(int *opcED, int *opcTad, int *opcQtdTextos, int *opcQtdPalavr, int *opcOrd){
    system("clear");
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
    scanf("%d",opcTad);
    system("clear");

    if(*opcTad == 1){
        system("clear");
        printf(RED "-----------------------------------\n" RESET);
        printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
        printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
        printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
        printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
        printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
        printf(RED "-----------------------------------\n"                          RESET);
        printf(BLU "Opção: " RESET);
        scanf("%d", opcED);
        system("clear");

        printf(RED "-----------------------------------\n" RESET);
        printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
        printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
        printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
        printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
        printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
        printf(RED "-----------------------------------\n"                          RESET);
        printf(BLU "Opção: " RESET);
        scanf("%d",opcOrd);
        system("clear");
    } else
        if(*opcTad == 2){
            system("clear");
            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d", opcED);
            system("clear");

            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET" Quantidade de palavras"RED   "          |\n"RESET);
            printf(RED "-----------------------------------\n" RESET);
            printf(BLU "Quantidade: " RESET);
            scanf("%d",opcQtdPalavr);
            system("clear");

            printf(RED "-----------------------------------\n" RESET);
            printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
            printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
            printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
            printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
            printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
            printf(RED "-----------------------------------\n"                          RESET);
            printf(BLU "Opção: " RESET);
            scanf("%d",opcOrd);
            system("clear");
        }else
            if(*opcTad == 3){
                system("clear");
                printf(RED "-----------------------------------\n" RESET);
                printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
                printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
                printf(RED"|"RESET"  Escolha a estrutura de dados "RED              "  |\n"RESET);
                printf(RED "|"RESET BLU" (1)"RESET " Lista Encadeada" RED"             |\n" RESET);
                printf(RED "|"RESET BLU" (2)"RESET " Arranjo/Vetor" RED"               |\n" RESET);
                printf(RED "-----------------------------------\n"                          RESET);
                printf(BLU "Opção: " RESET);
                scanf("%d", opcED);
                system("clear");

                printf(RED "-----------------------------------\n" RESET);
                printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
                printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
                printf(RED"|"RESET" Quantidade de palavras"RED   "          |\n"RESET);
                printf(RED "-----------------------------------\n" RESET);
                printf(BLU "Tamanho: " RESET);
                scanf("%d",opcQtdPalavr);
                system("clear");

                printf(RED "-----------------------------------\n" RESET);
                printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
                printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
                printf(RED"|"RESET"  Escolha a quantidade de textos"RED     "   |\n"RESET);
                printf(RED "-----------------------------------\n" RESET);
                printf(BLU "Tamanho: " RESET);
                scanf("%d",opcQtdTextos);
                system("clear");

                printf(RED "-----------------------------------\n" RESET);
                printf(RED "|        " BLU"  |CONFIGURACAO|" RED             "         |\n" RESET);
                printf(RED "|        " BLU"  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾" RED             "         |\n" RESET);
                printf(RED"|"RESET"       Escolha o algoritmo "RED              "      |\n"RESET);
                printf(RED "|"RESET BLU" (1)"RESET " Inserção"RED "                    |\n" RESET);
                printf(RED "|"RESET BLU" (2)"RESET " QuickSort" RED"                   |\n" RESET);
                printf(RED "-----------------------------------\n"                          RESET);
                printf(BLU "Opção: " RESET);
                scanf("%d",opcOrd);
                system("clear");
            }else
                if(*opcTad == 4){
                    system("clear");
                    printf(YEL"                     ---FIM DE EXECUCAO!---\n"RESET);
                    exit(1);
                }else {
                    printf("\n");
                    printf("\n");
                    printf(YEL"                         OPCAO INVALIDA!\n"RESET);
                    printf(YEL"                     ---FIM DE EXECUCAO!---\n"RESET);
                    exit(1);
                }
}
//---------------------------------------------------------------------------------------------

void interface(){
    int opcTad = 0; //qual tad a ser utilizado
    int opcED = 0;  //qual estrutura de dados
    int opcQtdTextos = 0; //quantidade de textos -> biblioteca
    int opcQtdPalavr = 0; //quantidade de palavras -> texto
    int opcOrd = 0;      //qual alg de orde

    int tamTexto; //qtd de palavra pro texto
    int tamBibli; //qtd de textos pra biblioteca

    int opcOperacao = 0; //operacao do tad

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

    configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);


    inicializaListas(opcED, opcTad, &palavraLe, &palavraArr, &textoLe, &textoArr, &bibliLe,&bibliArr);
    do {
        switch (opcTad) {
            case 1: {//tad palavra
                if (opcED == 1) { //lista encadeada
                    printFuncPalavra();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) { //inserir letra LE
                        insereLetraLe(&palavraLe);
                        printf(YEL"----> LETRAS INSERIDAS"RESET);
                        system("clear");
                    } else if (opcOperacao == 2) { //remover letra LE
                        int pos = 0;
                        printf(YEL"----> Posicao a ser removida: "RESET);
                        scanf("%d", &pos);
                        if (pos <= palavraLe.tam && palavraLe.tam > 0) {
                            system("clear");
                            printf(YEL"----> Removidah!"RESET);
                        }
                        else
                            printf(YEL"----> Nao é possivel remover!"RESET);
                    } else if (opcOperacao == 3) {
                        system("clear");
                        printf(YEL"----> Palavra: "RESET);
                        imprimePalavraLe(&palavraLe);
                        break;
                    } else if(opcOperacao == 4){
                        system("clear");
                        printf(YEL"----> Tamanho da palavra: "RESET"%d\n", tamanhoPalavraLe(&palavraLe));
                        break;
                    }else if(opcOperacao == 5){
                        system("clear");
                        configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
                        break;
                    }else {
                        printf(YEL"----> Invalido"RESET);
                        break;
                    }
                } else if (opcED == 2) {//arranjo
                    printFuncPalavra();
                    scanf("%d", &opcOperacao);
                    if (opcOperacao == 1) { //inserir letra LE
                        insereLetraArr(&palavraArr);
                        printf(YEL"----> LETRAS INSERIDAS"RESET);
                        system("clear");
                    } else if (opcOperacao == 2) { //remover letra LE
                        int pos = 0;
                        printf(YEL"----> Posicao a ser removida: "RESET);
                        scanf("%d", &pos);
                        if (pos <= palavraArr.ultimo && palavraArr.ultimo > 0)
                            printf(YEL"----> Removidah!"RESET);
                            //removeLetraLe(&palavraLe, pos);
                        else
                            printf(YEL"----> Nao é possivel remover!"RESET);
                    } else if (opcOperacao == 3) {
                        system("clear");
                        printf(YEL"----> Palavra: "RESET);
                        imprimePalavraArr(&palavraArr);
                    } else if (opcOperacao == 4) {
                        system("clear");
                        printf(YEL"----> Tamanho da palavra: "RESET" %d\n", tamanhoPalavraArr(&palavraArr));
                        break;
                    } else if (opcOperacao == 5) {
                        system("clear");
                        configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
                        break;
                    } else {
                        printf(YEL"----> Invalido"RESET);
                        break;
                    }
                }
                    break;
                }
                case 2: {//tad texto
                    if(opcED == 1) { //lista encadeada
                        printFuncTexto(&tamTexto);
                        scanf("%d", &opcOperacao);
                        if (opcOperacao == 1) {
                            system("clear");
                            inserePalavraLe(&palavraLe, &textoLe);
                            printf(YEL"----> Palavra inserida!\n"RESET);
                        } else if (opcOperacao == 2) {
                            system("clear");
                            int pos = 0;
                            printf(YEL"----> Posicao a ser removida: "RESET);
                            scanf("%d", &pos);
                            if(pos <= textoLe.tam && pos >= 0) {
                                removePalavraLe(&palavraLe, &textoLe); //tem que mudar sa parada aq
                                printf(YEL"----> Palavra removida!\n"RESET);
                            }
                        } else if (opcOperacao == 3) {
                            system("clear");
                            printf(YEL"----> Tamanho do texto: "RESET"%d", tamanhoTextoLe(&textoLe));
                        }else if(opcOperacao == 4){
                            printf(YEL"----> Ordenadah\n"RESET);
                        } else if(opcOperacao == 5) {
                            configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
                            break;
                        }
                    }else if(opcED == 2){
                        printFuncTexto(&tamTexto);
                        scanf("%d", &opcOperacao);
                        if (opcOperacao == 1) {
                            system("clear");
                            inserePalavraArr(&palavraArr);
                            printf(YEL"----> Palavra inserida!\n"RESET);
                        } else if (opcOperacao == 2) {
                            system("clear");
                            int pos = 0;
                            printf(YEL"----> Posicao a ser removida: "RESET);
                            scanf("%d", &pos);
                            if(pos <= textoArr.ultimo && pos >= 0) {
                                removePalavraArr(&palavraArr, &textoArr); //tem que mudar sa parada aq
                                printf(YEL"----> Palavra removida!\n"RESET);
                            }
                        } else if (opcOperacao == 3) {
                            system("clear");
                            printf(YEL"----> Tamanho do texto: "RESET"%d", tamanhoTextoArr(&textoArr));
                        } else if(opcOperacao == 4) {
                            configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
                            break;
                        }
                    }
                    break;
                }
                case 3: {//tad biblioteca
                    if(opcED == 1){
                        printFuncBiblio(&tamBibli);
                        scanf("%d", &opcOperacao);
                        if (opcOperacao == 1) {
                            system("clear");
                            insereTextoLe(&textoLe, &bibliLe);
                            printf(YEL"----> Texto inserido!\n"RESET);
                        } else if (opcOperacao == 2) {
                            system("clear");
                            int pos = 0;
                            printf(YEL"----> Posicao a ser removida: "RESET);
                            scanf("%d", &pos);
                            if(pos <= bibliLe.tam && pos >= 0) {
                                removeTextoLe(&textoLe, &bibliLe); //tem que mudar sa parada aq
                                printf(YEL"----> Texto removido!\n"RESET);
                            }
                        } else if (opcOperacao == 3) {
                            system("clear");
                            printf(YEL"----> Tamanho da biblioteca: "RESET"%d\n", tamanhoBibliotecaLe(&bibliLe));
                        } else if(opcOperacao == 4) {
                            configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
                            break;
                        }
                    } else
                        if(opcED == 2){
                            printFuncBiblio(&tamBibli);
                            scanf("%d", &opcOperacao);
                            if (opcOperacao == 1) {
                                system("clear");
                                insereTextoArr(&textoArr, &bibliArr);
                                printf(YEL"----> Texto inserido!\n"RESET);
                            } else if (opcOperacao == 2) {
                                system("clear");
                                int pos = 0;
                                printf(YEL"----> Posicao a ser removida: "RESET);
                                scanf("%d", &pos);
                                if(pos <= bibliArr.ultimo && pos >= 0) {
                                    removeTextoArr(&textoArr, &bibliArr); //tem que mudar sa parada aq
                                    printf(YEL"----> Texto removido!\n"RESET);
                                }
                            } else if (opcOperacao == 3) {
                                system("clear");
                                printf(YEL"----> Tamanho da biblioteca: "RESET"%d\n", tamanhoBibliotecaArr(&bibliArr));
                            } else if(opcOperacao == 4) {
                                configura(&opcED, &opcTad, &opcQtdTextos, &opcQtdPalavr, &opcOrd);
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