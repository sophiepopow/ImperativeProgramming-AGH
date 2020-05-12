// //
// //  mieszaniePodwojneHashMapa.c
// //
// //
// //  Created by Sophie Popow on 10/05/2020.
// //

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


typedef struct Call{
    char * number;
    char * name;
    char type;
    struct Call* next;
} Call;

int hashing(char* name) {
    int hash = 0;

    int min = strlen(name);
    if (min > 4) min = 4;

    for (int i = 0; i < min; i++) {
        hash = hash * 31 + ((int)name[i])*((int)name[i]);
    }
    return hash;
}

int hashing2(char* nazwisko) {
    int hash = 0;
    int min = strlen(nazwisko);
    if (min > 4) min = 4;
    for (int i = min; i >= 0; i--) {
        hash = hash * 17 + nazwisko[i];
    }
    return hash;
}


void add_call(Call** hashtable, int n, char* name, char* number){
    int hash = (hashing(name)+hashing2(name)) % n;

    // printf("hash: %d\n",hash);
    Call* newcall = malloc(sizeof(Call));
    newcall -> name = name;
    newcall -> number = number;
    newcall -> next = NULL;

    Call* head = hashtable[hash];

    if(head == NULL){
        hashtable[hash] = newcall;
        return;
    }
    while(head->next != NULL){
        head=head->next;
    }
    head->next = newcall;
}


void remove_call(Call** hashtable, int n, char* name){
    int hash = (hashing(name)+hashing2(name)) % n;

    Call* tmp = hashtable[hash];
    if(tmp == NULL) return;
    if(!strcmp(tmp->name,name)){
        hashtable[hash] = hashtable[hash] -> next;
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
        // delete tmp;
    }
}

void get_call(Call** hashtable, int n, char* name){
    int hash = (hashing(name)+hashing2(name)) % n;
    Call* tmp = hashtable[hash];
    while(tmp!=NULL){
        if(!strcmp(tmp->name,name)){
            break;
        }
        tmp = tmp->next;
    }

    if (tmp != NULL){
        printf("%s\n",tmp->number);
    }
    else printf("\n");

}

void wypisz(Call * table){
    Call * tmp = table;
    while(tmp != NULL){
        printf("%s ",tmp->number);
        tmp = tmp->next;
    }
    printf("\n");
}
int main() {

    int Z;
    scanf("%d",&Z);

    while (Z--) {
        int n, k;
        scanf("%d %d",&n,&k);


        Call** hashtable = malloc(n*sizeof(Call*));

        for (int i = 0; i < n; i++)
            hashtable[i] = NULL;

        for (int i = 0; i < k; i++) {

            struct Call call;
            char *sign = malloc(sizeof(char));
            call.name = calloc(32,sizeof(char));
            call.number = calloc(32,sizeof(char));
            scanf("%s",sign);
            call.type = sign[0];

            switch (call.type)
            {
            case 'a':
                scanf("%s %s",call.name,call.number);
                add_call(hashtable, n, call.name, call.number);
                break;

            case 'r':
                scanf("%s",call.name);
                remove_call(hashtable, n, call.name);
                break;

            case 'g':
                scanf("%s",call.name);
                get_call(hashtable, n, call.name);
                break;

            };

        }

    }
}
