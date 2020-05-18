//
//  SkipList.h
//  SkipList
//
//  Created by Sophie Popow on 17/05/2020.
//  Copyright © 2020 Sophie Popow. All rights reserved.
//

#ifndef SkipList_h
#define SkipList_h

#include <stdio.h>

typedef struct Node {
    int value;
    struct Node **next;
} Node;

typedef struct SkipList {
    struct Node *first;
    struct Node *last;
    int max_level;
} SkipList;

SkipList *create_skiplist(int max_level, int n);
void addNode(SkipList *sl, int level, int value);
Node *removeNode(SkipList *(&sl), Node *delete_node);
Node *findNode(SkipList *sl, int value);
void printSkiplist(SkipList *sl);
int rand_level(int max_level);

#endif /* SkipList_h */
