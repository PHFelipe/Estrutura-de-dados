#include <stdio.h>
#include "listaest.h"

typedef struct lista Lista;

void cria(Lista *l){
  l->tamanho = 0;
}

int vazia(Lista *l){
  return l->tamanho == 0;
}

int cheia(Lista *l){
  return l->tamanho == MAX;
}

int tamanho(Lista *l){
  return l->tamanho;
}

// retorna a posicao quando encontrar
// o elemento
// ou -1 caso contrario
int busca(Lista *l, int dado){
  for (int i=0; i<l->tamanho; i++){
    if (l->dados[i] == dado)
      return i;
  }  
  return -1;
}

// inserir no final da lista
int inserir(Lista *l, int dado){
  if (cheia(l))
    return 0;
  l->dados[l->tamanho] = dado;
  l->tamanho++;
  return 1;
}

void inserir_pos(Lista *l,int posicao,int dado){
  if(cheia(l)){
    printf("\nA lista está cheia, não há como inserir mais nenhum dado!");
  }else{
    l->tamanho++;
    for(int i = l->tamanho - 1; i >= posicao; i--){
      l->dados[i+1] = l->dados[i];
    }
    l->dados[posicao] = dado;
    printf("\nO dado foi inserido na posição %d com sucesso",posicao);
  }
}

int remover(Lista *l, int dado){
  if (vazia(l))
    return 0;
  
  int pos = busca(l,dado);
  if (pos==-1)
    return 0;

  for (int i=pos; i<l->tamanho-1; i++){
     l->dados[i] = l->dados[i+1]; 
  }
  l->tamanho--;
  return 1;
}


void exibir(Lista *l){
  printf("\n[");
  for (int i=0; i < l->tamanho; i++){
    if (i != l->tamanho-1)
     printf("%d,", l->dados[i]);
    else
      printf("%d", l->dados[i]);
  }
  printf("]\n");
}
void exib_element(Lista *l,int posicao){
  if(posicao <= l->tamanho && posicao >= 0){
    printf("\n%d", l->dados[posicao]);
  }else{
    printf("\nPosição inválida, tente novamente");
  }
}
void exib_posic(Lista *l,int elemento){
  int achou = 0;
  for(int i = 0; i< l->tamanho;i++){
    if(elemento == l->dados[i]){
      printf("\n%d", i);
      achou = 1;
    }
    }if(achou == 0){
    printf("\nO elemento nao foi encontrado\ndentro da lista");
    }
}

void limpar(Lista *l){
    if(vazia(l)){
      printf("\nA lista já está vazia");
    }else{
      for(int i = 0; i< l->tamanho;i++){
        l->dados[i] = 0;
      }
      l->tamanho = 0;
      printf("\nA lista foi esvaziada com sucesso");
    }
}