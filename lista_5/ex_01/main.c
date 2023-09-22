#include <stdio.h>

void somavet(int *ptvetor);
void maior(int *ptvetor);
void menor(int *ptvetor);

int main(void){
  int vetor[8]={10,20,50,35,48,94,60},*ptvetor;
  ptvetor = vetor;
  somavet(ptvetor);
  maior(ptvetor);
  menor(ptvetor);
  return 0;
}
void somavet(int *ptvetor){
  int soma = 0;
  for(int i =0; i<7;i++){
    soma += ptvetor[i];
  }
  printf("a soma dos elementos do vetor é:%d\n", soma);
}
void maior(int *ptvetor){
  int nummaior= 0;
  for(int i = 0;i<7;i++){
    if(ptvetor[i] >= nummaior){
      nummaior = ptvetor[i];
    }
  }
  printf("O maior elemento do vetor é:%d\n",nummaior);
}
void menor(int *ptvetor){
  int nummenor = 10000;
  for(int i=0; i<7;i++){
    if(ptvetor[i] <= nummenor){
      nummenor=ptvetor[i];
    }
  }
  printf("O menor elemento do vetor é:%d\n",nummenor);
}