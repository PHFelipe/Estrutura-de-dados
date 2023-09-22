#ifndef __FILADIN_H__
#define __FILADIN_H__

typedef struct no{
  char cliente[50];
  struct no *prox;
}No;

typedef struct fila{
  No *inicio;
  No *fim;
  int tam;
}Fila;

void cria(Fila *f);
int vazia(Fila *f);
int tamanho(Fila *f);
//int busca(Lista *l, int dado);
int entrar(Fila *f, char nome[50]);
int sair(Fila *f, char nome[50]);
void troca(char *mensagem, char nome[50]);
void texto(char *mensagem);
#endif


