#include <stdio.h>

int main(){
float ph;
while (1){
  scanf("%f", &ph);
  if (ph > 7){
    printf("BASICA\n");
  } if (ph == 7){
    printf("NEUTRA\n");
  } if (ph < 7 && ph != -1){
    printf("ACIDA\n");
    } if (ph == -1){
    break;
  }
}

return 0;
}