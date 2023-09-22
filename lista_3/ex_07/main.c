#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matriz[10][10];
  srand(time(0));
  for (int i = 0; i < 10; i++) {
    printf("\n");
    for (int j = 0; j < 10; j++) {
      matriz[i][j] = rand() % 51;
      printf("%d ", matriz[i][j]);
    }
  }
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("\n");
    for (int j = 0; j < 10; j++) {
      if(i == j){
        printf("%d",matriz[i][j]);
      }else{
        printf(" ");
      }
    }
  }
   return 0;
}