#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int vetor[30];
  int maior = 0;
  int menor = 100;
  srand(time(0));
  for (int i = 0; i <= 30; i++) {
    vetor[i] = rand() % 31;
    if (vetor[i] > maior) {
      maior = vetor[i];
    } 
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
  }printf("Este é o maior: %d \nEste é o menor: %d", maior,menor);
  return 0;
}