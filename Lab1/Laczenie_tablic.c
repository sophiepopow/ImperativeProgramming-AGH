//
//  Laczenie_tablic.c
//  
//
//  Created by Sophie Popow on 14/03/2020.
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

int count_duplicates(int * t,int n){
  int result = 1;
    for(int i=0; i<n-1; i++){
        if(t[i]!=t[i+1]){
          result++;
        }
    }
    return result;
}
void remove_duplicates(int* t, int* t2, int n){

  int x = 0;
  for (int i = 0; i < n; i++) {
      if(t[i]!=t[i+1]){
        t2[x] = t[i];
        x++;
      }
  }
}
int main() {

    int n;
    int m;
    scanf("%d", &m);
    scanf("%d", &n);


    int *t1 = malloc(m*sizeof(int));
    int *t2 = malloc(n*sizeof(int));
    int *t3 = malloc((n+m)*sizeof(int));

    int var;
    for (int i = 0; i < (n+m); i++) {
      scanf("%d", &var);

      if(i<m){
        t1[i] = var;
      }
      else{
        t2[i-m] = var;
      }
    }
    sort(t1,m);
    int len1 = count_duplicates(t1,m);
    int *arr1 = malloc(len1*sizeof(int));
    remove_duplicates(t1,arr1,m);
    free(t1);

    sort(t2,n);
    int len2 = count_duplicates(t2,n);
    int *arr2 = malloc(len2*sizeof(int));
    remove_duplicates(t2,arr2,n);
    free(t2);
    
    int l = 0, r = 0, i = 0; // left array anf right array
    while(l<len1 && r<len2){

      if(arr1[l] < arr2[r]){
        t3[i] = arr1[l];
        l+=1;
        i+=1;
      }
      else if(arr1[l] == arr2[r]){
        t3[i] = arr1[l];
        l+=1;
        r+=1;
        i+=1;
      }
      else{
        t3[i] = arr2[r];
        r+=1;
        i+=1;
      }
    }
    while (l<len1) {
      t3[i] = arr1[l];
      l+=1;
      i+=1;
    }
    while (r<len2) {
      t3[i] = arr2[r];
      r+=1;
      i+=1;
    }

    for(int x=0; x<i; x++) {
        printf("%d\n", t3[x]);
    }
    free(arr1);
    free(arr2);
    free(t3);

}
