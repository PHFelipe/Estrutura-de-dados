#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int m[5][5];
  int n[5][5];
  srand(time(0));
  printf("matriz M:");
  for (int i = 0; i <= 4; i++) {
    printf("\n");
    for (int j = 0; j <= 4; j++) {
      m[i][j] = rand() % 15;
      printf("%d ", m[i][j]);
    }
  }
  printf("\n\nmatriz N:");
  for (int i = 0; i <= 4; i++) {
    printf("\n");
    for (int j = 0; j <= 4; j++) {
      n[i][j] = m[i][j] * 2;
      printf("%d ", n[i][j]);
    }
  }
  return 0;
}