#include <stdio.h>

int main (char[]][] args){
  int n = scanf("%d");
  char grid[2][n];
  scanf("%s",grid[0]);
  scanf("%s",grid[1])

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == '0'){
        //É importante

        //verificar se existem movimentos possiveis
      }

    }
  }

  
}
// USAR BFS
// a cada iteracao trocar o 0 por 1 e dai rodar!!!!
// ou seja fazer um caminhozinho
// 0 0 0 0 0
// 1 1 0 1 0
// > > > > V 
// x x V x V
