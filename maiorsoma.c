/*
 DADO A SEQUENCIA, ENCONTRAR SUBSEQUENCIA DE MAIOR SOMA
*/

#include <stdio.h>
#include <stdlib.h> // alocacao dinamica

int main(int argc, char *argv[]) {
  int *n,
  qtd_digitos, // n digitos fornecidos
  soma = 0, // maior soma possivel
  aux, // soma temporaria
  i, j; // indices
  
  do {
    scanf("%d", &qtd_digitos);
      
    n = (int *) malloc(qtd_digitos * sizeof(int));
    if(n == NULL) {
      printf("Erro: Memoria Insuficiente!\n");
      exit(1); // termina o programa
    }
    
    for (i=0; i<qtd_digitos; i++)
      scanf("%d", &n[i]); // preenche vetor n
    
    for (i=0; i<=qtd_digitos; i++) { // contador de 0 ate quantidade de digitos
      aux = 0;
      for (j=i; j<=qtd_digitos; j++) { // contador de 1 ate quantidade de digitos
        aux = aux + n[j];
        if (aux > soma)
          soma = aux;
      }
    }
      
    printf("%d\n", soma);
    
    free(n);
  } while (qtd_digitos != 0);
  
  return 0;
}
