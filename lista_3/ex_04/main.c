#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int vetor[7],entrada;
  int verif = 0;
  srand(time(0));
  for (int i = 0; i <= 7; i++) {
    vetor[i] = rand() % 10;
    printf("%d\n", vetor[i]);
  }
  scanf("%d",&entrada);
  for (int i = 0; i <= 7; i++) {
    if(vetor[i] == entrada){
      printf("no vetor existe um número igual ao que voce digitou na posição %d",i);
      verif = 1;
      break;
    }
  } if (verif == 0){
    printf("nao existe o numero que voce digitou no vetor");
  }
  return 0;
}
