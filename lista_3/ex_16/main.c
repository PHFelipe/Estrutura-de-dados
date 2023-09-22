#include<stdio.h>
#include <string.h>
int main(){
  char palavras[10][50], pmaior[50]="a",pmenor[50] = "bbbbbb";
  int maior = 1, menor = 100;
  for(int i=0;i<=9;i++){
    printf("digite o nome:");
    scanf("%s",palavras[i]);
    if(strlen(palavras[i]) >= strlen(pmaior)){
      strcpy(pmaior,palavras[i]);
    }if(strlen(palavras[i]) < strlen(pmenor)){
      strcpy(pmenor,palavras[i]);
    }
  }
  printf("a maior palavra é:%s\n",pmaior);
  printf("a menor palavra é:%s",pmenor);
  return 0;
}