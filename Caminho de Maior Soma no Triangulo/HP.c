#include <stdio.h>
#include <stdlib.h>

void imp(int N, long int **matriz){
  int i, j;
  for(i=0; i<N; i++){
    for(j=0; j<i+1; j++){
      printf("matriz[%d][%d] = %ld\n", i, j, matriz[i][j]);
//      printf("%ld ", matriz[i][j]);
    }
//   printf("\n");
  }
}

int main() {
  int N;
  long int **matriz;
  int i, j;
  
  matriz = malloc(10000 * sizeof(long int*));
  for(i=0; i<10000; i++){
    matriz[i] = malloc((i+1) * sizeof(long int));
  }
    
  while(scanf("%d", &N) && N){
    for(i=0; i<N; i++){
      for(j=0; j<i+1; j++){
        scanf("%ld", &matriz[i][j]);
        printf("matriz[%d][%d] = %ld\n", i, j, &matriz[i][j]);
      }
    }
    printf("\nImpressao depois da insercao:\n");
    imp(N,matriz);
    
    for(i=N-2; i>=0; i--) // Ultima linha eh n-1, soh que sao folha, entao comeco do n-2
      for(j=0; j < i+1; j++)
        if(matriz[i+1][j] > matriz[i+1][j+1]) // linha de baixo, coluna de baixo e coluna de baixo mais um
          matriz[i][j] += matriz[i+1][j];
        else
          matriz[i][j] += matriz[i+1][j+1];

    printf("%ld\n", matriz[0][0]);

  }
  
  for (i=0; i<10000; i++)
    free(matriz[i]);
  free(matriz);
}
