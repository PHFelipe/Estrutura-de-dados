#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Lista l;
  int opcao;
  cria(&l);
    while (1) {
        printf("\033[1;34mDeveloped by Pedro Medeiros and Paulo Felipe\033[0m\n");
      printf("\nEditor de Lista");
      printf("\n-------------------------------");
      printf("\n1 - Exibir lista");
      printf("\n2 - Inserir");
      printf("\n3 - Remover");
      printf("\n4 - Exibir posição");
      printf("\n5 - Esvaziar Lista");
      printf("\n6 - sair\n");
      printf("\nDigite a opção:");
      scanf("%d", &opcao);
      
      if(opcao >= 1 && opcao <= 6){
        if (opcao == 1) {
          if (vazia(&l)) {
            caixinha("A lista está vazia");
          } else {
            system("clear");
            printf("\n-------------------------------\n");
            exibir(&l);
            printf("\n-------------------------------\n");
          }
        }
  
        if (opcao == 2) {
          char nome[100];
          printf("\nInsira o nome: ");
          scanf("%s", nome);
          inserir(&l, nome);
          caixinha("Nome inserido com sucesso!");
          }
        
        if (opcao == 3) {
          char nome[100];
          printf("\nInsira o nome a ser removido: ");
          scanf("%s",nome);
          remover(&l,nome);
        }
        
        if (opcao == 4) {
          char nome[100];
          if (vazia(&l)) {
            caixinha("A lista está vazia!");
          } 
          else if (busca(&l, nome) != -1) {
            printf("\nDigite o nome que procura: ");
            scanf("%s", nome);
            system("clear");
            printf("\n-------------------------------\n");
            printf("\nA posição do elemento é: %d", busca(&l, nome));
            printf("\n-------------------------------\n");
          } 
          else {
            caixinha("O elemento não se encontra na lista.");
          }
        }
        
        if (opcao == 5) {
          esvazia(&l);
          caixinha("Lista esvaziada!");
        }
        if (opcao == 6) {
          break;
        }
    }
      else{
        caixinha("Opção inválida, tente novamente.");
      }
    }
system("clear");
printf("\n-------------------------------");
printf("\nAté Logo!\n");
printf("-------------------------------\n");
}


