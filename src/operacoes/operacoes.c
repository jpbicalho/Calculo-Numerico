#include "operacoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float* criaVetor(int linha){
    float* novoVetor=malloc(sizeof(float)*linha);
    for (int i = 0; i<linha; i++)
    {
        printf("Digite o valor do b[%d,1]\n", i+1);
        scanf("%f", &novoVetor[i]);        
    }
    printf("\n");
    for (int i = 0; i<linha; i++)
    {
        printf("%.2f\n", novoVetor[i]);
    }
    return novoVetor;
    
}
float* criaVetorValor(int linha,float valor){
    float* novoVetor=malloc(sizeof(float)*linha);
     for (int i = 0; i<linha; i++)
    {
        novoVetor[i]=valor;        
    }
    return novoVetor;
}

float** alocaMatriz(int linha, int coluna){
    float** novaMatriz;
    novaMatriz = malloc(sizeof(float*)*linha);
    for(int i=0;i<coluna;i++){
        novaMatriz[i] = malloc(sizeof(float)*coluna);
    }
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            novaMatriz[i][j] = 0;
        }
    }

    return novaMatriz;
}
float** criaMatriz(int linha, int coluna){
    float** novaMatriz;
    novaMatriz = malloc(sizeof(float*)*linha);
    for(int i=0;i<coluna;i++){
        novaMatriz[i] = malloc(sizeof(float)*coluna);
    }

    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("Digite o valor do A[%d,%d]\n", i+1,j+1);
            scanf("%f", &novaMatriz[i][j]);
        }
    }
    printaMatriz(novaMatriz,linha,coluna);
    return novaMatriz;
}
void printaMatriz(float** matriz,int linha,int coluna){
    printf("\n");
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("%.2f\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void printaVetor(float* vet, int tamanho){
    printf("\n");
    for(int i=0;i<tamanho;i++)
        printf("%.2f\n", vet[i]);
}
float** copiaMatriz(float** matriz,int linha,int coluna){
    float** copia=alocaMatriz(linha,coluna);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            copia[i][j] =matriz[i][j];
        }
    }
    return copia;
}
float* copiaVetor(float* vetor,int tamanho){
    float *y = malloc(sizeof(float)*tamanho);
    for(int i=0;i<tamanho;i++){
        y[i] = vetor[i];
    }
    return y;
}

float resultadoFuncao(float* coeficientes,int grau,float x){
    float resultado=0;
    for(int i=0;i<grau+1;i++){
        resultado+=pow(x,grau-i)*coeficientes[grau-i];
    }
    //printf("\n\nVALOR DA FUNCAO: %.4f\n" , resultado);
    return resultado;
}
float modulo(float num){
    if(num<0){
        return num*(-1);
    }else return num;
}

Polinomio produtoPolinomio(Polinomio p1,Polinomio p2){
    Polinomio prod;
    prod.grau = p1.grau+p2.grau;
    prod.coeficiente=malloc(sizeof(float)*(prod.grau+1));
    for(int i=0;i<=prod.grau;i++){
        prod.coeficiente[i]=0;
    }
    for(int i=0;i<=p1.grau;i++){
        for (int j = 0; j <= p2.grau; j++)
        {
            prod.coeficiente[i+j]+= p1.coeficiente[i] * p2.coeficiente[j];
        }
        
    }
    return prod;
}

void printaPolinomio(Polinomio p){
    if(p.grau==0){
        printf("%.2f",p.coeficiente[0]);
        }else{
        printf("%.3fx^%d",p.coeficiente[p.grau],p.grau);
        for(int i=1;i<p.grau;i++){
            if(p.coeficiente[p.grau-i]>0){
            printf("+ %.3fx^%d",p.coeficiente[p.grau-i],p.grau-i);
            }else if(p.coeficiente[p.grau-i]<0){
                printf(" %.3fx^%d",p.coeficiente[p.grau-i],p.grau-i);
            }else continue;
        }
        if(p.coeficiente[0]>0){
            printf(" + %.3f",p.coeficiente[0]);
        }else if(p.coeficiente[0]<0){
            printf(" %.3f",p.coeficiente[0]);
        }
    }
    printf("\n");
}
Polinomio somaPolinomio(Polinomio p1,Polinomio p2){
    int grauMenor = 0;
    if(p1.grau>p2.grau){
        grauMenor = p2.grau;
        for(int i=0;i<=grauMenor;i++){
            
            p1.coeficiente[i]=p1.coeficiente[i]+p2.coeficiente[i];
            }
            
        return p1;
    }else if(p1.grau<p2.grau){
        grauMenor=p1.grau;
        for(int i=0;i<=grauMenor;i++){
            p2.coeficiente[i]=p2.coeficiente[i]+p1.coeficiente[i];
            }
        
        return p2;
    }else{
        for(int i=0;i<=p1.grau;i++){
            p2.coeficiente[i]=p2.coeficiente[i]+p1.coeficiente[i];
            }
            return p2;
    }
    
    
    
}
Polinomio prodEscalarPolinomio(float n,Polinomio p){
    for(int i=0;i<=p.grau;i++){
        p.coeficiente[i] *= n; 
    }
    return p;
}

float arredonda4casas(float n){
    return round(n*10000)/10000;
}

void desalocaMatriz(int linhas,float** matriz){
    for(int i=0;i<linhas;i++){
        free(matriz[i]);
    }
    free(matriz);
}

float fatorial(float n){
    if (n== 1){//caso base
        return 1;
    } else return n*fatorial(n-1);
}
Polinomio criaPolinomio(float valor){

    //aloca um polinomio de grau 0 com o coeficiente[0]=valor
    Polinomio p;
    p.coeficiente = malloc(sizeof(float));
    p.coeficiente[0] = valor;
    p.grau=0;
    return p;
}

Polinomio recebePolinomio(){
    Polinomio aux;
    printf("Qual o grau do polinômio: ");
    scanf("%d", &aux.grau);
    aux.coeficiente = malloc(sizeof(float)*(aux.grau+1));
    for(int i=0;i<=aux.grau;i++){
        printf("\nDigite o valor que acompanha a%dx%d",aux.grau-i,aux.grau-i);
        scanf("%f", &aux.coeficiente[aux.grau-i]);
    }
    return aux;
}

