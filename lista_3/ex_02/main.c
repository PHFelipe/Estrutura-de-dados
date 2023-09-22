#include <stdio.h>
int main(){
  int p[10];
  int v[9];
  int s[19];
  int contador = 0;
  int i,j,k;
  for(i = 2; i<= 20;i++){
    if((i % 2) == 0){
      p[contador] = i;
      contador++;
    }
  }
  int count = 0;
  for(j=10; j<=19;j++){
    v[count] = j;
    count++;
  }
  int cont = 0;
  for(k = 0;k <= 18;k++){
    if(k <= 8){
      s[cont] = p[k];
      cont++;
      s[cont] = v[k];
      cont++;
    }else if(k == 9){
      s[cont] = p[k];
    }printf("%d\n",s[k]);
  }
//falta printar o p e o v
  return 0;
}