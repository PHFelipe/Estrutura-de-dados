#include "filaprior.h"
#include "filapessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int entrarprioridade(Fila *f, No *novo) {
  No *aux = f->inicio;
  if (strcmp(novo->dado.gestante, "Sim") == 0) {
    if (strcmp(f->inicio->dado.gestante, "Não") == 0) {
      novo->prox = f->inicio;
      f->inicio = novo;
    } else {
      while ((aux->prox) && (strcmp(aux->prox->dado.gestante, "Sim") == 0)) {
        aux = aux->prox;
      }
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  } else {
    if (novo->dado.idade > 64) {
      if ((f->inicio->dado.idade < 65) &&
          ((strcmp(f->inicio->dado.gestante, "Não") == 0))) {
        novo->prox = f->inicio;
        f->inicio = novo;
      } else {
        while ((aux->prox) && (aux->prox->dado.idade > 64)) {
          aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
      }
    } else {
      while ((aux->prox)) {
        aux = aux->prox;
      }
      aux->prox = novo;
      f->fim = novo;
    }
  }
  return 1;
}
