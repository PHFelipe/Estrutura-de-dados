#include<stdio.h>
#include <string.h>

void inverte(char *frase, char *ifrase);

int main(){
  char frase[50],ifrase[50];
  printf("Digite a palavra:");
  fgets(frase,50,stdin);
  inverte(frase,ifrase);
  printf("%s",ifrase);
  return 0;
}
void inverte(char *frase, char *ifrase){
  int tamanho = strlen(frase);
  for(int i = 0,j = (tamanho-1);i<tamanho;i++,j--){
    ifrase[i]=frase[j];
  }
}