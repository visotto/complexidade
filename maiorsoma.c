/*
 DADO A SEQUENCIA, ENCONTRAR SUBSEQUENCIA CONSECUTIVA DE MAIOR SOMA
*/

#include <stdio.h> // entrada e saida
#include <stdlib.h> // alocacao dinamica

int main(int argc, char *argv[]) {
  int *n, // sequencia de inteiros
  qtd_digitos = -1, // n digitos
  soma, // maior soma possivel
  temp, // soma temporaria
  i; // indice

  while (qtd_digitos != 0) {
    soma = temp = 0;

    scanf("%d", &qtd_digitos);

    if (qtd_digitos == 0)
      break; // finaliza o programa

    n = (int *) malloc(qtd_digitos * sizeof(int));
    if (n == NULL) {
      printf("Erro: Memoria Insuficiente!\n");
      exit(1); // termina o programa
    }

    for (i=0; i<qtd_digitos; i++) // contador de 0 ate quantidade de digitos - 1
      scanf("%d", &n[i]); // preenche vetor n

    // se o conteudo das posicoes iniciais de n[qtd_digitos] forem < 0
    // incrementa-se i, ignorando estas primeiras posicoes
    i=0;
    while (n[i] < 0)
      i++;
    
    // se o conteudo das posicoes finais de n[qtd_digitos] forem < 0
    // decrementa-se qtd_digitos, ignorando estas ultimas posicoes
    while (n[qtd_digitos-1] < 0) // posicao 0, 1, ... , x-1
      qtd_digitos--;

    for (; i<qtd_digitos; i++) { // contador de i ate quantidade de digitos - 1
      temp = temp + n[i]; // temp recebe ele mesmo + conteudo da proxima posicao do vetor

      // se soma temporaria > que soma maxima
      // soma maxima recebe soma temporaria
      if (temp > soma)
        soma = temp;

      // se soma temporaria ficar negativa,
      // tal soma eh sempre nao negativa,
      // conforme guidelines, portanto = 0
      if (temp < 0)
        temp = 0;
    }

    printf("%d\n", soma);

    free(n); // libera a sequencia
  }

  return 0;
}
