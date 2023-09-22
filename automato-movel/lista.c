#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(ListaDE *l) {
  l->inicio = NULL;
  l->fim = NULL;
}

int vazia(ListaDE *l) {
  if (l->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(ListaDE *l) {
  No *aux = l->inicio;
  int cont = 0;

  while (aux != NULL) {
    aux = aux->prox;
    cont++;
  }

  return cont;
}

int busca(ListaDE *l, int id) {
  No *aux = l->inicio;
  int pos = 0;
  while (aux != NULL) {
    if (aux->trecho.idTrecho == id) {
      return pos;
    }
    pos++;
    aux = aux->prox;
  }
  return -1;
}

int inserir(ListaDE *l, int id, char direcao, float distancia) {
  No *novo = (No *)malloc(sizeof(No));
  TipoTrecho novoTrecho;

  if (novo == NULL)
    return 0;

  novoTrecho.idTrecho = id;
  strcpy(&novoTrecho.direcao, &direcao);
  novoTrecho.distancia = distancia;
  novo->trecho = novoTrecho;

  novo->prox = novo->ant = NULL;

  if (vazia(l)) {
    l->inicio = l->fim = novo;
    l->inicio->ant = l->inicio->prox = NULL;
    l->fim->ant = l->fim->prox = NULL;
    return 1;
  }

  No *temp = l->fim;
  l->fim->prox = novo;
  novo->ant = l->fim;
  l->fim = novo;
  return 1;
}

int insereinicio(ListaDE *l, int id, char direcao, float distancia) {
  No *novo = (No *)malloc(sizeof(No));
  TipoTrecho novoTrecho;

  if (novo == NULL)
    return 0;

  novoTrecho.idTrecho = id;
  strcpy(&novoTrecho.direcao, &direcao);
  novoTrecho.distancia = distancia;
  novo->trecho = novoTrecho;
  novo->prox = novo->ant = NULL;

  if (vazia(l)) {
    l->inicio = l->fim = novo;
    return 1;
  }

  novo->prox = l->inicio;
  l->inicio->ant = novo;
  l->inicio = novo;
  return 1;
}

int inserirpos(ListaDE *l, int pos, int id, char direcao, float distancia) {

  if (pos <= 0 || pos >= tamanho(l) + 2) {
    return 0;
  }
  if (pos == 1) {
    insereinicio(l, id, direcao, distancia);
    return 1;
  }
  if (pos == tamanho(l) + 1) {
    inserir(l, id, direcao, distancia);
    return 1;
  }

  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL)
    return 0;

  TipoTrecho novoTrecho;
  novoTrecho.idTrecho = id;
  strcpy(&novoTrecho.direcao, &direcao);
  novoTrecho.distancia = distancia;
  novo->trecho = novoTrecho;

  No *aux = l->inicio;
  for (int i = 1; i < pos - 1; i++) {
    aux = aux->prox;
  }
    novo->prox = aux->prox;
  novo->ant = aux;
  aux->prox->ant = novo;
  aux->prox = novo;
  return 1;
}

int remover(ListaDE *l, int id) {
  int pos = busca(l, id);
  if (pos == -1)
    return 0;


  // remocao no inicio
  if (pos == 0) {
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    free(temp);
    return 1;
  }


  No *aux = l->inicio;
  for (int i = 1; i < pos; i++) {
    aux = aux->prox;
  }

  if (pos == tamanho(l) - 1) {
    No *temp = l->fim;
    aux->prox = temp->prox;
    l->fim = aux;
    free(temp);
    return 1;
  }
  No *temp = aux->prox;
  aux->prox = aux->prox->prox;
  aux->prox->ant = aux;
  free(temp);
  
  return 1;
}

void exibir(ListaDE *l) {
  float somaPercurso = 0;
  printf("\n[");
  for (No *aux = l->inicio; aux != NULL; aux = aux->prox) {
    if (aux->prox != NULL) {
      somaPercurso += aux->trecho.distancia;
      printf("[%d, %c, %.2f], ", aux->trecho.idTrecho, aux->trecho.direcao,
             aux->trecho.distancia);
    } else {
      printf("[%d, %c, %.2f]", aux->trecho.idTrecho, aux->trecho.direcao,
             aux->trecho.distancia);
      somaPercurso += aux->trecho.distancia;
    }
  }
  printf("]\n");
  printf("\nDistância total do percurso: %.2f metros", somaPercurso);
}
void texto(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}