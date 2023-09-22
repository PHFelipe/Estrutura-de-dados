#include <stdio.h>
#include "listaest.h"

void menu(){
  Lista l;
  int dado,posicao,elemento,opcao;
  while(1){
    printf("Editor de Lista");
    printf("\n-------------------------------");
    printf("\n1 - Exibir lista");
    printf("\n3 - Remover");
    printf("\n4 - Exibir elemento");
    printf("\n5 - Exibir posição");
    printf("\n6 - Esvaziar Lista");
    printf("\n7 - Inserir na posição");
    printf("\n8 - sair\n");
    printf("\nDigite a opção:");
    scanf("%d",&opcao);
    if(opcao == 1){
      exibir(&l);
    }
    if(opcao == 2){
      printf("\nInsira o dado:");
      scanf("%d",&dado);
      inserir(&l,dado);
    }
    if(opcao == 3){
      printf("\nInsira o dado a ser removido:");
      scanf("%d",&dado);
      remover(&l,dado);
    }
    if(opcao == 4){
      printf("\nDigite a posição do elemento:");
      scanf("%d", &posicao);
      exib_element(&l,posicao);
    }
    if(opcao == 5){
      printf("\nDigite o elemento:");
      scanf("%d",&elemento);
      exib_posic(&l,elemento);
    }
    if(opcao == 6){
      limpar(&l);
    }
    if(opcao == 7){
      int dado,posicao;
      printf("\ndigite o dado a ser inserido na lista:");
      scanf("%d",&dado);
      printf("\ndigite a posição da lista onde será inserido o dado:");
      scanf("%d",&posicao);
      inserir_pos(&l,posicao,dado);
    }
    if(opcao == 8){
      break;
    }
    break;
  }
}