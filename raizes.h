#ifndef RAIZES_H
#define RAIZES_H

typedef struct{
    int grau,k;
    float precisao,Ak,Bk,Xk,*funcao,fXk,fAk;
}Bissecao;

//calculo pelo metodo de bissecao
Bissecao calculaXk(Bissecao dados);
void metodoBissecao();


#endif