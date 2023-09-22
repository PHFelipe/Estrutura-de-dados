#include <stdio.h>

int main(){
  int n,i,j; 
  printf("digite o N: ");
  scanf("%d", &n);
  for(i = 1; i <=n;i++){
    for(j = 1; j<=n;j++){
      if(j == n){
        printf(" %d\n", j);
      }else{
        printf(" %d", j);
      }
    }
  }
  return 0;
}