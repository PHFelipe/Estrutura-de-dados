#include <stdio.h>
#include <string.h>

void troca_letra(char *str, char original, char novo);

int main() {
  char palavraorigi[50];
  char letra, letranova;
  
  printf("digite a palavra:");
  scanf("%s", palavraorigi);
  fflush(stdin);
  
  printf("agora digite a letra original:");
  scanf(" %c", &letra);
  fflush(stdin);
  
  printf("digite a letra nova:");
  scanf(" %c", &letranova);
  fflush(stdin);
  
  troca_letra(palavraorigi, letra, letranova);
  printf("%s", palavraorigi);

  return 0;
}


void troca_letra(char *str, char original, char novo) {
  int tamanho = strlen(str);
  for (int i = 0; i < tamanho; i++) {
    if (*(str + i) == original) {
      *(str + i) = novo;
    }
  }
}