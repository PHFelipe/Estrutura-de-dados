#include <stdio.h>

int somaprimos(int x,int y){
  int soma = 0,inverso = 0,inverso1 = 0;
  if(x>y){
    inverso = y;
    inverso1 = x;
    x = inverso;
    y = inverso1;
  }
  for(int i = x;i<=y;i++){
    if(i == 1|| i == 3 || i == 2 || i == 5){
      soma += i;
    }
    if(i % 2 != 0){
      if(i%3 != 0){
        if(i%5 != 0){
          soma += i;
        }
      }
    }
  }
  return soma;
}
int main(){
  int x,y;
  scanf("%d %d", &x, &y);
  printf("x é: %d e y: %d\n",x,y);
  printf("o somatório é: %d",somaprimos(x,y));
  return 0;
}