#ifndef LISTADIN_H
#define LISTADIN_H

typedef struct trecho {
  int idTrecho;
  char direcao;
  float distancia;
} TipoTrecho;

typedef struct no {
  struct trecho trecho;
  struct no *prox;
  struct no *ant;
} No;

typedef struct lista {
  No *inicio;
  No *fim;
} ListaDE;

void cria(ListaDE *l);
int vazia(ListaDE *l);
int tamanho(ListaDE *l);
int busca(ListaDE *l, int elem);
void exibir(ListaDE *l);
void texto(char *mensagem);
int inserir(ListaDE *l, int id, char direcao, float distancia);
int insereinicio(ListaDE *l, int id, char direcao, float distancia);
int inserirpos(ListaDE *l, int pos, int id, char direcao, float distancia);
int remover(ListaDE *l, int id);
#endif