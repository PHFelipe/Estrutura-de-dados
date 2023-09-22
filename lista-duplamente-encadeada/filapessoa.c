#include "filapessoa.h"
#include "filaprior.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(Fila *f) {
  f->inicio = f->fim = NULL;
  f->tam = 0;
}

int vazia(Fila *f) {
  if (f->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(Fila *f) { return f->tam; }

int entrar(Fila *f, char *cpf, char *nome, int idade, char *gestante) {
  
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL)
    return 0;

  Pessoa nova;
  strcpy(nova.cpf, cpf);
  strcpy(nova.nome, nome);
  nova.idade = idade;
  strcpy(nova.gestante, gestante);

  novo->dado = nova;
  novo->prox = NULL;
  f->tam++;

  //lista vazia
  if (vazia(f)) {
    f->inicio = novo;
    f->fim = novo;
    return 1;
    
  } else {
    //pessoa com prioridade
    entrarprioridade(f, novo);
  }
  return 1;
}

int sair(Fila *f, char *nome) {
  if (vazia(f))
    return 0;

  No *temp = f->inicio;
  f->inicio = f->inicio->prox;
  strcpy(nome, temp->dado.nome);
  f->tam--;
  free(temp);
  return 1;
}

void exibir(Fila *f) {
  printf("\n-------------------------\n");
  for (No *aux = f->inicio; aux != NULL; aux = aux->prox) {
    if (aux->prox == NULL) {
      printf("%s", aux->dado.nome);
    } else {
      printf("%s, ", aux->dado.nome);
    }
  }
  printf("\n-------------------------\n");
}

int exibirpriori(Fila *f, char *cpf, char *nome, int idade, char *gestante) {
  if (vazia(f))
    return 0;
  strcpy(nome, f->inicio->dado.nome);
  strcpy(cpf, f->inicio->dado.cpf);
  idade = f->inicio->dado.idade;
  strcpy(gestante, f->inicio->dado.gestante);
  return 1;
}

void texto(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}
void saida(char *mensagem,char nome[50]) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s " "\n   \033[1;%s\033[0m\n", mensagem,nome);
  printf("\n-------------------------------\n");
}
