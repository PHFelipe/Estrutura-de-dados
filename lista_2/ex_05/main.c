#include <stdio.h>

int main(){
  printf("Lojas Tabajara\n");
  float produto, total, dinheiro,troco;
  int i = 1;
  while(produto != 0){
      printf("Produto %i: R$ ", i);
      scanf("%f", &produto);
    if (produto == 0){
      printf("\n");
    }
    i++;
    total = total + produto;
  }
  printf("Total: R$ %.2f", total);
  printf("\nDinheiro: R$ ");
  scanf("%f",&dinheiro);
  troco = dinheiro - total;
  printf("Troco: R$ %.2f", troco);
  return 0;
}