#include "raizes.h"
#include "../operacoes/operacoes.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



MetodosRaizes calculaXkBissecao(MetodosRaizes dados){
    dados.Xk = (dados.Ak + dados.Bk)/2;
    return dados;
}
void metodoBissecao(){
    MetodosRaizes dados;
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
        dados = calculaXkBissecao(dados);
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
        if(mDiferenca <= dados.precisao){
            libera++;
        }

    }while(libera<2);
    //calcula o resultado de Xk
    //se Xk < 0 e Ak>0, Bk assume o valor de Xk;
    //se Xk > 0 e Ak>0, Ak assume o valor de Xk

}




void metodoFalsaPosicao(){
    MetodosRaizes dados;
    /*printf("Grau da equacao: ");
    scanf("%d",&dados.grau);
    
    //cria um vetor de coeficientes
    
    dados.funcao=criaVetor(dados.grau);
    printf("\nQual a precisao: "); scanf("%f",&dados.precisao);
    printf("Valor de A0,0x: "); scanf("%f %f",&dados.Ak,&dados.Bk);*/

    dados.grau = 4;
    dados.funcao = malloc(sizeof(float)*dados.grau+1);
    dados.funcao[4]=1; dados.funcao[3] = 0; dados.funcao[2] = -14; dados.funcao[1]=24;dados.funcao[0]=-10;
    dados.precisao = 0.01; 
    dados.Ak = 2; dados.Bk = 3;
    dados.fAk = resultadoFuncao(dados.funcao,dados.grau,dados.Ak);
    dados.k=0;
    printf("\n\n\nk |   Ak   |   Bk   |   Xk    |   f(Xk)  | |f(Xk)| |    f(Ak) * f(Xk)   |\n");
    printf("____________________________________________________________________________\n");
    float precisaoTabela = 1;
    int libera = 0;
    int it = 12;
    do{
        dados=calculaXkFalsaPosicao(dados);
        dados.fXk = resultadoFuncao(dados.funcao,dados.grau,dados.Xk);
        dados.fAk = resultadoFuncao(dados.funcao,dados.grau,dados.Ak);
        printf("%d | %.4f | %.4f |  %.4f  | %.4f | %.4f  | %.4f  * %.4f\n",
            dados.k,dados.Ak,dados.Bk,dados.Xk,dados.fXk,modulo(dados.fXk),dados.fAk,dados.fXk);
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
        
        precisaoTabela=modulo(dados.fXk);
        if( precisaoTabela <= dados.precisao){
            libera++;
        }

    }while(libera<1 || dados.k==it);
}

MetodosRaizes calculaXkFalsaPosicao(MetodosRaizes dados){

    float fA = resultadoFuncao(dados.funcao, dados.grau, dados.Ak);
    float fB = resultadoFuncao(dados.funcao, dados.grau, dados.Bk);
    dados.Xk = (fB*dados.Ak-dados.Bk*fA)/(fB-fA); 
    return dados;
}

void metodoNewtonRaphson(){
    //calcular f(a)*f'(a) e  f(b)*f'(b) o que for positivo assume o valor de Xk

    MetodosRaizes dados;
    /*printf("Grau da equacao: ");
    scanf("%d",&dados.grau);
    
    //cria um vetor de coeficientes
    
    dados.funcao=criaVetor(dados.grau);
    printf("\nQual a precisao: "); scanf("%f",&dados.precisao);
    printf("Valor de A0,0x: "); scanf("%f %f",&dados.Ak,&dados.Bk);*/

    dados.grau = 3;
    dados.funcao = malloc(sizeof(float)*dados.grau+1);
    dados.funcao[3] = 1; dados.funcao[2] = -9; dados.funcao[1]=0;dados.funcao[0]=3;
    
    dados.funcaoderivada = malloc(sizeof(float)*dados.grau);
    dados.funcaoderivada[2] = 3; dados.funcaoderivada[1]=-18;dados.funcaoderivada[0]=0;
    //definicao dos dados
    dados.precisao = 0.065; 
    dados.Ak = 0; dados.Bk = 1;
    dados.fAk = resultadoFuncao(dados.funcao,dados.grau,dados.Ak);
    dados.k=0;
    
    printf("\n\n\nk |   Xk    |   f(Xk)  | f'(Xk) |    f(Ak) * f(Xk)   |\n");
    printf("____________________________________________________________________________\n");
    float precisaoTabela = 1;
    int libera = 0;
    int it = 3;
    //definicao de qual utilizar como o x0
        //calculo de f(a) e f(b)
    float fA = resultadoFuncao(dados.funcao,dados.grau,dados.Ak);float fB = resultadoFuncao(dados.funcao,dados.grau,dados.Bk);
        //calculo de f'(a) e f'(b) 
    float fdA = resultadoFuncao(dados.funcaoderivada,dados.grau,dados.Ak); float fdB = resultadoFuncao(dados.funcaoderivada,dados.grau,dados.Bk);
    //O PRODUTO QUE FOR POSITIVO VAI SER O X0
    if(fA*fdA > 0){ dados.Xk = dados.Ak;}
    if(fB*fdB > 0){ dados.Xk = dados.Bk;}
    //variavel que vai armazenar o xk-1
    float antxK=0;
    //calcula o f(x) e f'(x)
    dados.fXk = resultadoFuncao(dados.funcao,dados.grau,dados.Xk);
    dados.fdXk = resultadoFuncao(dados.funcaoderivada,dados.grau,dados.Xk);
    //primeiro print
    printf("%d | %.4f | %.4f |  %.4f  | -----\n",
            dados.k,dados.Xk,dados.fXk,dados.fdXk);
    printf("____________________________________________________________________________\n");
    do{
        antxK = dados.Xk;
        dados=calculaXkNewtonRaphson(dados);
        dados.k++;
        dados.fXk = resultadoFuncao(dados.funcao,dados.grau,dados.Xk);
        dados.fdXk = resultadoFuncao(dados.funcaoderivada,dados.grau,dados.Xk);
        printf("%d | %.4f | %.4f |  %.4f  | %.4f\n",
            dados.k,dados.Xk,dados.fXk,dados.fdXk,modulo(dados.Xk-antxK));
        printf("____________________________________________________________________________\n");
        precisaoTabela=modulo(dados.Xk-antxK);
        if( precisaoTabela < dados.precisao){
            libera++;
        }

    }while(libera!=1);   

}
MetodosRaizes calculaXkNewtonRaphson(MetodosRaizes dados){
    dados.Xk = dados.Xk - (resultadoFuncao(dados.funcao,dados.grau,dados.Xk)/
                           resultadoFuncao(dados.funcaoderivada,dados.grau,dados.Xk));
    return dados;
}