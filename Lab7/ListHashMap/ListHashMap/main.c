//
//  main.c
//  ListHashMap
//
//  Created by Sophie Popow on 09/05/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


// --MARK: Call struct:

typedef struct Call{
    char* phone_number;
    char* name;
    char type;
    struct Call* next;
}Call;


// --MARK: Hashing function:
int hashing(char* name) {
    int hash = 0;

    int min = (int)strlen(name);
    if (min > 4) min = 4;

    for (int i = 0; i < min; i++) {
        hash = hash * 31 + ((int)name[i])*((int)name[i]);
    }
    return hash;
}

int hashing2(char* nazwisko) {
    int hash = 0;
    int min = (int)strlen(nazwisko);
    if (min > 4) min = 4;
    for (int i = min; i >= 0; i--) {
        hash = hash * 17 + nazwisko[i];
    }
    return hash;
}

// --MARK: Add Person to the list:

void addCall(Call** map, char* name, char* number, int n){
    int hash = (hashing(name)+hashing2(name)) % n;
    
    Call* newUser = malloc(sizeof(Call));
    newUser->name = name;
    newUser->phone_number = number;
    newUser->next = NULL;
    
    Call* head = map[hash];
    
    if(head == NULL){
        map[hash] = newUser;
        return;
    }
    while(head->next != NULL){
        head=head->next;
    }
    head->next = newUser;

}

// --MARK: Get person from the map:
void getCall(Call** map, char* name, int n){
    int hash = (hashing(name)+hashing2(name)) % n;

    Call* tmp = map[hash];
    while(tmp!=NULL){
        if(!strcmp(tmp->name,name)){
            break;
        }
        tmp = tmp->next;
    }
    if (tmp != NULL){
        printf("%s\n", tmp->phone_number);

    }
    else printf("\n");
}

// --MARK: Remove Person from the list:
void removeCall(Call** map, char* name, int n){
    int hash = (hashing(name)+hashing2(name)) % n;

    Call* tmp = map[hash];
    if(tmp == NULL) return;
    if(!strcmp(tmp->name,name)){
        map[hash] = map[hash] -> next;
        return;
    }

    Call* prev = tmp;
    tmp= tmp -> next;
    while(tmp!= NULL && strcmp(tmp->name,name)){
        tmp = tmp->next;
        prev = prev ->next;
    }
    if(tmp != NULL){
        prev->next = tmp->next;
        free(tmp);
    }
}



// --MARK: Free the memory:
void freeMemory(Call** map, int n)
{
    Call *prev, *next;
    for (int i = 0; i < n; i++)
    {
        prev = map[i];
        while (prev != NULL)
        {
            next = prev->next;
            free(prev);
            prev = next;
        }
    }
    free(map);
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
        freeMemory(map, n);
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

