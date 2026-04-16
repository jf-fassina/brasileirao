#include <stdio.h>

int n;
char grid[2][10000001]; // 2 <= n <= 10^7 (o + 1 é para o '\0')
int visitado[2][10000001];

void dfs(int linha, int coluna) {
  // fora da grid
  if (linha < 0 || linha >= 2)
    return;
  if (coluna < 0 || coluna >= n)
    return;

  // bloqueado ou já visitado
  if (grid[linha][coluna] == '1' || visitado[linha][coluna])
    return;

  visitado[linha][coluna] = 1;

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
/* USAR BFS
 a cada iteracao trocar o 0 por 1 e dai rodar!!!!
 ou seja fazer um caminhozinho
 0 0 0 0 0
 1 1 0 1 0
 > > > > V
 x x V x V

 start:
 * visitar(nó)
 *   marcar como visitado
 *
 *  para cada vizinho:
 *    se não foi visitado:
 *        visitar(vizinho)
 end;
 */
