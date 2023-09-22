#include <stdio.h>
/*Faça um programa para uma loja de tintas. O algoritmo deverá pedir o tamanho em metros quadrados da área a ser pintada. Considere que a cobertura da tinta é de 1 litro para cada 3 metros quadrados e que a tinta é vendida em latas de 18 litros, que custam R$ 80,00.Informe ao usuário a quantidades de latas de tinta a serem compradas e o preço total.*/

int main(){
  int metros;
  scanf("%i", &metros);
  if (metros <= 54){
    printf("1 lata de tinta\n");
    printf("R$ 80,00\n");
  }else{
    int latas = (metros/3)/18;
    int preco = latas*80;
    printf("%i latas de tinta\n", latas);
    printf("R$ %i\n",preco);
  }
  return 0;
}