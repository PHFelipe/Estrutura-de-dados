#include <stdio.h>
#include <math.h>


typedef struct ponto{
  int x;
  int y;
}dist;
float distancia(int x1,int y1,int x2,int y2);

int main(){
  dist cord1,cord2;
  printf("distancia x do ponto 1:");
  scanf("%d",&cord1.x);
  printf("distancia y do ponto 1:");
  scanf("%d",&cord1.y);
  printf("distancia x do ponto 1:");
  scanf("%d",&cord2.x);
  printf("distancia y do ponto 2:");
  scanf("%d",&cord2.y);
  printf("\na distancia é: %.2f",distancia(cord1.x,cord1.y,cord2.x,cord2.y));
  return 0;
}
float distancia(int x1,int y1,int x2,int y2){
  float dist = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
  return dist;
}
