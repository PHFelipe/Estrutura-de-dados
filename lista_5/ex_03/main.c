#include <stdio.h>

void multiplica(int *vetor);
int main(){
  int vetor[10]={5,2,10,15,20,7,9,13,17,21};
  
  multiplica(vetor);
  
  for(int i =0;i<10;i++){
    printf("%d ",*(vetor + i));
  }
}

void multiplica(int *vetor){
  int soma = 0;
  for(int i = 0;i<10;i++){
    *(vetor+i) *= 2;
  }  
}
