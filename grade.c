#include <stdio.h>
#include <string.h>

#define MAX_COLS 10000001
// 2 <= n <= 10^7 (o + 1 é para o '\0')

char grid[2][MAX_COLS];
char buff[2][MAX_COLS];
int cols;

// tem q verificar se é um quadradinho ao redor se pa, n ta funcionando
int dfs(int row, int col) {
  if (row < 0 || row > 1 || col < 0 || col >= cols)
    return 0;
  if (grid[row][col] != '0')
    return 0;

  // marca como 1 p n revisitar (o que eu tinha visualizado como 2)
  grid[row][col] = '1';

  // soma todos os zeros
  return 1 + dfs(row, col + 1) + dfs(row, col - 1) + dfs(row + 1, col) +
         dfs(row - 2, col);
}

int main(void) {
  scanf("%d", &cols);
  scanf("%s", grid[0]);
  scanf("%s", grid[1]);
  memcpy(buff, grid, sizeof(grid));

  int total = 0;
  for (int r = 0; r < 2; r++)
    for (int c = 0; c < cols; c++)
      if (grid[r][c] == '0')
        total++;

  int res = 0;

  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < cols; c++) {
      if (buff[r][c] != '0')
        continue;

      // restaura o grid
      memcpy(grid, buff, sizeof(grid));
      grid[r][c] = '1'; // block autal

      int iniR = -1, iniC = -1;
      // procura o primeiro zero
      for (int i = 0; i < 2 && iniR == -1; i++)
        for (int j = 0; j < cols && iniR == -1; j++)
          if (grid[i][j] == '0') {
            iniR = i;
            iniC = j;
          }

      int reached = (iniR != -1) ? dfs(iniR, iniC) : 0;

      if (reached < total - 1)
        res++;
    }
  }

  printf("%d\n", res);
  return 0;
}
