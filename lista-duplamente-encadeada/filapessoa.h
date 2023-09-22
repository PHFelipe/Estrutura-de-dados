#ifndef __FILAPESSOA_H__
#define __FILAPESSOA_H__

typedef struct pessoa{
  char cpf[12];
  char nome[50];
  int idade;
  char gestante[5];
}Pessoa;

typedef struct no {
Pessoa dado;
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
int entrar(Fila *f, char *cpf, char *nome, int idade, char *gestante);
int sair(Fila *f, char *nome);
void exibir(Fila *f);
int exibirpriori(Fila *f, char *cpf, char *nome, int idade, char *gestante);
void texto(char *mensagem);
void saida(char *mensagem,char nome[50]);


#endif