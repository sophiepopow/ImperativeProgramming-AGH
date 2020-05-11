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

// --MARK: Call struct:

typedef struct Call{
    char* phone_number;
    char* name;
    char type;
    struct Call* next;
}Call;


// --MARK: Hashing function:
int hashfunc(const char* name) {
    int h = 0;
    for(int i=0; i<strlen(name); i++) {
        h = h*31 + name[i];
    }
    return h;
}

// --MARK: Add Person to the list:
void addCall(Call** map, char* name, char* number, int n){
    int hash = hashfunc(name)%n;
    
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
    int hash = hashfunc(name)%n;

    Call* tmp = map[hash];
    while(tmp!=NULL && tmp->name != name){
        tmp = tmp->next;
    }
    if (tmp != NULL){
        printf("%s\n", tmp->phone_number);

    }
    else printf("\n");
}

// --MARK: Remove Person from the list:
void removeCall(Call** map, char* name, int n){
    int hash = hashfunc(name)%n;

    Call* tmp = map[hash];
    if(tmp == NULL) return;
    if(tmp->name == name){
        map[hash] = map[hash] -> next;
        return;
    }

    Call* prev = tmp;
    tmp= tmp -> next;
    while(tmp!= NULL && tmp->name != name){
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

    int Z;
    scanf("%d", &Z);

    while (Z--) {
        int n, k;
        scanf("%d %d", &n, &k);
        Call** map = calloc(0, n*(sizeof(Call)));
        
        //memset

        for (int i = 0; i < n; i++)
            map[i] = NULL;

        for (int i = 0; i < k; i++) {

            struct Call newUser;
            scanf("%c", &newUser.type);
            switch (newUser.type)
            {
            case 'a':
                    scanf("%s %s", newUser.name, newUser.phone_number);

                addCall(map, newUser.name, newUser.phone_number, n);
                break;

            case 'r':
                scanf("%s", newUser.name);
                removeCall(map, newUser.name, n);
                break;

            case 'g':
                scanf("%s", newUser.name);
                getCall(map, newUser.name, n);
                break;

            };
        }

    }
    freeMemory(map, n);
    return 0;
}


