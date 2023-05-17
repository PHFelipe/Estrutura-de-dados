#include "listase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(Lista *l) { l->inicio = NULL; }

int vazia(Lista *l) {
  if (l->inicio == NULL) {
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
  if (vazia(l)) {
    strcpy(novo->dado, dado);
    novo->prox = NULL;
    l->inicio = novo;
  } else {
    // 2o caso - Lista com elementos
    No *aux = l->inicio;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }

    novo->prox = NULL;
    // inserção do dado
    strcpy(novo->dado, dado);
    novo->prox = NULL;
    aux->prox = novo;
  }
  return 1;
}

int remover(Lista *l, char dado[100]) {
  if (vazia(l)) {
    caixinha("A lista está vazia, tente novamente.");
    return 0;
  }

  int pos = busca(l, dado);
  if (pos == -1) {
    caixinha("Nome não consta na lista.");
    return 0;
  }

  if (pos == 0) {
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);
    caixinha("Nome removido com sucesso!");
    return 1;
  }

  No *aux = l->inicio;
  for (int i = 0; i < pos - 1; i++) {
    aux = aux->prox;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  free(temp);
  caixinha("Nome removido com sucesso!");
  return 1;
}

void exibir(Lista *l) {
  for (No *aux = l->inicio; aux != NULL; aux = aux->prox) {
    printf("%s \n", aux->dado);
  }
}

void esvazia(Lista *l) {
  for (No *aux = l->inicio; aux != NULL; aux = aux->prox) {
    remover(l, aux);
  }
}

void caixinha(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}

int obterElemento(Lista *l, int posicao, char *elemento) {
  int pos = 0;
  if (vazia(l) == 0) {
    for (No *aux = l->inicio; aux != NULL; aux = aux->prox) {
      if (pos == posicao - 1) {
        strcpy(elemento, aux->dado);
        return 1;
      }
      pos++;
    }
  }
  return 0;
}

int inserirNaPosicao(Lista *l, char elemento[], int posicao) {
  int len = 1, pos = 1;
  No *aux = l->inicio, *novo = (No *)malloc(sizeof(No)), *temp;
  //verificando tamanho da lista
  while (aux != NULL) {
      aux = aux->prox;
      len++;
    }
  //mensagem de erro caso o malloc falhe
  if(novo == NULL){
    caixinha("Erro de alocação de memória");
    return 0;
  }
  // inserção do nome no novo nó
  strcpy(novo->dado, elemento);

  //1° caso: Lista vazia
  if (vazia(l)){
    caixinha("Este é o primeiro elemento,portanto\nocupará a posição 1 da lista");
    novo->prox = NULL;
    l->inicio = novo;
    return -1;
  }
  //2° caso: Inserção de um nó entre outros nós
  if(posicao < len){
    //variavel para armazenar o endereço do nó posterior
    No* endereco = NULL;
    int i = 1;
    aux = l->inicio;
    //Caso 2.1: Inserção no primeiro nó
    if(posicao == 1){
      endereco = l->inicio;
      l->inicio = novo;
      novo->prox = endereco;
      return 1;
    }
    else{
    //Empurrando um nome na posição indicada
    while (i < posicao - 1) {
      aux = aux->prox;
      i++;
    }
    endereco = aux->prox;
    aux->prox = novo;
    novo->prox = endereco;
    return 1;
    }
  }
  //3° caso: A posição dada excede o tamanho da lista
  if (posicao > len) {
    caixinha("O elemento será adicionado\nao fim da lista");
    while (aux != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
    novo->prox = NULL;
    return 0;
  } 
}
