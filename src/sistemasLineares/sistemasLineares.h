#ifndef SISTEMASLINEARES_H
#define SISTEMASLINEARES_H
typedef struct{
    float **Mat1,**Mat2;
}ConjuntoMat;
void eliminacaoGauss();
ConjuntoMat faseEliminacao(float** matriz,float* vetor,int linha,int coluna);
void faseSubstituicao(float** matriz,float* vetor,int linhas,int colunas);
void decomposicaoLU();
void adaptaMatrizL(float** matriz,int linha,int coluna);
void encontraY(float** U,float * y,int linha,int coluna);
void metodoJacobi();
float calculaFormulaJacobi(int,float*,float*,int);
float calculaErro(float* k1,float* k2,int);
#endif