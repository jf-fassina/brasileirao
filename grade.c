#include <stdio.h>

#define MAX_VALUE 10000001
// 2 <= n <= 10^7 (o + 1 é para o '\0')

int n;
char grid[2][MAX_VALUE];
int visitado[2][MAX_VALUE];

void dfs(int linha, int coluna) {
  // fora da grid
  if (linha < 0 || linha >= 2)
    return;
  if (coluna < 0 || coluna >= n)
    return;

  // bloqueado
  if (grid[linha][coluna] == '1')
    return;

  visitado[linha][coluna] = 2;

  // movimentos possíveis
  dfs(linha, coluna + 1); // direita
  dfs(linha, coluna - 1); // esquerda
  dfs(1 - linha, coluna); // troca de linha
}

int main() {
  scanf("%d", &n);

  scanf("%s", grid[0]);
  scanf("%s", grid[1]);

  dfs(0, 0);

  if (visitado[1][n - 1])
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
/* start:
 *
 * visitar(nó)
 *   marcar como visitado --> 2
 *   criar mapa(total de 0ros)
 *
 *  para cada vizinho != 1:
 *        visitar(vizinho)
 *
 *  bloquear atual
 *  para cada viz != 1:
 *    visitar(vizinho)
 *    se total de livres < (mapa-1)
 *  -Indica que teve separação?
 *
 * end;
 */

int teste() {

  scanf("%d", &n);

  scanf("%s", grid[0]);
  scanf("%s", grid[1]);

  for (int l = 0; l < 2; l++) {
    for (int c = 0; c < n; c++) {

      if (grid[l][c] != '1') {
        grid[l][c] = '2';
      }
    }
  }
}
