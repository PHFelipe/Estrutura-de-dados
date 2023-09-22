#include <stdio.h>
#include <string.h>

int main(){
  char palavra[50],letra[5];
  printf("digite a palavra que voce desejar:");
  scanf("%s",palavra);
  printf("\nagora digite qual letra voce deseja contar:");
  scanf("%s",letra);
  int tamanho = strlen(palavra), contador = 0;
  for(int i =0;i<tamanho;i++){
    if(palavra[i] == letra[0]){
      contador += 1;
    }
  }
  printf("a letra '%c' aparece %d na frase",letra[0],contador);
  return 0;
}