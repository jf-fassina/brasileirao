#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char b[100];
  char *e;
  int l = strtol(fgets(b, 100, stdin), &e, 10);
  for (int i = 0; i < l; i++) {
    char p[10000];
    fgets(p, 10000, stdin);
    p[strcspn(p, "\n")] = '\0';
    int n = strlen(p);
    int k = ((p[n - 1] - 'A') - 24 + 26) % 26;
    for (int j = 0; j < n; j++) {
      if (p[j] >= 'A' && p[j] <= 'Z') {
        p[j] = ((p[j] - 'A') - k + 26) % 26 + 'A';
      }
    }
    printf("%s\n", p);
  }
  return 0;
}
