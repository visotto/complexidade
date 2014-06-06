#include <stdio.h> // entrada e saida
#include <stdlib.h> // alocacao dinamica

int main() {
  int N; // qtd de linhas/niveis
  int** triangulo; // array de int*, 2 dimensoes
  int i, j; // indices

  triangulo = malloc(5000 * sizeof(int*)); // cria as linhas/niveis
  for (i = 0; i < 5000; i++) { // cria as colunas
    triangulo[i] = malloc((i + 1) * sizeof(int)); // i+1 = a cada linha/nivel o numero de colunas aumenta em 1
  }

  while (scanf("%d", &N) && N) { // N = 0 finaliza o programa

    // preenche o triangulo
    for (i = 0; i < N; i++)
      for (j = 0; j < i + 1; j++)
        scanf("%d", &triangulo[i][j]);

    // verificacao de maior caminho comeca de baixo para cima
    // verifica o maior entre direita e esquerda e soma com seu antecessor
    for (i = N - 2; i >= 0; i--) // ultima linha eh n-1. Porem como eh a base, comeco de n-2
      for (j = 0; j < i + 1; j++)
        if (triangulo[i + 1][j] > triangulo[i + 1][j + 1]) // linha de baixo, coluna de baixo e coluna de baixo mais um
          triangulo[i][j] += triangulo[i + 1][j]; // elemento da esquerda eh maior que o da direita
        else
          triangulo[i][j] += triangulo[i + 1][j + 1]; // elemento da direita eh maior que o da esquerda

    printf("%d\n", triangulo[0][0]); // topo do triangulo, caminho de maior soma

  }

  // libera as colunas de cada uma das linhas
  for (i = 0; i < 5000; i++)
    free(triangulo[i]);

  free(triangulo);

  return 0;
}
