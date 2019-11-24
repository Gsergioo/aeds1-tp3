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
void interface(){
    printf(RED "----------------------------------\n" RESET);
    printf(RED "|        " BLU "      MENU" RED      "              |\n" RESET);
    printf(RED "|"RESET BLU"(1)"RESET " Opçao 1" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(2)"RESET " Opçao 2" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(3)"RESET " Opçao 3" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(4)"RESET " Opçao 4" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(5)"RESET " Opçao 5" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(6)"RESET " Opçao 6" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(7)"RESET " Opçao 7" RED"                     |\n" RESET);
    printf(RED "|"RESET BLU"(8)"RESET " Opçao 8" RED"                     |\n" RESET);
    printf(RED "----------------------------------\n" RESET);
    printf(BLU "Opção: " RESET);
}