#include <stdio.h>

int main() {
  int linha, coluna;
  scanf("%d %d", &linha, &coluna);
  int matriz[linha][coluna];
  // recebimento de dados da matriz
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  // verificação dos valores
  int soma = 0, menor = 1000;
  
  for (int i = 0; i < coluna; i++) {
    for (int j = 0; j < linha; j++) {
      soma = soma + matriz[j][i];
    }if (soma < menor) {
      menor = soma;
      }
  soma = 0;
  }
  // saida da soma menor
  printf("%d", menor);
}