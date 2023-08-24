#ifndef RAIZES_H
#define RAIZES_H

typedef struct{
    int grau,k;
    float precisao,Ak,Bk,Xk,*funcao,fXk,fdXk,fAk,*funcaoderivada;
}MetodosRaizes;


//calculo pelo metodo de bissecao
MetodosRaizes calculaXkBissecao(MetodosRaizes dados);
void metodoBissecao();
void metodoFalsaPosicao();
MetodosRaizes calculaXkFalsaPosicao(MetodosRaizes dados);
void metodoNewtonRaphson();
MetodosRaizes calculaXkNewtonRaphson(MetodosRaizes dados);
float* criaFuncao(int grau);

#endif