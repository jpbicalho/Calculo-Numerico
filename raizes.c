#include "raizes.h"
#include "operacoes.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



Bissecao calculaXk(Bissecao dados){
    dados.Xk = (dados.Ak + dados.Bk)/2;
    return dados;
}
void metodoBissecao(){
    Bissecao dados;
    printf("Grau da equacao: ");
    scanf("%d",&dados.grau);
    
    //cria um vetor de coeficientes
    
    dados.funcao=criaVetor(dados.grau);
    printf("\nQual a precisao: "); scanf("%f",&dados.precisao);
    printf("Valor de A0,0x: "); scanf("%f %f",&dados.Ak,&dados.Bk);
    printf("\n\n\nk |   Ak   |   Bk   |   Bk-Ak   |   Xk   |   f(Xk)  |    f(Ak) * f(Xk)   |\n");
    printf("____________________________________________________________________________\n");
    //ate entao recebemos os dados necessarios para a realização do metodo
    dados.k=0;
    float mDiferenca = 1;
    int libera=0;
   do{    
        dados = calculaXk(dados);
        dados.fAk = resultadoFuncao(dados.funcao,dados.grau,dados.Ak);
        dados.fXk =  resultadoFuncao(dados.funcao,dados.grau,dados.Xk);
        printf("%d | %.4f | %.4f |  %.4f  | %.4f | %.4f | %.4f  * %.4f\n",
            dados.k,dados.Ak,dados.Bk,(dados.Ak-dados.Bk),dados.Xk,dados.fXk,dados.fAk,dados.fXk);
        printf("____________________________________________________________________________\n");
        if(dados.fXk == 0){
            break;
        }
        if(dados.fAk * dados.fXk >0){
            dados.Ak = dados.Xk;
        }
        if(dados.fAk * dados.fXk <= 0){
            dados.Bk = dados.Xk;
        }
        dados.k++;
        mDiferenca = dados.Ak -dados.Bk;
        if(mDiferenca < 0) mDiferenca = mDiferenca * (-1);
        if(mDiferenca <= 0.065){
            libera++;
        }

    }while(libera<2);
    //calcula o resultado de Xk
    //se Xk < 0 e Ak>0, Bk assume o valor de Xk;
    //se Xk > 0 e Ak>0, Ak assume o valor de Xk

}


void printaTabelaBissecao(Bissecao dados){
    printf("k | Ak | Bk | Bk-Ak | Xk | f(Xk) | f(Ak) * f(Xk) |\n");
    printf("__________________________________________________\n");

}