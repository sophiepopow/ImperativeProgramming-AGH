//
//  SkipList.c
//  SkipList
//
//  Created by Sophie Popow on 17/05/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node **next;
} Node;

typedef struct SkipList {
    struct Node *first;
    struct Node *last;
    int max_level;
} SkipList;


void printSkiplist(SkipList *sl)
{
    for(int i=sl->max_level-1; i>=0; i--)
    {
        Node *p = sl->first->next[i];
        printf("Level %d :", i);
        while(p->value != INT_MAX)
        {
            printf("%d ",p->value);
            p = p->next[i];
        }
        printf("\n");

    }
}


int rand_level(int max_level)
{
    srand((unsigned int)time(NULL));
    int level = 1;
    while(level < max_level && ((double)rand()/RAND_MAX < 0.5)) level++;
    return level;
}

void addNode(SkipList *sl, int level, int value)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = (Node **) malloc(level*sizeof(Node*));

    Node *prev[level];
    Node *p = sl->first;
    for(int i=level-1; i>=0; i--)
    {
        while(p->next[i]->value < value) p = p->next[i];
        prev[i] = p;
    }
    if(p->next[0]->value == value) return; // element already exists

    for(int i=level-1; i>=0; i--)
    {
        new_node->next[i] = prev[i]->next[i];
        prev[i]->next[i] = new_node;
    }
}

SkipList *createSkiplist(int max_level, int n)
{
    SkipList *sl = (SkipList*)malloc(sizeof(SkipList));
    sl->max_level = max_level;

    sl->first = (Node*)malloc(sizeof(Node));
    sl->first->value = INT_MIN;
    sl->first->next = (Node**)malloc(max_level*sizeof(Node*));

    sl->last = (Node*)malloc(sizeof(Node));
    sl->last->value = INT_MAX;
    sl->last->next = (Node**)malloc(max_level*sizeof(Node*));
    
    for (int i = 0; i < max_level; i++) {
        sl->first->next[i] = malloc(sizeof(Node));
        sl->last->next[i] = malloc(sizeof(Node));
    }

    for(int i=0; i<max_level; i++) sl->first->next[i] = sl->last;
    for(int i=0; i<max_level; i++) sl->last->next[i] = NULL;

    for(int i=0; i<n; i++)
    {
        int value, level = rand_level(sl->max_level);
        scanf("%d", &value);
        addNode(sl, level, value);
    }

    return sl;
}

Node *removeNode(SkipList *sl, Node *delete_node)
{

    Node *prev[sl->max_level];
    Node *p = sl->first;
    for(int i=sl->max_level-1; i>=0; i--)
    {
        while(p->next[i]->value < delete_node->value) p = p->next[i];
        prev[i] = p;
    }
    if(p->next[0]->value != delete_node->value) return NULL; // element doesn't exists

    for(int i=sl->max_level-1; i>=0; i--)
    {
        if(prev[i]->next[i]->value == delete_node->value)
        {
            prev[i]->next[i] = prev[i]->next[i]->next[i];
            delete_node->next[i] = NULL;

        }
    }
    return delete_node;
}

Node *findNode(SkipList *sl, int value)
{
    Node *v = sl->first;
    for(int i=sl->max_level-1; i>=0; i--)
        while(v->next[i]->value < value && v->next[i] != NULL)
            v = v->next[i];
    v = v->next[0];

    return v->value == value ? v : NULL;
}





int main(int argc, const char * argv[]) {
    int Z;
    scanf("%d", &Z);
    
    while(Z--){
        int max_level, n, remove, find;
        scanf("%d %d %d %d", &max_level, &n, &remove, &find);
    
        SkipList* skipList = createSkiplist(max_level, n);
        
        int num;
        
        for (int i = 0 ; i < remove; i++) {
            scanf("%d", &num);
            Node* delete_node = findNode(skipList, num);
            delete_node = removeNode(skipList, delete_node);
        }
        
        for (int i = 0 ; i < find; i++) {
            scanf("%d", &num);
            Node* find_node = findNode(skipList, num);
            if (find_node == NULL) {
                printf("N\n");
            }
            else printf("Y\n");
        }
        
        
    }
   
    return 0;
}

//1
//2 4 3 2
//3 2 5 1 5 1 3 1 2
