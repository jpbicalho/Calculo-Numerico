#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "sistemasLineares/sistemasLineares.h"
#include "operacoes/operacoes.h"
#include "raizes/raizes.h"
#include "integral/integral.h"
#include "interpolacao/interpolacao.h"

int main(){ 
    printf("Os metodos a seguir foram feitos baseados em que suas condicoes ja foram validadas anteriormante.\n");
    direcionaMenu(criaMenu());
    
    return 0;
}