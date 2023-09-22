#include <stdio.h>
#include <string.h>
int main(){
  char palavra[50], invertido[50];
  printf("digite a palavra:");
  scanf("%s",palavra);
  int tamanho = strlen(palavra),tam2= strlen(palavra);
  for(int i =0;i<tamanho;i++){
    invertido[tam2] = palavra[i];
    tam2--;
  }
  int palindromo = 0;
  for(int i=0,j =strlen(palavra)-1; i<tamanho;i++,j--){
    if(palavra[i]==palavra[j]){
      palindromo += 1;
    }
  }
  if(palindromo == tamanho){
    printf("a palavra é um palindromo");
  }else{
    printf("não é um palindromo");
  }
  return 0;
}