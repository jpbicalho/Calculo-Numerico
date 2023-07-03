#include "sistemasLineares.h"
#include <stdlib.h>
#include <stdio.h>
void eliminacaoGauss(){
    int linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    float **A,*b;
    A = criaMatriz(linhas,colunas);//matriz dos coeficientes
    b = criaVetor(linhas);//matriz das respostas
    faseEliminacao(A,b,linhas,colunas);
    return;

}
void faseEliminacao(float** matriz,float* vetor,int linha,int coluna){
    float **mult=alocaMatriz(linha,coluna);
    float **A=alocaMatriz(linha,coluna);
    for(int k=0;k<linha-1;k++){
        for (int i = k+1; i <linha; i++){
            mult[i][k] = -1 * (matriz[i][k] / matriz[k][k]);
            for(int j=k;j<linha;j++){
                matriz[i][j] = matriz[i][j] + mult[i][k] * matriz[k][j];
                A[i][j]=matriz[i][j];
            }
            vetor[i]= vetor[i]+mult[i][k]*vetor[k];
        }
    }   
    faseSubstituicao(matriz,vetor,linha,coluna);
    return vetor;
}

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
    float** copia=criaMatriz(linha,coluna);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j] = copia[i][j];
        }
    }
    return copia;
}

void faseSubstituicao(float** matriz,float* vetor,int linhas,int colunas){
    float *variavel = malloc(sizeof(float)*linhas);
      for (int i = linhas - 1; i >= 0; i--) {
        variavel[i] = vetor[i];
        for (int j = i + 1; j < linhas; j++) {
            variavel[i] -= matriz[i][j] * variavel[j];
        }
        variavel[i] /= matriz[i][i];
    }
    printf("\n\n\tVALOR DA MATRIZ RESULTANTE:\n\n");
    printaVetor(variavel,linhas);
    return;
}