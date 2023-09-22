#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(0));
  int matriz[10][10],soma;
  for(int i = 0;i<=9;i++){
    for(int j = 0;j<=9;j++){
      matriz[i][j] = rand()%11;
      soma = soma + matriz[i][j];
      printf("%d ", matriz [i][j]);
    }
    printf(" a soma da linha é: %d",soma);
    printf("\n");
    soma = 0;
  }
  return 0;
}