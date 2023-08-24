#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../sistemasLineares/sistemasLineares.h"
#include "../interpolacao/interpolacao.h"
#include "../raizes/raizes.h"
#include "../integral/integral.h"
int criaMenu(){
    int opcao;
    printf("\tEscolha o que deseja fazer:\n");
    printf("1.Resolucao de sistemas lineares\n");
    printf("2.Interpolacao de pontos\n");
    printf("3.Integracao numerica\n");
    printf("4.Raizes de equacoes algebricas\n");
    printf("5.Sair \n");
    scanf("%d", &opcao);
    if(opcao==5)exit(0);
    return opcao;
}
void direcionaMenu(int opc){
    int controller = opc;
        switch (controller)
        {
        case 1:
            menuSistemaLinear();
            break;
        case 2:
            menuInterpolacao();
            break;
        case 3:
            menuIntegral();
            break;
        case 4:
            menuRaizes();
            break;
        default:
            printf("Valor invalido...\n");
            controller =criaMenu();
            break;
        }

} 
void menuSistemaLinear(){
    int opc;
    do{
        printf("\tQual metodo deseja aplicar:\n");
        printf("1.Metodo de Gauss\n");
        printf("2.Decomposicao LU\n");
        printf("3.Metodo de Jacobi\n");
        printf("4.Metodo de Gauss Seidel\n");
        printf("5.Sair\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
            printf("A matriz pedida nao inclui o vetor b,inclui apenas os coeficientes\n");
            printf("ELIMINACAO DE GAUSS...\n\n");
            eliminacaoGauss();
            break;
            case 2:
            printf("A matriz pedida nao inclui o vetor b,inclui apenas os coeficientes\n");
            decomposicaoLU();
            break;
            case 3:
            printf("A matriz pedida inclui todos os numeros inclusive os valores apos o = \n");
            metodoJacobi();
            break;
            case 4:
            printf("A matriz pedida inclui todos os numeros,inclusive os valores apos o = \n");
            metodoGaussSeidel();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\n\ndigite uma nova opcao: ");

        }
    }while(opc!=5);
    return;
}
void menuInterpolacao(){
    int opc;
    do{
        printf("\tQual metodo deseja aplicar:\n");
        printf("1.Metodo de Lagrange\n");
        printf("2.Diferencas Divididas\n");
        printf("3.Diferencas finitas\n");
        printf("4.Sair\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
            metodoLagrange();
            break;
            case 2:
            diferencasGenericas(1);
            break;
            case 3:
            diferencasGenericas(2);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\ndigite uma nova opcao: ");

        }
    }while(opc!=4);
    return;

}
void menuRaizes(){
    int opc;
    do{
        printf("\tQual metodo deseja aplicar:\n");
        printf("1.Metodo da bissecao\n");
        printf("2.Metodo de falsa posicao\n");
        printf("3.Metodo Newton Raphson\n");
        printf("4.Sair\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
            metodoBissecao();
            break;
            case 2:
            metodoFalsaPosicao();
            break;
            case 3:
            metodoNewtonRaphson();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\ndigite uma nova opcao: ");

        }
    }while(opc!=4);
    return;
}
void menuIntegral(){
        int opc;
    do{
        printf("\tQual metodo deseja aplicar:\n");
        printf("1.Metodo dos Trapezios\n");
        printf("2. 1 Regra de Simpson\n");
        printf("3. 2 Regra de Simpson\n");
        printf("4.Sair");
        scanf("%d", &opc);
        switch(opc){
            case 1:
            metodoGenerico(1);
            break;
            case 2:
            metodoGenerico(2);
            break;
            case 3:
            metodoGenerico(3);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\ndigite uma nova opcao: ");
            break;


        }
    }while(opc!=4);
    return;
}