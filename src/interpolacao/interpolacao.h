#ifndef INTERPOLACAO_H
#define INTERPOLACAO_H
#include "../operacoes/operacoes.h"

typedef struct{
    float x,y;
}tPonto;

void metodoLagrange();
Polinomio calculaL(int i,tPonto* pontos);
void diferencasDivididas();
float** calculaTabelaDifDiv(tPonto*,int,int);
float** calculaTabelaDifFin(tPonto*,int);

Polinomio calculaPolinomioDifDiv(int grau,Polinomio prod,Polinomio *vetorP,Polinomio somatorio, float** tabela);
Polinomio calculaPolinomioDifFin(float** tabela,int grau,float h,Polinomio prod,Polinomio* termos,Polinomio somatorio);

void diferencasFinitas();
void diferencasGenericas(int);


#endif