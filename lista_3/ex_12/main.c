#include <stdio.h>

int main(){
  char nome[20];
  scanf("%s",&nome);
  int tamanho = strlen(nome);
  for(int i = 0; i< tamanho;i++){
    if((i % 2) == 0){
      printf("%c ",nome[i]);
    }
  }
  return 0;
}