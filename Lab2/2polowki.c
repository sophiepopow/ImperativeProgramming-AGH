//
//  2polowki.c
//  
//
//  Created by Sophie Popow on 22/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
int main(){

    int n;
    scanf("%d", &n);
    
    int *tab = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &tab[i]);
    }

    int i = 0, j = n-1;
    int sumi = 0;
    int sumj = 0;
    
    while(i < j){
        if(sumi < sumj){
            
            sumi += tab[i];
            i +=1;
        }
        else{
            sumj += tab[j];
            j-=1;
        }
    }
    
    printf("%d\n", j);
   
}
