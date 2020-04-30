//
//  Hyperloop.c
//  
//
//  Created by Sophie Popow on 18/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct queueElement {
    struct queueElement *next;
    int val;
} queueElement;

typedef struct queue {
    int start, end, size;
    queueElement *elements;
} queue;

queue *new_queue(int size)
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->start=0;
    q->end=0;
    q->size=size;
    q->elements=(queueElement *) malloc(size*sizeof(queueElement));
    return q;
}

void delete_queue(queue *q)
{
    free (q->elements);
    free (q);
}

queueElement* get(queue *q) {
    if (q->start+1 < q->size)
    {
        return &(q->elements[++q->start]);
    }
    else
    {
        q->start=0;
        return &(q->elements[q->start]);
    }
}

bool is_empty(queue *q) {
    if (q->start==q->end) return true;
    return false;
}

void push(int val, queue *q){
    if (q->end+1 < q->size)
    {
        q->end++;
        q->elements[q->end].val = val;

    }
    else
    {
        q->end=0;
        q->elements[q->end].val = val;

    }
}
int* BFS(int** G, int n){

    int* visited  = malloc(n* sizeof(int));
    int* connections = malloc(n* sizeof(int));
    memset(visited,0,sizeof(int)*n);
    memset(connections ,0,sizeof(int)*n);
    queueElement* node;

    queue *q = new_queue(n);

    for(int i =0; i<n;i++ ){
        if(visited[i])
            continue;
        push(i, q);
        connections[i] = i;
        while(!is_empty(q)){
            node = get(q);
            for (int j = 0; j < n ; j++) {
                if( G[node->val][j] == 1 && visited[j] == 0){
                    visited[j] = 1;
                    connections[j] = i;
                    push(j,q);
                }

            }
        }

    }
    return connections;

}

int main() {
    int n, k, p;
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &p);

    int**G = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++) {
        G[i] = malloc(n*sizeof(int));
        memset(G[i],0,sizeof(int)*n);
    }

    int x,y;
    for (int j = 0; j < k; ++j) {
        scanf("%d", &x);
        scanf("%d", &y);
        G[x][y] = 1;
        G[y][x] = 1;
    }

    int* connect = BFS(G,n);

    for (int l = 0; l < p; ++l) {
        scanf("%d", &x);
        scanf("%d", &y);
        if (connect[x] == connect[y]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
}
