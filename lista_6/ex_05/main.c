#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Ponto{
  int x;
  int y;
};

typedef struct Ponto Ponto;

typedef struct Circulo{
  char nome[10];
  Ponto centro;
  float raio;
}Circulo;


Circulo *criaCirculo(char nome[], float x, float y, float r);
int contem(Circulo *c1, Circulo *c2);
float distancia(Ponto *p1, Ponto *p2);

int main(void) {
  Circulo *c1, *c2, *c3;

  c1 = criaCirculo("Circulo01", 3.0, 4.0, 2.0);
  c2 = criaCirculo("Circulo02", 3.0, 3.0, 1.0);
  c3 = criaCirculo("Circulo03", 1.0, 5.0, 1.0);
 
  printf("%d\n", contem(c1,c2));
  printf("%d\n", contem(c1,c3));

  free(c1);
  free(c2);
  free(c3);

}

Circulo *criaCirculo(char nome[], float x, float y, float r){
    Circulo *c = (Circulo *) malloc(sizeof(Circulo));
    strcpy(c->nome, nome);
    c->centro.x = x;
    c->centro.y = y;
    c->raio = r;

    return c;
}

float distancia(Ponto *p1, Ponto *p2){
  return sqrt((p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y));
}

int contem(Circulo *c1, Circulo *c2){
  return ((distancia(&c1->centro, &c2->centro)+c2->raio ) <= c1->raio);
}
