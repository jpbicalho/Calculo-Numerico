#include "interpolacao.h"
#include <stdio.h>
#include <stdlib.h>
void metodoLagrange(){
    int grauL=2;
    int *y = malloc(sizeof(int)*3);
    tPonto *pontos=malloc(sizeof(tPonto)*3);
    pontos[0].x=0; pontos[1].x=0.5; pontos[2].x=1;
    pontos[0].y=1.3; pontos[1].y=2.5; pontos[2].y=0.9;
    Polinomio l;
    l.coeficiente=malloc(sizeof(float)*(grauL+1));
    l.coeficiente[0]=0;l.coeficiente[1]=0;l.coeficiente[2]=0;
    for(int i=0;i<=grauL;i++){
        printf("\nMetodo Lagrange l%d: ",i);printaPolinomio(calculaL(i,pontos));
        printf("Y%d=%.2f\n",i,pontos[i].y);
        l = somaPolinomio(l,prodEscalarPolinomio(pontos[i].y,calculaL(i,pontos)));
       
    }
    printaPolinomio(l);
    
}
Polinomio calculaL(int i,tPonto* pontos){
    int numPontos=3;
    int grauL=2;
    float denominador=1;
    
    Polinomio p1,produtorio;
    produtorio.coeficiente = malloc(sizeof(float)*1);
    p1.grau = 1;
    p1.coeficiente = malloc(sizeof(float)*(p1.grau+1));
    p1.coeficiente[0] = 1;p1.coeficiente[1]=1;



    denominador=1;
    produtorio.grau=0;produtorio.coeficiente[0]=1;
    for(int j=0;j<numPontos;j++){
        if(i!=j){
            denominador = denominador * (pontos[i].x - pontos[j].x);
            p1.coeficiente[0]= (-1*pontos[j].x);
            produtorio=produtoPolinomio(produtorio,p1);
        }
        
    }
    for(int j=0;j<=produtorio.grau;j++){
        produtorio.coeficiente[j] /= denominador;
    }
    return produtorio;


}
void diferencasDivididas(){
    //Para formar um polinomio de grau n são necessarios n+1 pontos
    //tabela tera ordem de n+1

    //ENTRADA DE DADOS
    int grau = 3;
    tPonto *pontos = malloc(sizeof(tPonto)*(grau+1));
    pontos[0].x=1; pontos[1].x=2; pontos[2].x=4; pontos[3].x=8;
    pontos[0].y=120;pontos[1].y=94;pontos[2].y=75;pontos[3].y=62;
    float** tabela=calculaTabela(pontos,grau);
/*
    //FORMAÇÃO DA TABELA
    for(int i=0;i<=grau;i++){
        tabela[i][0] = pontos[i].y;
    }
    for(int i=1;i<grau+1;i++){
        for(int j=0;j<grau+1-i;j++){
            tabela[j][i] = (tabela[j + 1][i - 1] - tabela[j][i - 1]) / (pontos[i + j].x - pontos[j].x);
        }
        
    }
    printf(" i\t|  xi\t|  yi\t| Ordem 0|");
    for(int i=1;i<grau+1;i++){
        printf("Ordem %d|",i);
    }
    printf("\n");
    for(int i=0;i<grau+1;i++){
        printf("%d\t|%.2f\t|%.2f\t|",i,pontos[i].x,pontos[i].y);
        for(int j=0;j<grau+1-i;j++){
            printf("%.4f|",tabela[i][j]);
        }
        printf("\n");
    }*/

    //CALCULO DO POLINOMIO
    
    Polinomio *vetorP = malloc(sizeof(Polinomio)*(grau+1));
    Polinomio somatorio;
    somatorio.coeficiente = malloc(sizeof(float));
    somatorio.coeficiente[0] = 0;
    somatorio.grau=0;
    
    Polinomio prod;
    prod.coeficiente = malloc(sizeof(float));
    prod.coeficiente[0] = 1;
    prod.grau=0;
    
    vetorP[0].coeficiente=malloc(sizeof(float));
    vetorP[0].coeficiente[0]=tabela[0][0];
    vetorP[0].grau = 0;
    
    for(int i=1;i<=grau;i++){
        vetorP[i].coeficiente=malloc(sizeof(float)*3);
        vetorP[i].coeficiente[1]=1;
        vetorP[i].coeficiente[0]=(pontos[i-1].x)*(-1);
        vetorP[i].grau = 1;
    }
    //LOGICA DE OPERACAO
    
        for(int i=0;i<grau;i++){
            prod.grau=0;
            prod.coeficiente=malloc(sizeof(float));
            prod.coeficiente[0]=1;
            for(int j=0;j<=i;j++){
                prod = produtoPolinomio(vetorP[j+1],prod);
            }
            prod = prodEscalarPolinomio(tabela[0][i+1],prod);
            somatorio=somaPolinomio(somatorio,prod);


        }


    somatorio = somaPolinomio(somatorio,vetorP[0]);
    printaPolinomio(somatorio);
    printf("Resultado f(3): %.4f",resultadoFuncao(somatorio.coeficiente,somatorio.grau,3));
    free(pontos);
    for(int i=0;i<grau+1;i++){
    free(vetorP[i].coeficiente);}
    free(somatorio.coeficiente);
    free(tabela);  
}

float** calculaTabela(tPonto* pontos,int grau){
    float **tabela=alocaMatriz(grau+1,grau+1);
    //FORMAÇÃO DA TABELA
    for(int i=0;i<=grau;i++){
        tabela[i][0] = pontos[i].y;
    }
    for(int i=1;i<grau+1;i++){
        for(int j=0;j<grau+1-i;j++){
            tabela[j][i] = (tabela[j + 1][i - 1] - tabela[j][i - 1]) / (pontos[i + j].x - pontos[j].x);
        }
        
    }
    printf(" i\t|  xi\t|  yi\t| Ordem 0|");
    for(int i=1;i<grau+1;i++){
        printf("Ordem %d|",i);
    }
    printf("\n");
    for(int i=0;i<grau+1;i++){
        printf("%d\t|%.2f\t|%.2f\t|",i,pontos[i].x,pontos[i].y);
        for(int j=0;j<grau+1-i;j++){
            printf("%.4f|",tabela[i][j]);
        }
        printf("\n");
    }
    return tabela;

}