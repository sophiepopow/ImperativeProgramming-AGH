//
//  radixSort.c
//  
//
//  Created by Sophie Popow on 28/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

int digit(char* number, int position) {
    return (int)(number[position] - '0');
}

void countingSort(char** arr, int n, int pos){
    int x = 10;
    
    int* counters = malloc(x*sizeof(int));
    
    
    for (int i = 0; i < x; i++) {
        counters[i] = 0;
    }
    for (int i=0; i < n; i++) {
        counters[digit(arr[i],pos)]++;
    }

    for (int i = 1; i < x; i++) {
        counters[i] = counters[i-1]+counters[i];
    }
    
    char** output = malloc(n*sizeof(char*));
    for(int i=n-1 ; i>=0 ; i--){
        
        output[counters[digit(arr[i],pos)] - 1] = arr[i];

        counters[digit(arr[i],pos)] -= 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(counters);

}
void radixSort(char** arr, int n, int k) {
    
    for(int i = k - 1; i >= 0; i--) {
      countingSort(arr, n, i);
    }
}
int main() {
    int Z;
    scanf("%d", &Z);
    
    while (Z--) {
        
        int n, k;
        scanf("%d", &n);
        scanf("%d", &k);
        char **arr = malloc(n*sizeof(char*));
        for(int i=0; i<n; i++) {
            arr[i] = malloc((k+1)*sizeof(char));
            scanf("%s", arr[i]);
        }
        
        radixSort(arr, n, k);
        for(int i=0; i<n; i++) {
            printf("%s\n", arr[i]);
            free(arr[i]);
        }
        free(arr);
    }
}
