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

int MAX_NAME_SIZE = 30;

typedef struct Node {
    int id;
    char* name;
    struct Node *left, *right, *parent;
} Node;

Node* create_node(int id,char *name) {
    Node* student = (node*)malloc(sizeof(Node));
    
    student->name = malloc(MAX_NAME_SIZE*sizeof(char));
    strcpy(student->name,name);
    
    student->id = id;
    student->left = NULL;
    student->right = NULL;
    student->parent = NULL;
    
    return student;
}

void delete_tree(Node* root) {
    if (root = NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

void insert(Node* root, Node* student) {
    
}

Node* find(Node* root, int id) {
    
}

void delete(Node* root) {
    
}

Node* minimum(Node* root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root;
    
    return minimum(root->left);
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



