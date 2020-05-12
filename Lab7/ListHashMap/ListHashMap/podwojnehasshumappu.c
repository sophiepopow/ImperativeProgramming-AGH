//
//  mieszaniePodwojneHashMapa.c
//
//
//  Created by Sophie Popow on 10/05/2020.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


typedef struct Call{
    char* phone_number;
    char* name;
    char type;
    struct Call* next;
}Call;

int hash(char * str){

    int hash_value = 0;
    int length = (int)strlen(str);
    for (int i=0; i<length; i++) {
        hash_value += (int) str[i];
    }
    return hash_value;
}

void addCall(Call** map, char* name, char* number, int n){
    int index;
    index = hash(name)%n;
    int i = 2;
    while(i<n && map[index]!= NULL){
        index = (i*hash(name))%n;
        i++;
    }
    map[index]->name = name;
    map[index]->phone_number = number;
}
int searchForIndex(Call** map, char* name, int n){
    int index = hash(name)%n;
    int i = 2;
    while(i<n && strcmp(map[index]->name, name)){
        index = (i*hash(name))%n;
        i++;
    }
    if(!strcmp(map[index]->name, name)){
        return index;
    }
    else return -1;
}

void removeCall(Call** map, char* name, int n){
    int index = searchForIndex(map, name, n);
    if(index != -1){
        map[index] = NULL;
    }
}

void getCall(Call** map, char* name, int n){
    int index = searchForIndex(map, name, n);
    if(index != -1){
        printf("%s\n", map[index]->phone_number);
    }
    printf("\n");
}



int main(int argc, const char * argv[]) {
    int z;
    scanf("%d", &z);
    
    while (z--) {
        int n, k;
        scanf("%d %d",&n,&k);


        Call** map = malloc(n*sizeof(Call*));

        for (int i = 0; i < n; i++)
            map[i] = NULL;

        for (int i = 0; i < k; i++) {

            struct Call call;
            char *sign = malloc(sizeof(char));
            call.name = calloc(32,sizeof(char));
            call.phone_number = calloc(32,sizeof(char));
            scanf("%s",sign);
            call.type = sign[0];

            switch (call.type)
            {
            case 'a':
                scanf("%s %s",call.name,call.phone_number);
                addCall(map, call.name, call.phone_number, n);
                break;

            case 'r':
                scanf("%s",call.name);
                removeCall(map, call.name, n);
                break;

            case 'g':
                scanf("%s",call.name);
                getCall(map, call.name, n);
                break;

            };

        }
        free(map);
    }
}

//1
//4
//11
//a ala 123
//a kot 234
//a pies 345
//a smok 666
//r pies
//g ala
//g pies
//g kot
//g nicosc
//a swinka 555
//g swinka


