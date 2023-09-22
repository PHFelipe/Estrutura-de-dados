#define MAX 30

struct lista{
  int dados[MAX];
  int tamanho;
 // int posUltimo;
};

typedef struct lista Lista;

void cria(Lista *l);
int vazia(Lista *l);
int cheia(Lista *l);
int tamanho(Lista *l);
int busca(Lista *l, int dado);
int inserir(Lista *l, int dado);
void inserir_pos(Lista *l,int posicao,int dado);
int remover(Lista *l, int dado);
void exibir(Lista *l);
void exib_element(Lista *l,int posicao);
void exib_posic(Lista *l,int elemento);
void limpar(Lista *l);

