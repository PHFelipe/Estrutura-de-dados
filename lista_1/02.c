#include <stdio.h>

int main(){
  int pe;

  scanf("%i", &pe);
  int polegada = pe * 12;
  int jarda = pe / 3;
  int milha = jarda / 1760;
  printf("%i pé(s) são %i em polegada(s)\n", pe, polegada);
  printf("%i pé(s) são %i em jarda(s)\n", pe, jarda);
  printf("%i jarda(s) são %i milha(s)\n", jarda, milha);
  return 0;
}