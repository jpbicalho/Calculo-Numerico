#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int criaMenu(){
    int opcao;
    printf("\tEscolha o que deseja fazer:\n");
    printf("1.Resolução de sistemas lineares\n");
    printf("2.Interpolacao de pontos ");
    scanf("%d", &opcao);
    return opcao;
}