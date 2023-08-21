#include "interpolacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int numPontos = 6;
    tPonto *pontos = malloc(sizeof(tPonto)*(numPontos));
    pontos[0].x=2; pontos[1].x=3; pontos[2].x=4; pontos[3].x=5; pontos[4].x=6;pontos[5].x=7;
    pontos[0].y=3.69;pontos[1].y=6.7;pontos[2].y=13.65;pontos[3].y=29.68;pontos[4].y=67.24;pontos[5].y=156.66;
    float** tabela=calculaTabelaDifDiv(pontos,grau,numPontos);

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

    float x=4.5;
    somatorio = somaPolinomio(somatorio,vetorP[0]);
    printf("\n\nPolinomio formado: ");printaPolinomio(somatorio);
    printf("Resultado f(%.3f): %.4f",x,resultadoFuncao(somatorio.coeficiente,somatorio.grau,x));
    free(pontos);
    for(int i=0;i<grau+1;i++){
    free(vetorP[i].coeficiente);}
    free(somatorio.coeficiente);
    free(tabela);  
}

float** calculaTabelaDifDiv(tPonto* pontos,int grau,int nPontos){
    float **tabela=alocaMatriz(nPontos+1,nPontos+1);
    //FORMAÇÃO DA TABELA
    for(int i=0;i<=nPontos;i++){
        tabela[i][0] = pontos[i].y;
    }
    for(int i=1;i<nPontos;i++){
        for(int j=0;j<nPontos-i;j++){
            tabela[j][i] = (tabela[j + 1][i - 1] - tabela[j][i - 1]) / (pontos[i + j].x - pontos[j].x);
        }
        
    }
    printf(" i\t|  xi\t|  yi\t|f[0]\t|");
    for(int i=1;i<nPontos;i++){
        printf("f[%d]\t|",i);
    }
    printf("\n");
    for(int i=0;i<nPontos;i++){
        printf("%d\t|%.2f\t|%.2f\t|",i,pontos[i].x,pontos[i].y);
        for(int j=0;j<nPontos-i;j++){
            printf("%.2f\t|",tabela[i][j]);
        }
        printf("\n");
    }
    return tabela;

}

float** calculaTabelaDifFin(tPonto* pontos,int nPontos){
    float **tabela=alocaMatriz(nPontos,nPontos);
    //preenche primeira coluna
    
    
    for(int i=0;i<nPontos;i++){
        tabela[i][0] =  pontos[i].y;
    }
    //CALCULA VALORES DA TABELA
    for(int i=1;i<nPontos;i++){
        for(int j=0;j<nPontos-i;j++){
            tabela[j][i] = (tabela[j + 1][i - 1] - tabela[j][i - 1]);  
        }
    }

    //PRINTA A TABELA
    printf("xi\t|0f[x]\t|");
    for(int i=0;i<nPontos;i++){
        printf("%df[x]\t|",i);
    }
    printf("\n");
    printf("-----------------------------------------");printf("\n");
    for(int i=0;i<nPontos;i++){
        printf("%.2f\t|%.2f\t|",pontos[i].x,pontos[i].y);
        for(int j=0;j<nPontos-i;j++){
            printf("%.2f\t|",tabela[i][j]);
        }
        printf("\n-----------------------------------------");printf("\n");
    }
    return tabela;
}
void diferencasFinitas(){
    //ENTRADA DE DADOS
    int numPontos = 3;
    int grau = 2;
    tPonto *pontos=malloc(sizeof(tPonto)*numPontos);
    pontos[0].x=0;pontos[1].x=1; pontos[2].x=2; 
    pontos[0].y=0; pontos[1].y=0.5; pontos[2].y= 2.0/3.0;
    int h = pontos[1].x - pontos[0].x;
    
    //CALCULA O VALOR DA TABELA
    float** tabela = calculaTabelaDifFin(pontos,numPontos);

    //APLICA A FORMULA Pi(x)
    Polinomio somatorio;
    somatorio.coeficiente = malloc(sizeof(float));
    somatorio.coeficiente[0] = 0;
    somatorio.grau=0;
    
    Polinomio prod;
    prod.coeficiente = malloc(sizeof(float));
    prod.coeficiente[0] = 1;
    prod.grau=0;
    
    Polinomio *termos = malloc(sizeof(Polinomio)*(grau+1));
    termos[0].coeficiente=malloc(sizeof(float));
    termos[0].coeficiente[0] = tabela[0][0];
    termos[0].grau=0;
    
    for(int i=1;i<=grau;i++){
        termos[i].grau=1;
        termos[i].coeficiente = malloc(sizeof(float)*(grau+1));
        termos[i].coeficiente[0]=pontos[i-1].x*(-1);
        termos[i].coeficiente[1]=1;
        
    }

    float escalar =1;
    for(int i=0;i<grau;i++){
        prod.grau=0;
        prod.coeficiente=malloc(sizeof(float));
        prod.coeficiente[0]=1;
        for(int j=0;j<=i;j++){
            prod = produtoPolinomio(termos[j+1],prod);
        }
        escalar = (tabela[0][i+1]/(pow(h,(i+1))*fatorial(i+1)));
        prod=prodEscalarPolinomio(escalar,prod);
        somatorio = somaPolinomio(somatorio,prod);
    }
    somatorio = somaPolinomio(somatorio,termos[0]);
    printf("VALOR DE f(1.3) %f= ",resultadoFuncao(somatorio.coeficiente,somatorio.grau,1.3));
   
   /* METODO DIFERENCAS DIVIDIDAS
        for(int i=0;i<grau;i++){
        prod.grau=0;
        prod.coeficiente=malloc(sizeof(float));
        prod.coeficiente[0]=1;
        for(int j=0;j<=i;j++){
            prod = produtoPolinomio(termos[j+1],prod);
        }
        prod = prodEscalarPolinomio(tabela[0][i+1],prod);
        somatorio=somaPolinomio(somatorio,prod);


    }*/



    for(int i=0;i<=grau;i++){
        free(termos[i].coeficiente);
    }
    free(termos);
    free(pontos);
    desalocaMatriz(numPontos,tabela);
}
