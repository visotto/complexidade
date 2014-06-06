#include <stdio.h> // entrada e saida

int main() {
  int N, // qtd de peixes
      X, // soma a ser obtida
      i, // indice p/ os valores dos peixes
      j, // indice p/ piscinas
      temp, // armazena temporareamente o valor associado de cada peixe
      max, // peixe de maior valor
      soma; // soma dos valores dos maiores peixes

  while (scanf("%d %d", &N, &X) && (N || X)) { // N = X = 0 finaliza o programa

    soma = 0;

    for (j = 0; j < 3; j++) { // itera para 3 piscinas
      max = -300 - 1; // minimo valor possivel de cada peixe - 1
      for (i = 0; i < N; i++) { // recebe o valor de cada peixe da piscina j e atualiza o maior valor do peixe
        scanf("%d", &temp);
        if (temp > max)
          max = temp;
      }
      soma += max; // acumula na soma o maior valor do peixe na piscina j
    }

    if (soma >= X) // valor acumulado maior ou igual ao premio
      printf("SIM\n");
    else
      printf("NÃO\n");
  }

  return 0;
}
