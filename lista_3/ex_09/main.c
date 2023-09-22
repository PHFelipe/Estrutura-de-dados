#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int matriz[10][10], linha,coluna;
  int maior = 0;
  srand(time(0));
  for(int i = 0; i<=9;i++){
    printf("\n");
    for(int j = 0;j<=9;j++){
      matriz[i][j] = rand()%101;
      if(matriz[i][j] > maior){
        maior = matriz[i][j];
        linha = i;
        coluna = j;
      }
      printf("%d ",matriz[i][j]);
    }
  } printf("\n o maior é %d está na linha %d da coluna %d",maior,linha,coluna);
  return 0;
}