#ifndef SISTEMASLINEARES_H
#define SISTEMASLINEARES_H
void eliminacaoGauss();
float** criaMatriz(int linha, int coluna);
float** alocaMatriz(int linha, int coluna);
void printaMatriz(float** matriz,int linha,int coluna);
float** copiaMatriz(float** matriz,int linha,int coluna);
void printaVetor(float* vet, int tamanho);
float* criaVetor(int linha);
void faseEliminacao(float** matriz,float* vetor,int linha,int coluna);
void faseSubstituicao(float** matriz,float* vetor,int linhas,int colunas);
#endif