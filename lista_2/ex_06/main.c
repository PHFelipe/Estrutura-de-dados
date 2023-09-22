#include <stdio.h>
#include <math.h>
int main(){
  int a,b,c,delta,xi,xii;
  printf("Insira os coeficientes A,B,C: ");
  scanf("%d %d %d", &a,&b,&c);
  delta = (b*b) - 4 * a * c;
  
  if(delta > 0){
    xi = ((b*-1) + sqrt(delta))/(2*a);
    xii = ((b*-1) - sqrt(delta))/(2*a);
    printf("As raizes da equação são %d e %d", xi,xii);
  }else if(delta == 0){
    xi = (b*-1)/(2*a);
    printf("A equação possui as duas raizes reais e iguais que é: %d", xi);
  }else{
    printf("A equação nao possui raizes reais");
  }

  return 0;
}