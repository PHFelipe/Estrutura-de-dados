typedef struct no{
  char dado[100];
  struct no *prox;
}No;

typedef struct lista{
  No *inicio;
}Lista;

void cria(Lista *l);
int vazia(Lista *l);
int tamanho(Lista *l);
int busca(Lista *l, char dado[100]);
int inserir(Lista *l, char dado[100]);
int remover(Lista *l, char dado[100]);
void exibir(Lista *l);
void caixinha(char *mensagem);
void esvazia(Lista *l);
