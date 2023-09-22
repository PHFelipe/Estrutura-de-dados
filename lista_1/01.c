#include <stdio.h>

int main(){
  char nome[100];
  float salario;
  float montante;
  
  scanf("%s", nome);
  scanf("%f", &salario);
  scanf("%f", &montante);
  float salariototal = salario + (0.15*montante);
  printf("TOTAL = R$ %.2f", salariototal);
  return 0;
}