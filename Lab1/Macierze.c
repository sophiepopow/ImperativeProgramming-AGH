//
//  Macierze.c
//  
//
//  Created by Sophie Popow on 13/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int**mat = malloc(n*sizeof(int*));
  for (int i = 0; i < n; i++) {
    mat[i] = malloc(n*sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &mat[i][j]);
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if(mat[i][j] != 0){
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");

}
