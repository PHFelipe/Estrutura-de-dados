#include <stdio.h>


void menor(int m, int n, int mat[m][n], int *menornum, int *l, int *c);

int main(){
  int m,n,l,c,menornum;
  
  printf("Qual a ordem da matriz:");
  scanf("%d %d",&m,&n);
  int mat[m][n];

  for(int linha = 0; linha <m;linha++){
    for(int coluna = 0;coluna <n;coluna ++){
      scanf("%d",&mat[linha][coluna]);
    }
  }
  menor(m,n,mat,&menornum,&l,&c);
  printf("o menor valor é: %d\n",menornum);
  printf("na linha %d e na coluna %d",l,c);
  
  return 0;
}

void menor(int m, int n, int mat[m][n], int *menornum, int *l, int *c){
  
  int menorv=1000,linha,coluna;
  
  for(int i=0; i<m;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        if(mat[i][j] < menorv){
          menorv = mat[i][j];
          linha = i;
          coluna = j;
        }
      }
    }
  }
  *menornum = menorv;
  *l = linha;
  *c = coluna;
}