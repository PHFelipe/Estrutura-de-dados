#include <stdio.h>

typedef struct ponto{
  int x;
  int y;
} cord;

void retangulo(int *x,int *y,cord *p);

int main(void){
  cord p1;
  p1.x = 10;
  p1.y= 5;
  int x1,y1;
  printf("digite a coordenada x do seu ponto:");
  scanf("%d",&x1);
  printf("digite a coordenada y do seu ponto:");
  scanf("%d",&y1);
  retangulo(&x1,&y1,&p1);
  return 0;
}
void retangulo(int *x,int *y,cord *p){
  if((p->x >= *x && *x >= 0)&&( p->y >= *y  && *y >= 0)){
    printf("O ponto está dentro do retangulo");
  }else{
    
    printf("O ponto não está dentro do retangulo");
  }
}
