#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int a[2][3];
  int b[2][3];
  int c[2][3];
  srand(time(0));
  printf("matriz A:");
  for(int i = 0;i <=1;i++){
    printf("\n");
    for(int j = 0; j <=2; j++){
      a[i][j] = rand()%15;
      printf("%d ",a[i][j]);
    }
  }
  printf("\n\nmatriz B:");
  for(int i = 0;i <=1;i++){
    printf("\n");
    for(int j = 0; j <=2; j++){
      b[i][j] = rand()%15;
      printf("%d ",b[i][j]);
    }
  }
  printf("\n\nmatriz C:");
  for(int i = 0;i <=1;i++){
    printf("\n");
    for(int j = 0; j <=2; j++){
      c[i][j] = a[i][j] + b[i][j];
      printf("%d ",c[i][j]);
    }
  }
  return 0;
}