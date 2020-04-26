//
//  1Szyfr_cezara.c
//  
//
//  Created by Sophie Popow on 22/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 101    //    100 chars + nullbyte

void encrypt(char* message) {
    int pivot = 0;
    int first_word_length = strlen(message)-1;
    int counter = 0;
   
    while(pivot < first_word_length && message[pivot] == ' '){
        pivot++;
    }
    while(pivot < first_word_length && message[pivot] != ' '){
        counter++;
        pivot++;
    }
    char alphabet[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    for(int i = 0; i < first_word_length; i++){
        if(message[i] != ' '){
            int j = 0;
            while(alphabet[j] != message[i]){
                j++;
            }
            message[i]=alphabet[(j+2*counter)%strlen(alphabet)];
        }
    }
}

int main() {
    char message[N];
    fgets(message, N, stdin);
    encrypt(message);
    printf("%s\n", message);
}


