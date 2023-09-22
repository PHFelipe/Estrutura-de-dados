#include <stdio.h>
#include <string.h>

void remover(char* frase, int pos);

int main(){
  char frase[50];
  int pos;
  printf("Digite a frase:");
  scanf("%s",frase);
  printf("Digite a posiçao:");
  scanf("%d",&pos);
  remover(frase,pos);
  printf("%s",frase);
}

void remover(char* frase, int pos){
  char vazio ="";
  frase[pos-1]=vazio;
}