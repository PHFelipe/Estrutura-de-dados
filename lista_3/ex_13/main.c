#include <stdio.h>

int main(){
  char mensagem[20];
  int a =0;
  int b = 0;
  int c = 0;
  scanf("%s",&mensagem);
  int tamanho = strlen(mensagem);
  for(int i=0;i<tamanho;i++){
    if(mensagem[i] == 'a'||mensagem[i] == 'A'){
      a += 1;
    }
    if(mensagem[i] == 'b'||mensagem[i] == 'B'){
      b += 1;
    }
    if(mensagem[i] == 'c'||mensagem[i] == 'C'){
      c += 1;
    }
  }printf("a mensagem possui %d A, %d B e %d C",a,b,c);
  return 0;
}