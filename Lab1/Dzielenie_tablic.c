//
//  Dzielenie_tablic.c
//  
//
//  Created by Sophie Popow on 13/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

void sort(int* t, int n){
  for (int i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < n-1; j++) {
      if(t[j]>t[j+1]){
        int tmp = t[j];
        t[j]=t[j+1];
        t[j+1]=tmp;
        flag = 1;
      }
    }
    if(flag == 0) break;
  }
}

int main() {

    int n;
    scanf("%d", &n);

    int e = 0, o = 0; // e - sum of even num, o - sum of odd num

    int *t1 = malloc(n*sizeof(int));
    int *t2 = malloc(n*sizeof(int));
    int *t3 = malloc(n*sizeof(int));

    int var;
    for (int i = 0; i < n; i++) {
      scanf("%d", &var);
      t1[i] = var;

      if(t1[i]%2 == 0){
        t2[e] = var;
        e+=1;
      }
      else{
        t3[o] = var;
        o+=1;
      }
    }

    printf("%d %d\n", e,o);

    sort(t2,e);
    for(int i=0; i<e; i++) {
        printf("%d\n", t2[i]);
    }
    free(t2);

    sort(t3,o);
    for(int i=0; i<o; i++) {
        printf("%d\n", t3[i]);
    }
    free(t3);

}

