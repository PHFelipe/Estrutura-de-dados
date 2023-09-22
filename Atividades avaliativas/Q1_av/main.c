#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char senha[50];
  int numeros[] = {'0','1','2','3','4','5','6','7','8','9'};
  char vogal[] = {'A','E','I','O','U'};
  int tam,permitido = 0;
  printf("Digite a senha:");
  scanf("%s",senha);
  tam = strlen(senha);
  for(int i = 0;i<tam;i++){//roda a string
    for(int j = 0; j <10;j++){//verifica numero
      if(senha[i] == numeros[j]){
        for(int k = 0;k<5;k++){//verifica vogal
          if(senha[i+1] == vogal[k]){
            permitido = 1;
            break;
          }else{
            permitido = 0;
          }
        }
        }
      }
    }
  
  if(permitido == 1){
    printf("SIM");
  }else{
    printf("NAO");
  }

}