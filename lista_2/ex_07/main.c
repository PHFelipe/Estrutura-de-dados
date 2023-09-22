#include <stdio.h>

int main(){
  int i,soma;
  for (i = 1; i <= 500; i++){
    if(i % 3 == 0){
      soma = i + soma;
    }
  }
  printf("a soma dos numeros multiplos de 3 presentes entre 1 e 500 é: %d", soma);
  return 0;
}