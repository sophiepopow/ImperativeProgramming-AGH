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
// --MARK: List and Person structs:

// --MARK: Hashing function:
uint hashfunc(const char* name) {
    uint h = 0;
    for(uint i=0; i<strlen(name); i++) {
        h = h*31 + name[i];
    }
    return h;
}
// --MARK: Add Person to the list:

// --MARK: Check if person exists in list:

// --MARK: Remove Person from the list:

// --MARK: Free the memory:


int main(int argc, const char * argv[]) {

    return 0;
}
