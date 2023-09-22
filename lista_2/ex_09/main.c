#include <stdio.h>

int main(){
  int n,i,j;
  printf("informe o N: ");
  scanf("%d", &n);
  for(i=1;i <= n;i++){
    for(j=1; j <= n;j++){
      if(j == n){
        printf(" %d\n", i);
      } else{
        printf(" %d",i);
      }
    }
  }
  return 0;
}