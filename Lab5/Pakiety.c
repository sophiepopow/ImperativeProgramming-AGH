//
//  Pakiety.c
//  
//
//  Created by Sophie Popow on 19/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DFS_Helper(int** G,int n,int* white_set,int* grey_set,int* black_set,int curr){

    //moving from white to grey
    grey_set[curr] = 1;
    white_set[curr] = 0;

    for(int i=0;i<n;i++){
        if(G[curr][i] != 0){

            if(black_set[i]){
                continue;
            }
            if(grey_set[i]){
                return 1;
            }
            if(DFS_Helper(G,n,white_set,grey_set,black_set,i)){
                return 1;
            }

        }
    }

    grey_set[curr] = 0;
    black_set[curr] = 1;
    return 0;
}

int is_not_empty_set(int *s,int n){
    int r = 0;
    for(int i=0;i<n;i++){
        r += s[i];
    }
    return r;
}

void wypisz(int * s,int n){

    for(int i=0;i<n;i++){

        printf("%d ",s[i]);
    }
    printf("\n");
}
int has_cycle(int** G, int n){

    int* white_set = malloc(n* sizeof(int));
    int* grey_set = malloc(n* sizeof(int));
    int* black_set = malloc(n* sizeof(int));

    for(int i=0;i<n;i++){
        white_set[i]=1;
    }
    memset(grey_set,0,sizeof(int)*n);
    memset(black_set,0,sizeof(int)*n);

    while(is_not_empty_set(white_set,n)){
        for(int current =0;current < n;current++){
            if(DFS_Helper(G,n,white_set,grey_set,black_set,current)){
                return 1;
            }
        }
    }


    return 0;
}

int all_in_1(int * s,int n){

    for(int i=0;i<n;i++){
        if(s[i]!= 1){
            return 0;
        }
    }
    return 1;
}
int main() {
    int n, k, p;
    scanf("%d", &n);
    scanf("%d", &k);

    int **G = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G[i] = malloc(n * sizeof(int));
        memset(G[i], 0, sizeof(int) * n);
    }

    int x, y;
    for (int j = 0; j < k; ++j) {
        scanf("%d", &x);
        scanf("%d", &y);
        G[x][y] = 1;
    }

    if(has_cycle(G,n)){
        printf("CYCLE\n");
        return 0;
    }

    printf("OK\n");

    int* display = malloc(n* sizeof(int));
    memset(display,0,sizeof(int)*n);

    while(!all_in_1(display,n)){
        for(int i=0;i<n;i++){
            int count_of_eges = 0;
            for(int j=0;j<n;j++){
                // G[j][i] nie jesli wskazuje tylko jesli jest wskazywany
                if(G[j][i] == 1)count_of_eges++;
            }
            if(!count_of_eges && !display[i]){
                printf("%d ",i);
                display[i]= 1;
                for(int j=0;j<n;j++){
                    // wymazywanie wskazywania
                    G[i][j] = 0;
                }
            }
        }
    }

    return 0;
}
