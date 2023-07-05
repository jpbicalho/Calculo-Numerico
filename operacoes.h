#ifndef OPERACOES_H
#define OPERACOES_H

float** criaMatriz(int linha, int coluna);
float** alocaMatriz(int linha, int coluna);
void printaMatriz(float** matriz,int linha,int coluna);
float** copiaMatriz(float** matriz,int linha,int coluna);
void printaVetor(float* vet, int tamanho);
float* criaVetor(int linha);
float* copiaVetor(float* vetor,int tamanho);

#endif