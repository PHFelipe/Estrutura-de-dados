#include <stdio.h>

int main(){
int idade,peso;
scanf("%i %i", &idade,&peso);
//idade menor que 20
if (idade<20){
  if(peso<=60){
    printf("9\n");
  } if(peso>=61 && peso<= 90){
    printf("8\n");
  }if (peso>=91){
    printf("7\n");
  }
}
//idade de 20 a 50
if (idade>=20 && idade<=50){
  if(peso<=60){
    printf("6\n");
  } if(peso>=61 && peso<= 90){
    printf("5\n");
  }if (peso>91){
    printf("4\n");
  }
}
//idade maior que 50
if(idade>=51){
  if(peso<=60){
    printf("3\n");
  } if(peso>=61 && peso<= 90){
    printf("2\n");
  }if (peso>91){
    printf("1\n");
  }
}
return 0;
}
