#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "sistemasLineares.h"
#include "operacoes.h"
#include "raizes.h"
#include "integral.h"

int main(){ 
    printf("trapezios:\n");
    metodoGenerico(1);
    printf("\nprimeira simpson:\n");
    metodoGenerico(2);
    printf("\nsegunda simpson:\n");
    metodoGenerico(3);
    return 0;
}