#include <stdio.h>

int main(){
  char carac;
  int ano;
  int pare = 0;
  int m_ano = 0;
  int count = 0;
  int soma = 0;
  float velo;
  float media = 0;
  float m_velo = 0;
  float v_media = 0;
  
  while (pare == 0){
  scanf("%s",&carac);
  if(carac == 'n' || carac == 'N'){
    break;
  }
  else{
      scanf("%d",&ano);
      scanf("%f",&velo);
        if(ano > m_ano){
          printf("cond 1: %d\n",ano);
          m_ano = ano;
        }
        if(velo > m_velo){
          printf("cond 2: %d\n",velo);
          m_velo = velo;
        }
    count = count + 1;
    soma = soma + velo;
    }
  }
  
  media = soma/count;
  printf("maior velocidade: %.2f\ncarro mais novo: %d\nvelocidade media: %.2f", m_velo,m_ano,media);
  return 0;
}