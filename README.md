# Calculo-Numerico
Os métodos ensinados durante as aulas de cálculo númerico aplicados em codigo na linguagem c.

_As intruções de compilação estao a seguir..._

gcc -o e.exe src/main.c src/menu/menu.c src/sistemasLineares/sistemasLineares.c src/operacoes/operacoes.c src/raizes/raizes.c src/integral/integral.c src/interpolacao/interpolacao.c -lm -Wall

./e.exe

_foi utilizado o VSCode,num Windows x64 para implementação dos métodos,e o proprio terminal para compilação do programa.(powershell)_ 

_Versionizado no GitHub_

*Metodos de encontrar soluções para sistemas lineares*
    Metodos que com base em um sistema linear, encontra a solução.

*Metodos de interpolação:*
    Metodo que gera um polinomio que liga varios pontos a um desejado.
    Que permite encontrar um f(x) de um x arbitrário

*Metodos de integracao*
    Metodos que permitem aplicar integral de uma funcao mais complexa,por 
    meio de pontos da própria função.

*Metodos para encontrar raizes*
    Por meio da funcao e de um intervalo que contenha a raiz, raciocinios iterativos
    se aproximam da raiz até atingir um ponto de parada.