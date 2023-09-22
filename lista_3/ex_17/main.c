#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
  char palavra[50];
  printf("digite a palavra:");
  scanf("%s",palavra);
  for(int i = 0;i< strlen(palavra);i++){
    for(int j = 0; j<=i;j++){
      printf("%c",toupper(palavra[j]));
    }printf("\n");
  }
  return 0;
}