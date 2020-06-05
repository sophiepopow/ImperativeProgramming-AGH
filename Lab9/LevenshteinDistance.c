//
//  LevenshteinDistance.c
//  
//
//  Created by Sophie Popow on 05/06/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_STRING_LENGTH = 200;

int minimum(int a, int b, int c){
    int tmp = ( a < b ? a : b);
    return ( tmp < c ? tmp : c);
}
int lavenshteinDistance(char* a, int a_length, char* b, int b_length){
    // Declaring a 2D array:
    int tab[a_length+1][b_length+1];

    // Initialising first column:
    for (int i = 0; i <= a_length; i++) {
        tab[i][0] = i;
    }
    
    // Initialising first row:
    for (int i = 0; i <= b_length; i++) {
           tab[0][i] = i;
    
    }
    //Applying the algorithm:
    int insertion, deletion, replacement;
    
    for (int i = 1; i < a_length+1; i++) {
        for (int j = 1; j < b_length+1; j++) {
            if(a[i-1] == b[j-1])
                tab[i][j] = tab[i-1][j-1];
            else{
                insertion = tab[i][j-1];
                deletion = tab[i-1][j];
                replacement = tab[i-1][j-1];
                
                tab[i][j] = minimum(insertion, deletion, replacement) +1;
            }
        }
    }
    
    return tab[a_length][b_length];
}
int main(){
    char* a = malloc(MAX_STRING_LENGTH*sizeof(char));
    char* b = malloc(MAX_STRING_LENGTH*sizeof(char));
    
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", lavenshteinDistance(a, strlen(a), b, strlen(b)));
}
