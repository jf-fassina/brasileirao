#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int l;
  char b[100];
  char *e;
  l = strtol(fgets(b, 100, stdin), &e, 10);

  for (int i = 0; i < l; i++) {
    char p[10000];
    fgets(p, 10000, stdin);
    p[strcspn(p, "\n")] = '\0';
    int n = strlen(p);
    int k = 0;
    char o = p[n - 1];
    while (1) {
      char y = ((o - 'A') - k + 26) % 26 + 'A';
      if (y == 'Y') {
        break;
      }
      k++;
    }
    for (int j = 0; j < n; j++) {
      if (p[j] >= 'A' && p[j] <= 'Z') {
        p[j] = ((p[j] - 'A') - k + 26) % 26 + 'A';
      }
    }
    printf("%s\n", p);
  }

  return 0;
}
