#include <stdio.h>

int main(int argc, char *argv[]) {
  int N, // numero de peixinhos
  X, // soma a ser obtida
  P1[5000],
  P2[5000],
  P3[5000],
  i,
  max1, max2, max3;
  
  while (1) {
    max1 = max2 = max3 = -300-1;
    
    scanf("%d %d", &N, &X);

    if ((N == 0) && (X == 0))
      break;

    for (i = 0; i < N; i++) {
      scanf("%d", &P1[i]);
    }

    for (i = 0; i < N; i++) {
      scanf("%d", &P2[i]);
    }
    
    for (i = 0; i < N; i++) {
      scanf("%d", &P3[i]);
    }
    
    for (i = 0; i < N; i++) {
      if(P1[i] > max1)
        max1 = P1[i];
    }
    
    for (i = 0; i < N; i++) {
      if(P2[i] > max2)
        max2 = P2[i];
    }
    
    for (i = 0; i < N; i++) {
      if(P3[i] > max3)
        max3 = P3[i];
    }
    
    if ((max1+max2+max3) >= X)
        printf("SIM\n");
    else
        printf("NÃO\n");
  }

  return 0;
}
