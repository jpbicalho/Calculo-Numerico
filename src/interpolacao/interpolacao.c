#include "interpolacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void metodoLagrange(){//PRONTO
    printf("\nDigite o grau de Pn(x): ");
    int grauL; scanf("%d",&grauL);
    printf("\nQuantidade de pontos: ");
    int numPontos; scanf("%d", &numPontos);
    
    tPonto *pontos=criaPontos(numPontos);
    Polinomio l;
    l.grau=2;
    l.coeficiente=malloc(sizeof(float)*(grauL+1));
    l.coeficiente[0]=0;l.coeficiente[1]=0;l.coeficiente[2]=0;
    for(int i=0;i<=grauL;i++){
        printf("\nMetodo Lagrange l%d: ",i);printaPolinomio(calculaL(i,pontos,numPontos,grauL));
        printf("Y%d=%.2f\n",i,pontos[i].y);
        l = somaPolinomio(l,prodEscalarPolinomio(pontos[i].y,calculaL(i,pontos,numPontos,grauL)));  
        
    }
    
    printaPolinomio(l);
    float x=0;char val;
    printf("\nDeseja calcular um valor de x para a funcao?(s/n) ");
    getchar();
    scanf("%c", &val);
    if(val == 's'){
        printf("\ndigite o valor de x:"); scanf("%f", &x);
        printf("VALOR DE f(%f) = %.4f \n\n",x,resultadoFuncao(l.coeficiente,l.grau,x));
    }
    
}
Polinomio calculaL(int i,tPonto* pontos,int numPontos,int grauL){

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
        produtorio.coeficiente[j] = produtorio.coeficiente[j] / denominador;
    }
    return produtorio;


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

void diferencasGenericas(int metodo){//PRONTO
    
    //ENTRADA DE DADOS

    int grau,numPontos;
    printf("Digite o grau do polinomio Pn(x): ");
    scanf("%d", &grau);
    printf("\nDigite o numero de pontos: ");
    scanf("%d", &numPontos);
    tPonto *pontos = criaPontos(numPontos);
    int h = pontos[1].x - pontos[0].x;
 
    float **tabela;
    switch (metodo)
    {
    case 1://DIFERENCAS DIVIDIDAS
        tabela=calculaTabelaDifDiv(pontos,grau,numPontos);       
        break;
    case 2://DIFERENCAS FINITAS
        tabela = calculaTabelaDifFin(pontos,numPontos);
        break;
    default:
        printf("Valor invalido");
        return;
        break;
    }

    Polinomio somatorio = criaPolinomio(0);
    Polinomio prod = criaPolinomio(1);
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
    Polinomio resultante;

    switch (metodo)
    {
    case 1://DIFERENCAS DIVIDIDAS
        resultante=calculaPolinomioDifDiv(grau,prod,termos,somatorio,tabela);
        break;
    case 2://DIFERENCAS FINITAS
        resultante=calculaPolinomioDifFin(tabela,grau,1,prod,termos,somatorio);
        break;
    default://INVALIDAR CASO NAO ESCOLHA UM DOS 2
        printf("Valor invalido");
        return;
        break;
    }
    resultante=somaPolinomio(resultante,termos[0]);
    printaPolinomio(resultante);
    float x=0;char val;
    printf("\nDeseja calcular um valor de x para a funcao?(s/n) ");
    getchar();
    scanf("%c", &val);
    if(val == 's'){
        printf("\ndigite o valor de x:"); scanf("%f", &x);
        printf("VALOR DE f(%f) = %.4f \n\n",x,resultadoFuncao(resultante.coeficiente,resultante.grau,x));
    }
    
    //DESALOCA ELEMENTOS
    for(int i=0;i<=grau;i++){
        free(termos[i].coeficiente);
    }
    free(termos);
    free(pontos);
    desalocaMatriz(numPontos,tabela);
}

Polinomio calculaPolinomioDifDiv(int grau,Polinomio prod,Polinomio *vetorP,Polinomio somatorio, float** tabela){
    
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
    
    return somatorio;

}

Polinomio calculaPolinomioDifFin(float** tabela,int grau,float h,Polinomio prod,Polinomio* termos,Polinomio somatorio){

    float escalar =1;
    //diferente
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
    return somatorio;
}

tPonto* criaPontos(int num){
    tPonto* pontos=malloc(sizeof(tPonto)*num);
    for(int i=0;i<num;i++){
        printf("\ndigite o valor de x%d: ",i);
        scanf("%f", &pontos[i].x);
        printf("\ndigite o valor de y%d: ",i);
        scanf("%f", &pontos[i].y);
    }
    return pontos;
}