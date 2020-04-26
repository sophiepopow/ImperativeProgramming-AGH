
//
//  3Liczby.c
//
//
//  Created by Sophie Popow on 22/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool war(int i){
    while(i>0){
        if((i/10)%10 > i%10)
            return false;
        i/=10;
    }
    return true;
}
void sieve(int *tab, int n){
    for (int i = 2; i*i <= n; i++) {
        while(tab[i] != 1 && i*i <= n){
            i++;
        }
       
        for(int j = 2*i; j <= n; j += i){
            tab[j] = 0;
        }
    }
}
int main() {
    
    int n;
    scanf("%d", &n);
    
    int *tab = malloc(n*sizeof(int));
    tab[0] = 0;
    tab[1] = 0;

    for(int i = 2; i <n; i++){
        tab[i] = 1;
    }
    sieve(tab,n-1);
    
    for (int i = 2; i < n ; i++) {
          if(tab[i] == 1 && (war(i))){
                  printf("%d\n", i);
              }
    }
    
    return 0;
}


