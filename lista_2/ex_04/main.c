#include <stdio.h>

int main(){
  float preco;
  printf("Preço do pão: ");
  scanf("%f", &preco);
  int i;
  float pao;
  for(i = 1; i <= 50; i++){
    pao = preco * i;
    printf("Panificadora Pão de Ontem - Tabela de preços\n");
    printf("%d - R$ %.2f\n", i,pao);
  }
  return 0;
}