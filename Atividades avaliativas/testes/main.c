#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geramatriz(int (*mat)[3], int linhas, int colunas);
void menorvalor(int (*mat)[3],int linhas,int colunas);

int main() {
  int mat[3][3];
  geramatriz(mat, 3, 3);
  menorvalor(mat,3,3);
  return 0;
}

void geramatriz(int (*mat)[3], int linhas, int colunas) {
  srand(time(0));
  for (int i = 0; i < linhas; i++) {
    printf("\n");
    for (int j = 0; j < colunas; j++) {
      mat[i][j] = rand() % 10;
      printf("%d ", mat[i][j]);
    }
  }
}

void menorvalor(int (*mat)[3],int linhas,int colunas){
  int menor = 15;
  int l = 0, col = 0;
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (i + j == colunas - 1) {
        if(mat[i][j] < menor){
            menor = mat[i][j];
            l = i;
            col = j;
        }
      }
    }
  }
  printf("\nO menor valor é %d e sua posiçao é %d %d",menor,l,col);
}