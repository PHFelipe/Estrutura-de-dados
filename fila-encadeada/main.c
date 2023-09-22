#include "filadin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char nome[50];
  int opcao;
  Fila f[3];
  cria(&f[0]);
  cria(&f[1]);
  cria(&f[2]);
  
  printf("\033[1;34mDeveloped by Pedro Medeiros and Paulo Felipe\033[0m\n");
  while (1) {
    printf("\n          Rei do mocotó Menu");
    printf("\n ========================================");
    printf("\n 1  - Inserir pedido na fila ");
    printf("\n 2  - Remover da fila de pedido");
    printf("\n 3  - Remover da fila de pagamento");
    printf("\n 4  - Remover da fila de encomenda");
    printf("\n 5  - Sair");
    printf("\n----------------------------------------");
    printf("\nDigite a opção:");
    scanf("%d", &opcao);

    if (opcao >= 1 && opcao <= 8) {
      switch (opcao) {
      case 1:
        printf("\nInfome o nome do cliente: ");
        scanf("%s", nome);
        entrar(&f[0], nome);
        texto("Pedido inserido na fila com sucesso!");
        break;
      case 2:
        // remover da lista de pedido
        sair(&f[0], nome);
        // inserir na lista de pagamento
        if (entrar(&f[1], nome) == 1) {
          troca("Cliente adicionado a lista de pagamento:", nome);
        };
        break;
      case 3:
        // remover da lista de pagamento
        sair(&f[1], nome);
        // inserir na lista de encomenda
        if (entrar(&f[2], nome) == 1) {
          troca("Cliente adicionado a lista de recebimento de encomenda:",
                nome);
        }
        break;
      case 4:
        // remover da lista de encomenda
        sair(&f[2], nome);
        // mensagem de saida
        troca("Cliente saindo com encomenda:", nome);
        break;
      }
      if (opcao == 5) {
        texto("Até Logo!");
        break;
      }
    } else {
      texto("Opção inválida, tente novamente");
    }
  }
  return 0;
}