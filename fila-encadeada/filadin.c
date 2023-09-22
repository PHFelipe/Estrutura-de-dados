#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filadin.h"

void cria(Fila *f){
  f->inicio = f->fim = NULL;
  f->tam = 0;
}

int vazia(Fila *f){
  if (f->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(Fila *f){
  return f->tam;
}

int entrar(Fila *f, char nome[50]){
  No *novo = (No *) malloc (sizeof(No));
  
  if (novo == NULL)
    return 0;
  strcpy(novo->cliente, nome);
  novo->prox = NULL;
  f->tam++;
  
  //1o caso
  if (vazia(f)){
    f->inicio = novo;
    f->fim = novo;
    return 1; 
  }

  //2o caso: fila nao vazia
  f->fim->prox = novo;
  f->fim = novo;
  return 1;
  
}

int sair(Fila *f, char nome[50]){
  if(vazia(f)){
    return 0;
  }
  //nome do cliente que saiu
  strcpy(nome, f->inicio->cliente);
  //desalocar memoria ocupada pelo cliente
  No *temp = (No *) malloc (sizeof(No));
  temp = f->inicio;
  f->inicio = f->inicio->prox;
  free(temp);
  f->tam--;
  return 1;
}

void troca(char *mensagem,char nome[50]) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s " "\n   \033[1;%s\033[0m\n", mensagem,nome);
  printf("\n-------------------------------\n");
}

void texto(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}
