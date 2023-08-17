#ifndef INTEGRAL_H
#define INTEGRAL_C
typedef struct{
    float *coeficientes;
    float *expoentes;
}tFuncao;
typedef struct{
    tFuncao funcao;
    float A,B,h,xi,yi;
    int qtdTermos,n;
}tIntegracao;



/*
      
f(x)= (1/x) + 2 
coef[0] = 1 coef[1] = 2
exp[0] = -1 exp[2] = 0

*/

//calcula yi em funcao de xi
float calculaFuncao(tFuncao,int,float);
float calculaXi(tIntegracao);
void metodoDosTrapezios();
float calculaH(tIntegracao);
void primeiraLeideSimpson();
void segundaLeideSimpson();
void metodoGenerico(int);
int coeficienteTrapezio(int i,int n);
int coeficientePrimeiraRegradeSimpson(int i ,int n);
int coeficienteSegundaRegradeSimpson(int i, int n);
#endif