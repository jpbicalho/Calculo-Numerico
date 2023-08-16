#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float* criaVetor(int linha){
    float* novoVetor=malloc(sizeof(float)*linha);
    for (int i = 0; i<linha; i++)
    {
        printf("Digite o valor do b[%d,1]\n", i+1);
        scanf("%f", &novoVetor[i]);        
    }
    printf("\n");
    for (int i = 0; i<linha; i++)
    {
        printf("%.2f\n", novoVetor[i]);
    }
    return novoVetor;
    
}

float** alocaMatriz(int linha, int coluna){
    float** novaMatriz;
    novaMatriz = malloc(sizeof(float*)*linha);
    for(int i=0;i<coluna;i++){
        novaMatriz[i] = malloc(sizeof(float)*coluna);
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            novaMatriz[i][j] = 0;
        }
    }

    return novaMatriz;
}
float** criaMatriz(int linha, int coluna){
    float** novaMatriz;
    novaMatriz = malloc(sizeof(float*)*linha);
    for(int i=0;i<coluna;i++){
        novaMatriz[i] = malloc(sizeof(float)*coluna);
    }

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("Digite o valor do A[%d,%d]\n", i+1,j+1);
            scanf("%f", &novaMatriz[i][j]);
        }
    }
    printaMatriz(novaMatriz,linha,coluna);
    return novaMatriz;
}
void printaMatriz(float** matriz,int linha,int coluna){
    printf("\n");
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("%.2f\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void printaVetor(float* vet, int tamanho){
    printf("\n");
    for(int i=0;i<tamanho;i++)
        printf("%.2f\n", vet[i]);
}
float** copiaMatriz(float** matriz,int linha,int coluna){
    float** copia=alocaMatriz(linha,coluna);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            copia[i][j] =matriz[i][j];
        }
    }
    return copia;
}
float* copiaVetor(float* vetor,int tamanho){
    float *y = malloc(sizeof(float)*tamanho);
    for(int i=0;i<tamanho;i++){
        y[i] = vetor[i];
    }
    return y;
}

float resultadoFuncao(float* coeficientes,int grau,float x){
    float resultado=0;
    for(int i=0;i<grau+1;i++){
        resultado+=pow(x,grau-i)*coeficientes[grau-i];
    }
    //printf("\n\nVALOR DA FUNCAO: %.4f\n" , resultado);
    return resultado;
}
