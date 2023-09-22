#include "listadinalu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria(ListaAluno *la) { la->inicio = NULL; }

int vazia(ListaAluno *la) { 
  if (la->inicio == NULL)
    return 1;
  return 0;
}

int tamanho(ListaAluno *la) { 
  int tam = 0;
  No *aux = la->inicio;
  while (aux != NULL) {
    tam++;
    aux = aux->prox;
  }
  return tam;
}

int buscaPosMat(ListaAluno *la, int mat, int *pos) {
  *pos = 1;
  No *aux = la->inicio;
  while (aux != NULL) {
    if (aux->dado.matricula == mat) {
      return 1;
    }
    (*pos)++;
    aux = aux->prox;
  }
  return 0;
}

int buscaAlunoPos(ListaAluno *la, int pos, Aluno *al) {
  No *aux = la->inicio;

  if (pos == 1) {
    *al = la->inicio->dado;
    return 1;
  }
  if (pos > 1 && pos <= tamanho(la)) {
    for (int i = 1; aux != NULL && i < pos; i++) {
      aux = aux->prox;
    }
    *al = aux->dado;
    return 1;
  }
  return 0;
}

int buscaNome(ListaAluno *la, Aluno *al, char *nome) {
  No *aux = la->inicio;
  while (aux != NULL) {
    if (strcmp(aux->dado.nome, nome) == 0) {
      *al = aux->dado;
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}

int insereFinal(ListaAluno *la, Aluno dado) { 
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    return 0;
  }
  // 1.Caso com a lista vazia
  if (vazia(la)) {
    novo->dado = dado;
    novo->prox = NULL;
    la->inicio = novo;
    return 1;
  }
  // 2.Lista com elementos
  No *aux = la->inicio;

  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->dado = dado;
  novo->prox = NULL;
  return 1;
}
int inserePos(ListaAluno *la, Aluno dado, int pos) {
  int len;
  No *aux = la->inicio;
  len = tamanho(la);
  No *novo = (No *)malloc(sizeof(No));

  novo->dado = dado;
  // mensagem de erro caso o malloc falhe
  if (novo == NULL) {
    texto("Ocorreu algum erro de alocação de memória");
  }

  // 1º caso: Lista vazia
  if (vazia(la)) {
    texto("A lista de alunos está vazia, portanto esse será o primeiro aluno "
          "da lista");
    novo->prox = NULL;
    la->inicio = novo;
    return 1;
  }
  // Caso o usuário tente inserir na posição 1
  if (pos == 1) {
    No *anterior = NULL;
    anterior = la->inicio;
    la->inicio = novo;
    novo->prox = anterior;
    return 1;
  }
  // Inserção em qualquer local da lista
  if (pos > 1) {
    int i = 1;
    No *anterior;
    while (i != pos) {
      anterior = aux;
      aux = aux->prox;
      i++;
    }
    anterior->prox = novo;
    novo->prox = aux;
    return 1;
  }
  // posição menor que 1
  if (pos < 1) {
    texto("A posição inserida é inválida");
    return 0;
  }
  if (pos > len) {
    texto("A posição indicada excede o tamanho da lista!");
    return 0;
  }
  return 0;
}

void exibirAlunos(ListaAluno *la) { // ok
  int i = 1;
  for (No *aux = la->inicio; aux != NULL; aux = aux->prox) {
    printf("\n\n%d - %s\n Matrícula: %d | Notas: %.1f, %.1f", i, aux->dado.nome,
           aux->dado.matricula, aux->dado.nota1, aux->dado.nota2);
    i++;
  }
}

void inseredecresc(ListaAluno *la, Aluno dado) {
  No *aux = la->inicio;
  Aluno al;
  int len = tamanho(la), matricula[len + 1], troca, pos = 0, maior;
  system("clear");
  matricula[0] = dado.matricula;
  for (int i = 1; i < len + 1; i++) {
    matricula[i] = aux->dado.matricula;
    if (aux->prox != NULL) {
      aux = aux->prox;
      if (aux > aux->prox) {
        maior = dado.matricula;
      }
    }
  }
  buscaPosMat(la, maior, &pos);
  buscaAlunoPos(la, pos, &al);
  if (pos == 1) {
    inserePos(la, dado, pos);
  }
  inserePos(la, dado, (pos-1));

  for (int i = 0; i < len + 1; i++) {
    for (int j = 0; j < len + 1; j++) {
      if (matricula[j] < matricula[i]) {
        troca = matricula[i];
        matricula[i] = matricula[j];
        matricula[j] = troca;
      }
    }
  }
  
  printf("\n\n");
  system("clear");
  printf("Segue a lista de Alunos em ordem decrescente:\n");
  for (int i = 0; i < len + 1; i++) {
    buscaPosMat(la, matricula[i], &pos);
    buscaAlunoPos(la, pos, &al);
    printf("\n%d - %s - Matricula %d - Notas - %.1f, %.1f.\n", i+1, al.nome, al.matricula, al.nota1, al.nota2);
  }
}

void texto(char *mensagem) {
  system("clear");
  printf("\n-------------------------------\n");
  printf("%s ", mensagem);
  printf("\n-------------------------------\n");
}

int removeAluno(ListaAluno *la, int pos) {
  No *aux = la->inicio;
  No *anterior = NULL;
  // Teste de vazia
  if (vazia(la))
    return 0;

  // Teste de entrada inválida
  if (pos < 1 || pos > tamanho(la))
    return 0;

  // remoção do primeiro elemento
  if (pos == 1) {
    aux = la->inicio;
    la->inicio = la->inicio->prox;
    free(aux);
    return 1;
  }
  // remoção de elementos intermediarios
  else {
    for (int i = 1; aux != NULL && i < pos; i++) {
      anterior = aux;
      aux = aux->prox;
    }
    anterior->prox = aux->prox;
    free(aux);
    return 1;
  }
  return 0;
}

int removeAlunoMat(ListaAluno *la, int mat) {
  int pos;

  buscaPosMat(la, mat, &pos);
  if (removeAluno(la, pos) == 1) {
    return 1;
  }
  return 0;
}

void fl() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}

int ultima(ListaAluno *l, int ele) {
  No *aux = l->inicio;
  int pos = 0, ult = 0;
  while (aux != NULL){
    if(aux->dado.matricula == ele){
      ult = pos;
    }
    pos++;
    aux=aux->prox;
  }
  return pos;
}
