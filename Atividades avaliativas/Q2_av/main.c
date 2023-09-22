#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    char nome[30];
    int quantidade;
    float *preco;
  };

struct produto *criaproduto(char nome[30], int qtd);
void venda(struct produto *p1,int indice,float valor);
void precomedio(struct produto *p1);
void destruicao(struct produto *p1);

int main(){
  char nome[30];
  int qtd,valor = 0,indice;
  struct produto *p1;
  printf("digite o nome do produto:");
  scanf("%s",nome);
  printf("digite a quantidade em estoque:");
  scanf("%d",&qtd);
  p1 = criaproduto(nome,qtd);//criação do produto
  
  for(int i =0;i<qtd;i++){
    printf("insira o preço:");
    scanf("%d", &valor);
    printf("digite o indice do preço:");
    scanf("%d",&indice);
    venda(p1,indice,valor);//inserção dos preços
  }
  precomedio(p1);
  detruicao(p1);//destruicao com problema
  return 0;
}

//Escreva uma função que cria um produto: a função recebe com parâmetro o nome, e a quantidade em estoque e deve retornar a referência para o novo produto criado. Note que o array de preços deve ser alocado dinamicamente, de acordo com a quantidade de produtos em estoque;
struct produto *criaproduto(char nome[30], int qtd){
  struct produto *p1;
  p1 = (struct produto*)malloc(sizeof(struct produto));
  strcpy(p1->nome,nome);
  p1->quantidade = qtd;
  p1->preco = (float*)malloc(sizeof(float) * qtd);
  return p1;
}
//Escreva uma função que atribui um preço de venda ao produto. Essa função recebe como parâmetro a referência para o produto, o índice do array de preço a ser modificado (entre [0] e [quantidade - 1]) e o valor a ser inserido. A função só deve inserir o preço se o índice for válido e se o valor do preço for positivo;
void venda(struct produto *p1,int indice,float valor){
  int tamanho = p1->quantidade;
  if(indice <= (tamanho-1) && indice >= 0){
    if(valor > 0){
      p1->preco[indice] = valor;
    }
  }
}
//Escreva uma função que receba como parâmetro a referência para um produto e retorne o preço médio de venda (média aritmética entre todos os preços no array de preços);
void precomedio(struct produto *p1){
  int tamanho = p1->quantidade;
  float soma = 0,media = 0;
  for(int i = 0;i<tamanho;i++){
    soma = soma + p1->preco[i];
  }
  media = soma/tamanho;
  printf("a media de preços é:%f",media);
}
//Escreva uma função para desalocar um produto da memória. A função recebe como parâmetro a referência do produto a ser desalocado;
void destruicao(struct produto *p1){
  free(p1);
  free(p1->preco);
}
