//
//  HeapSort.c
//  
//
//  Created by Sophie Popow on 28/03/2020.
//

#include<stdio.h>
#include<stdlib.h>

 void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
 }
  
 void heapify(int arr[], int n, int index) {
   int largest = index;
   int baby1 = 2*index+1;
   int baby2 = 2*index+2;
  
   if(baby1 < n && arr[baby1] > arr[largest]) largest = baby1;
   if(baby2 < n && arr[baby2] > arr[largest]) largest = baby2;
  
   if(largest != index) {
     swap(&arr[index], &arr[largest]);
     heapify(arr, n, largest);
   }
 }
  
 void heapSort(int arr[], int n) {
   for(int i = n/2 - 1; i >= 0; i--)
     heapify(arr, n, i);
  
   for(int i = n-1; i >= 0; i--) {
     swap(&arr[0], &arr[i]);
     heapify(arr, i, 0);
   }
 }

 
int main() {
    int Z;
    scanf("%d", &Z);

    while (Z--) {
        int n;
        scanf("%d", &n);
        int *a = malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        heapSort(a, n);
        for(int i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }
        free(a);
    }
}


