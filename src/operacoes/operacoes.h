#ifndef OPERACOES_H
#define OPERACOES_H

typedef struct{
    int grau;
    float *coeficiente;
}Polinomio;


float** criaMatriz(int linha, int coluna);
void desalocaMatriz(int linhas,float** matriz);
float** alocaMatriz(int linha, int coluna);
void printaMatriz(float** matriz,int linha,int coluna);
float** copiaMatriz(float** matriz,int linha,int coluna);
void printaVetor(float* vet, int tamanho);
float* criaVetor(int linha);
float* copiaVetor(float* vetor,int tamanho);
float resultadoFuncao(float* coeficientes,int grau,float x);
float modulo(float num);
Polinomio produtoPolinomio(Polinomio,Polinomio);
void printaPolinomio(Polinomio);
Polinomio somaPolinomio(Polinomio,Polinomio);
Polinomio prodEscalarPolinomio(float,Polinomio);
float arredonda4casas(float);
float fatorial(float);
Polinomio criaPolinomio(float valor);
#endif
