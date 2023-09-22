#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(Lista *l) { l->inicio = NULL; }

int vazia(Lista *l) {
  if (l->inicio == NULL){
    return 1;
  }
  return 0;
}

int tamanho(Lista *l) {
  int tam = 0;
  No *aux = l->inicio;
  while (aux != NULL) {
    tam++;
    aux = aux->prox;
  }
  return tam;
}

int busca(Lista *l, char dado[100]) {
  int pos = 0;
  No *aux = l->inicio;
  // Busca do dado nas posições
  while (aux != NULL) {
    if (strcmp(dado, aux->dado) == 0) {
      return pos;
    }
    pos++;
    aux = aux->prox;
  }
  return -1;
}

int inserir(Lista *l, char dado[100]) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    return 0;
  }
  // 1o caso - Lista Vazia
  if (vazia(l)){
    for(int i =0; i<sizeof(novo->dado)-1 && dado[i] != "\0";i++){ 
      novo->dado[i]=dado[i];
    }                                  
    novo->prox = NULL;
    l->inicio = novo;
  }
  else{
  // 2o caso - Lista com elementos
  No *aux = l->inicio;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    
  novo->prox = NULL;
  //inserção do dado 
  for(int i =0; i<sizeof(novo->dado)-1 && dado[i] != "\0";i++){ 
      novo->dado[i]=dado[i];
  }   
  novo->prox = NULL;
  aux->prox = novo;
  }
  return 1;
}

int remover(Lista *l, char dado[100]) {
  if (vazia(l)){
    return 0;
  }
  
  int pos = busca(l, dado);
  if (pos == -1){
    return 0;
  }
  
  if(pos == 0) {
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);
    return 1;
  }

  No *aux = l->inicio;
  for (int i = 0; i < pos; i++) {
    aux = aux->prox;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  free(temp);
  return 1;
}

void exibir(Lista *l) {
  for (No *aux = l->inicio; aux != NULL; aux = aux->prox) {
    printf("%s \n", aux->dado);
  }
}

void caixinha(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}