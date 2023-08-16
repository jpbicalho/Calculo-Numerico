#include "sistemasLineares.h"
#include <stdlib.h>
#include <stdio.h>
#include "operacoes.h"
void eliminacaoGauss(){
    int linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    float **A,*b;
    
    A = criaMatriz(linhas,colunas);//matriz dos coeficientes
    b = criaVetor(linhas);//matriz das respostas
    faseEliminacao(A,b,linhas,colunas);
    faseSubstituicao(A,b,linhas,colunas);
    return;

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
ConjuntoMat faseEliminacao(float** matriz,float* vetor,int linha,int coluna){
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
    ConjuntoMat novo;
    
    
    novo.Mat1 = alocaMatriz(linha,coluna); novo.Mat2 = alocaMatriz(linha,coluna);//cria 
    novo.Mat1=copiaMatriz(matriz,linha,coluna); novo.Mat2=copiaMatriz(mult,linha,coluna);//copia as matrizes
    return novo;
    
}

void decomposicaoLU(){
    int linha, coluna;
    scanf("%d", &linha);
    scanf("%d", &coluna);
    float **A,*b,*y; 
    A = criaMatriz(linha,coluna);//matriz dos coeficientes
    b = criaVetor(linha);//matriz das respostas
    y = malloc(sizeof(float)*linha);
    y = copiaVetor(b,linha);
    
    ConjuntoMat decompLU=faseEliminacao(A,y,linha,coluna);//Mat1=U Mat2 = L
    adaptaMatrizL(decompLU.Mat2,linha,coluna);
    encontraY(A,y,linha,coluna);
    //decompLU.Mat1 = U
    //decompLU.Mat2 =>L
    //A => U
    //b => b
    //y => y
    
    

}

void encontraY(float** U,float * y,int linha,int coluna){
    // Y / U = X
    float *x = malloc(sizeof(float)*linha);
        for (int i = linha - 1; i >= 0; i--) {
        float soma = 0.0;
        for (int j = i + 1; j < coluna; j++) {
            soma += U[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / U[i][i];
    }
    printaVetor(x,linha);
}

void adaptaMatrizL(float** matriz,int linha,int coluna){
    //vai colocar a DP como 1 e a parte de cima garantir como 0
    
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            if(j==i){
                matriz[i][j] = 1;
            }
            if(i<j){
                matriz[i][j] = 0;
            }
            if(i>j){
                matriz[i][j] = matriz[i][j]*(-1);
            }
        }
    }

}
