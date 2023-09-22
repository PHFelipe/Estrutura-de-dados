#include <stdio.h>
#include <stdlib.h>
#include "listaest.h"

typedef struct lista Lista;

int main(void) {
  Lista l;
  // [1,2,3]
  int dado,posicao,elemento,opcao;
  while(1){
    printf("\nEditor de Lista");
    printf("\n-------------------------------");
    printf("\n1 - Exibir lista");
    printf("\n2 - Inserir");
    printf("\n3 - Remover");
    printf("\n4 - Exibir elemento");
    printf("\n5 - Exibir posição");
    printf("\n6 - Esvaziar Lista");
    printf("\n7 - Inserir na posição");
    printf("\n8 - sair\n");
    printf("\nDigite a opção:");
    scanf("%d",&opcao);
    
    if(opcao == 1){
      system("clear");
      printf("\n-------------------------------");
      exibir(&l);
      printf("-------------------------------\n");
    }
    if(opcao == 2){
      printf("\nInsira o dado:");
      scanf("%d",&dado);
      inserir(&l,dado);
      system("clear");
      printf("\n-------------------------------\n");
      printf("Dado inserido com sucesso!");
      printf("\n-------------------------------\n");
    }
    if(opcao == 3){
      printf("\nInsira o dado a ser removido:");
      scanf("%d",&dado);
      remover(&l,dado);
      system("clear");
      printf("\n-------------------------------\n");
      printf("O dado %d foi removido com sucesso!",dado);
      printf("\n-------------------------------\n");
    }
    if(opcao == 4){
      printf("\nDigite a posição do elemento:");
      scanf("%d", &posicao);
      system("clear");
      printf("\n-------------------------------");
      exib_element(&l,posicao);
      printf("\n-------------------------------\n");
    }
    if(opcao == 5){
      printf("\nDigite o elemento:");
      scanf("%d",&elemento);
      system("clear");
      printf("\n-------------------------------");
      exib_posic(&l,elemento);
      printf("\n-------------------------------\n");
    }
    if(opcao == 6){
      int confirma;
      printf("\nVoce está prestes a esvaziar a lista, digite 1 para confirmar ou 0 para cancelar:");
  scanf("%d",&confirma);
      if(confirma){
      system("clear");
      printf("\n-------------------------------");
      limpar(&l);
      printf("\n-------------------------------\n");
      }else{
        system("clear");
      }
    }
    if(opcao == 7){
      int dado,posicao;
      printf("\ndigite o dado a ser inserido na lista:");
      scanf("%d",&dado);
      printf("\ndigite a posição da lista onde será inserido o dado:");
      scanf("%d",&posicao);
      system("clear");
      printf("\n-------------------------------");
      inserir_pos(&l,posicao,dado);
      printf("\n-------------------------------\n");
    }
    if(opcao == 8){
      break;
    }
    if(opcao <= 0 || opcao >8){
      system("clear");
      printf("\n-------------------------------\n");
      printf("Opção inválida, tente novamente");
      printf("\n-------------------------------\n");
    }
  }

  // cria(&l);
  // inserir(&l, 20);
  // inserir(&l, 12);
  // inserir(&l, 11);
  // inserir(&l, 21);
  // inserir(&l, 30);

  // printf("\nTamanho: %d", tamanho(&l));
  // printf("\nBusca: %d", busca(&l,20));
  // printf("\nBusca: %d", busca(&l,12));
  // printf("\nBusca: %d", busca(&l,11));
  // printf("\nBusca: %d\n", busca(&l,13));
  
  // exibir(&l);
  // printf("\nRemovendo 11...");
  // remover(&l,11);
  // exibir(&l);

  // printf("\nRemovendo 20...");
  // remover(&l,20);
  // exibir(&l);  

  // printf("\nRemovendo 30...");
  // remover(&l,30);
  // exibir(&l);
  
  return 0;
}