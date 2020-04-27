//
//  QuickSort.c
//
//
//  Created by Sophie Popow on 28/03/2020.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* t, int p, int r) {
    int x=t[r];
    int i=p-1,j;
    
    for(j=p ; j<r; j++)
    {
        if(t[j] < x)
        {
            i++;
            swap(&t[i],&t[j]);
        }
    }
    swap(&t[r],&t[i+1]);
    return i+1;
}

void quickSort(int t[], int p, int r) {
    if(p < r)
    {
        int q = partition(t,p,r);
        quickSort(t, p, q-1);
        quickSort(t, q+1, r);
    }
}

int main() {
    int Z;
    
    scanf("%d", &Z);
    
    while (Z--) {
        
        int n;
        scanf("%d", &n);
        int *tab = malloc(n*sizeof(n));
        for(int i=0; i<n; i++) {
            scanf("%d", &tab[i]);
        }
        
        quickSort(tab, 0, n-1);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
}

