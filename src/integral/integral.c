#include "integral.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "../operacoes/operacoes.h"

float calculaH(tIntegracao t){
    
    return (t.B - t.A)/t.n;
}
float calculaFuncao(tFuncao func,int tam,float x){
    float resultado=0;
    for(int i=0;i<tam;i++){
        resultado += func.coeficientes[i] * pow(x,func.expoentes[i]);
    }
    return resultado;
}
float calculaXi(tIntegracao t){
    return t.xi+t.h;
}
int coeficienteTrapezio(int i,int n){
    if(i%n==0){
        return 1;
    }else return 2;
}
int coeficientePrimeiraRegradeSimpson(int i,int n){
    if(coeficienteTrapezio(i,n)==1){
        return coeficienteTrapezio(i,n);
    }else if(i%2==0){
            return 2;
        }else return 4;
}
int coeficienteSegundaRegradeSimpson(int i,int n){
    if(coeficienteTrapezio(i,n)==1){
        return coeficienteTrapezio(i,n);
    }else if(i%3==0){
        return 2;
    }else return 3;
}
void metodoGenerico(int metodo){
    tIntegracao dados;
    //definindo funcao
    printf("Digite a quantidade de termos da funcao: \n");
    scanf("%d",&dados.qtdTermos);
    dados.funcao = criaTFuncao(dados.funcao,dados.qtdTermos);

    //definindo intrucoes para integracao
    printf("Qual o intervalo de integracao?\n A=? ");
    scanf("%f", &dados.A);
    printf("B = ? ");scanf("%f", &dados.B);
    printf("\nQual o numero de intervalos? ");
    scanf("%d", &dados.n);
    dados.h = calculaH(dados);
    dados.xi=dados.A;
    dados.yi = calculaFuncao(dados.funcao,dados.qtdTermos,dados.xi); 
    //começo da tabela e criação da logica
    printf("i |    xi    |    yi    | ci |\n");
    printf("__________________________________________\n");
    int ci=0;
    float integral=0;
    switch (metodo)
        {
        case 1: //regra dos trapezios
            
            for(int i=0;i<=dados.n;i++){
                ci=coeficienteTrapezio(i,dados.n);
                integral+=ci*dados.yi;
                printf("%d |  %.4f  |  %.4f  |  %d  |\n",i,dados.xi,dados.yi,ci);
                printf("__________________________________\n");
                dados.xi=calculaXi(dados);
                dados.yi = calculaFuncao(dados.funcao,dados.qtdTermos,dados.xi);
            }
            integral = integral * (dados.h/2);
            break;
        case 2: //primeira regra de simpson
            for(int i=0;i<=dados.n;i++){
            ci = coeficientePrimeiraRegradeSimpson(i,dados.n);
            integral+=ci*dados.yi;
            printf("%d |  %.4f  |  %.4f  |  %d  |\n",i,dados.xi,dados.yi,ci);
            printf("__________________________________________\n");
            dados.xi=calculaXi(dados);
            dados.yi = calculaFuncao(dados.funcao,dados.qtdTermos,dados.xi);
            }
            integral = integral * (dados.h/3);
            break;
        case 3: //segunda regra de simpson
            for(int i=0;i<=dados.n;i++){
                ci = coeficienteSegundaRegradeSimpson(i,dados.n);
                integral+=ci*dados.yi;
                printf("%d |  %.4f  |  %.4f  |  %d  |\n",i,dados.xi,dados.yi,ci);
                printf("__________________________________________\n");
                dados.xi=calculaXi(dados);
                dados.yi = calculaFuncao(dados.funcao,dados.qtdTermos,dados.xi);
                }
                integral = integral * (dados.h*3/8);  
                break;
            default:
            printf("\nMetodo invalido");    
            break;
        }

    
    printf("\n\n O VALOR DA INTEGRACAO EH:\t%.4f",integral);
    free(dados.funcao.coeficientes);
    free(dados.funcao.expoentes); 
}
tFuncao criaTFuncao(tFuncao func, int tam){
    func.coeficientes=malloc(sizeof(float)*tam);
    func.expoentes = malloc(sizeof(float)*tam);
    for(int i=0;i<tam;i++){
        printf("\nqual o valor do coeficiente %d",i);
        scanf("%f",&func.coeficientes[i]);
        printf("\nqual o valor do expoente %d",i);
        scanf("%f",&func.expoentes[i]);
    }
    return func;
}
