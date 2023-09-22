#include <stdio.h>

int main(){
  int vetor1[10];
  char vetor2[10];
  int i;
  for (i=0; i <= 9;i++){
    scanf("%i", &vetor1[i]);
  }
  int j;
  int k = 0;
  for (j=9;j >= 0; j--){
    vetor2[j] = vetor1[k];
    k++;
  }
  int n;
  int m;
  printf("Este é o vetor original:\n");
  for (m=0; m <= 9;m++){
    if (m != 9){
      printf("%i", vetor1[m]);
    }else{
      printf("%i\n", vetor1[m]);
    }
  }
  printf("Este é o vetor inverso:\n");
  for (n=0; n <= 9;n++){
    printf("%i", vetor2[n]);
  }
  return 0;
}