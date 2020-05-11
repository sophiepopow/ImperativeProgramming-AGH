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
void add(Call** map, char* name, char* number, int n){
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

// --MARK: Check if person exists in list:

// --MARK: Remove Person from the list:

// --MARK: Free the memory:


int main(int argc, const char * argv[]) {

    return 0;
}
