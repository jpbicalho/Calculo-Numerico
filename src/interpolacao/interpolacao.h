#ifndef INTERPOLACAO_H
#define INTERPOLACAO_H
#include "../operacoes/operacoes.h"

typedef struct{
    float x,y;
}tPonto;

void metodoLagrange();
Polinomio calculaL(int i,tPonto* pontos);
void diferencasDivididas();
float** calculaTabela(tPonto*,int);



#endif