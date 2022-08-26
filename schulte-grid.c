#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(const int argc, const char **argv) {
  int n = 4, *box;
  unsigned long long start;
  if (argc == 2) n = atoi(argv[1]);
  box = (int*)calloc(n * n, 4);
  srand(time(NULL));
  for (int i = 0; i < n * n; i++) {
    int x, y;
    do x = rand() % n, y = rand() % n;
    while (box[x * n + y]);
    box[x * n + y] = i + 1;
  }
  for (int i = 0; i < n * n; i++)
    printf("%d%c", box[i], "\t\n"[!(-~i % n)]);
  start = time(NULL);
  getchar();
  printf("used time: %llus.\n", time(NULL) - start);
}
