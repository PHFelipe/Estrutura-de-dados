#include<stdio.h>

int main(){
  //criação da lista
  int k;
  scanf("%d", &k);
  int i = k*2;
  int notas[k];
  //atribuição das notas a uma lista
  for(int j=0; j<i;j++){
    scanf("%d",&notas[j]);
  }
  //verificação da maior nota
  int maior = 0;
  int matriculas[k];
  int maiores[k];
  int contador = 0;
  for(int j=0; j<i;j++){
    if(j != 0 && j % 2 != 0){
      if (notas[j] >= maior){
        maior = notas[j];
        maiores[contador] = notas[j];
        matriculas[contador] = notas[j-1];
        contador = contador + 1;
      }
    }
  }
  //verificação se a primeira entrada é maior
  if (maiores[0] != maior){
    maiores[0] = 0;
    matriculas[0] = 0;
    contador = contador - 1;
  }printf("-----------------\n");
  //contagem dos premiados e saidas
  for(int i = 0;i <= contador;i++){
    if(matriculas[i] != 0){
    printf("%d \n", matriculas[i]);
    }
  }printf("Quantidade de premiados:%d",contador);
  return 0;
  }