#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geramatriz(){
  char matriz[6][6],reforma [6][6];
  int diagonal =0;
  srand(time(0));
  for(int i=0;i<6;i++){
    printf("\n");
    for(int j=0;j<6;j++){
      matriz[i][j] = rand()%10;
      printf("%d ", matriz[i][j]);
    }
  }
  printf("\n \n");
  for(int i = 0;i<6;i++){
    printf("\n");
    for(int j =0;j<6;j++){
      reforma[i][j] = matriz[i][j] * matriz[diagonal][diagonal];
      printf("%d ", reforma[i][j]);
    }
    diagonal += 1;
  }
}
int main(){
  geramatriz();
  return 0;
}