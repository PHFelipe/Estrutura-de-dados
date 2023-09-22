#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ListaDE l;
  cria(&l);
  char direcao;
  int cont = -1;
  float distancia;
  int opcao;
  while (1) {
    printf("\n          Automato movel");
    printf("\n ========================================");
    printf("\n 1  - Inserir ");
    printf("\n 2  - Exibir");
    printf("\n 3  - Insere inicio");
    printf("\n 4  - Insere na posição");
    printf("\n 5  - Remover");
    printf("\n 6  - Sair");
    printf("\n----------------------------------------");
    printf("\nDigite a opção:");
    scanf("%d", &opcao);
    if(opcao == 6){
      texto("Até logo!");
      break;
    }
    switch (opcao) {
    case 1:
      cont++;
      printf("\nInsira a direção de acordo com essa representação: "
             "\n((f)rente, (t)rás, (e)squerda e (d)ireita)\n Aqui: ");
      scanf("%*c");
      direcao = getchar();
      printf("\nInsira a distância em metros: ");
      scanf(" %f", &distancia);
      inserir(&l, cont, direcao, distancia);
      texto("Elemento inserido com sucesso!");
      break;

    case 2:
      if (vazia(&l)) {
        texto("A lista está vazia!");
      } else {
        exibir(&l);
      }
      break;

    case 3:
      cont++;
      printf("\nInsira a direção de acordo com essa representação: "
             "\n((f)rente, (t)rás, (e)squerda e (d)ireita)\n Aqui: ");
      scanf("%*c");
      direcao = getchar();
      printf("\nInsira a distância em metros: ");
      scanf(" %f", &distancia);
      insereinicio(&l, cont, direcao, distancia);
      texto("Elemento inserido com sucesso!");

    case 4:
      cont++;
      int pos;
      printf("\nDigite a posição em que deseja inserir: ");
      scanf("%d", &pos);
      printf("\nInsira a direção de acordo com essa representação: "
             "\n((f)rente, (t)rás, (e)squerda e (d)ireita)\n Aqui: ");
      scanf("%*c");
      direcao = getchar();
      printf("\nInsira a distância em metros: ");
      scanf(" %f", &distancia);
      if (inserirpos(&l, pos, cont, direcao, distancia) == 0) {
        texto("Nao foi possivel inserir nessa posição!");
        cont--;
      } else {
        texto("Elemento inserido com sucesso!");
      }
      break;

    case 5:
      if (vazia(&l)) {
        texto("A lista está vazia!");
        continue;
      }
      int num;
      printf("\nDigite o id do elemento que deseja remover: ");
      scanf("%d", &num);
      if (remover(&l, num) == 0) {
        texto("Elemento nao encontrado");
      } else {
        texto("Elemento removido com sucesso!");
      }
      break;
      
    }
  }
}