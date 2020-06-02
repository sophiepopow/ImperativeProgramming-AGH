//
//  WirtualnyDziekanat.c
//  
//
//  Created by Sophie Popow on 01/06/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    
}

Node* create_node(int value,char *name) {
    
}

void delete_tree(Node* root) {
    
}

void insert(Node* root, Node* student) {
    
}

Node* find(Node* root, int id) {
    
}

void delete(Node* root) {
    
}

Node* minimum(Node* root) {
    
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);
    
    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));
    
    if (n-- > 0)
    {
        scanf("%d", &number);
        scanf("%s", name);
        root = create_node(number, name);
    }
    
    while (n-- > 0)
    {
        scanf("%d", &number);
        scanf("%s", name);
        
        insert(root, create_node(number, name));
    }
    
    while (r-- > 0)
    {
        scanf("%d", &number);
        root = delete(root, number);
    }
    
    while (f-- > 0)
    {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }
    
    delete_tree(root);
    free(name);
}



