#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int vetor[40];
  srand(time(0));
  for(int i =0;i<=40;i++){
    vetor[i] = rand()%100;
    if(vetor[i] % 2 == 0){
      printf("%d \n",vetor[i]);
    }
  }
  return 0;
}