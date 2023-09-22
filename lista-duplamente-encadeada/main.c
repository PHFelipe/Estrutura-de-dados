#include "filapessoa.h"
#include "filaprior.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Fila f;
  cria(&f);
  char cpf[12], nome[50], gest[5];
  int idade;
  int opcao;
  printf("\033[1;34mDeveloped by Pedro Medeiros and Paulo Felipe\033[0m\n");
  while (1) {
    printf("\n          Editor de fila");
    printf("\n ========================================");
    printf("\n 1  - Exibir a fila ");
    printf("\n 2  - Entrar na fila");
    printf("\n 3  - Sair da fila");
    printf("\n 4  - Primeiro da fila");
    printf("\n 5  - Quantidade de pessoas na fila");
    printf("\n 6  - Sair");
    printf("\n----------------------------------------");
    printf("\nDigite a opção:");
    scanf("%d", &opcao);
    if(opcao == 6)
      break;
    switch (opcao) {
    case 1:
      system("clear");
      exibir(&f);
      break;

    case 2:
      printf("\nInsira o nome:");
      scanf(" %s%*[^\n]", nome);
      printf("\nInsira o CPF de 11 digitos: ");
      scanf(" %s[^\n]", cpf);
      printf("\nDigite a idade: ");
      scanf("%d", &idade);
      printf("\nÉ gestante? (Sim/Não): ");
      scanf(" %s[^\n]", gest);
      if (entrar(&f, cpf, nome, idade, gest) == 1)
        texto("Paciente inserido na fila com sucesso!");
      else
        texto("Nao foi possivel inserir o paciente na fila");
      break;

      case 3: 
        
      if (sair(&f,nome) == 0) {
        texto("A fila está vazia");
      } else if (sair(&f,nome) == 1) {
        saida("O paciente foi removido da fila:",nome);
      }
      break;
      
      case 4: 
      system("clear");
      if (exibirpriori(&f, cpf, nome, idade, gest) == 0) {
        printf("\nA fila está vazia.");
      } else if (exibirpriori(&f, cpf, nome, idade, gest) == 1) {
        printf("\n-----Primeiro(a) da Fila-----\n");
        printf("Sr.(a): %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Idade: %d\n", idade);
        printf("Gestante: %s\n", gest);
      }
      break;
      
      case 5:
      system("clear");
      printf("Existem %d pessoas na fila", tamanho(&f));
      break;
      
      default: 
      printf("\nDigite uma opção válida");
      break;
    }

  }
  return 0;
}
