#include <math.h>
#include <stdio.h>

int impares(int* notas,int tamanho);
int media(int* notas, int tamanho);

int main() {
  int i;
  printf("qual a quantidade de notas:");
  scanf("%d", &i);

  int notas[i];

  for (int j = 0; j <= (i - 1); j++) {
    printf("\ncoloque a %d° nota:", (j + 1));
    scanf("%i", &notas[j]);
  }
  printf("\nA soma dos impares é:%d", impares(notas, i));
  printf("\nA media dos pares é:%d", media(notas, i));
}

int impares(int *notas, int tamanho) {
  int soma = 0;
  for (int i = 0; i <= tamanho; i++) {
    if (notas[i] % 2 != 0) {
      soma = soma + notas[i];
    }
  }
  return soma;
}

int media(int* notas, int tamanho){
  int soma = 0, pares = 0;
  for (int i = 0; i <= tamanho; i++) {
    if (notas[i] % 2 == 0){
      soma = soma + notas[i];
      pares = pares + 1;
    }
    }
  int media = soma / pares;
  return media;
}