//
//  mieszaniePodwojneHashMapa.c
//
//
//  Created by Sophie Popow on 10/05/2020.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX_CHARS 31

typedef struct Person{
    int phone_number;
    char *name;
}Person;

typedef struct List{
    Person* person;
    struct List* next;
}List;


// funkcja hash string -> int
int hash(char * str){

    int hash_value = 0;
    int length = (int)strlen(str);
    for (int i=0; i<length; i++) {
        hash_value += (int) str[i];
    }
    return hash_value;
}

Person* addCall(Person* map, Person p, int n){
    int index;
    index = hash(p.name)%n;
    int i = 2;
    while(i<n && map[index]!= NULL){
        index = (i*hash(p.name))%n;
        i++;
    }
    map[index] = p;
    return map;
}
int searchForIndex(Person* map, char* name, int n){
    index = hash(name)%n;
    int i = 2;
    while(i<n && map[index].name != name){
        index = (i*hash(name))%n;
        i++;
    }
    if(map[index].name == name){
        return index;
    }
    else return NULL;
}

void removeCall(Person* map, char* name, int n){
    index = searchForIndex(int* map, char* name, int n);
    if(index != NULL){
        map[index] = NULL;
    }
}

Person* getCall(Person* map, char* name, int n){
    index = searchForIndex(int* map, char* name, int n);
    if(index != NULL){
        return map[index];
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    int z;
    scanf("%d", &z);

    while (z--) {
        int n, k;
        char op;
        char tmp_name[MAX_CHARS], tmp_phone[MAX_CHARS];

        scanf("%d", &n);
        scanf("%d", &k);

        int size = n * 20;

        List** map = (List**)calloc(size, sizeof(Person*));

        for (int i = 0; i < size; i++)
        {
            map[i] = (List*) malloc(sizeof(Person));
            map[i] = NULL;
        }

        for (int i = 0; i < k; i++)
        {
            do { scanf("%c", &op); } while(isspace(op));

            switch(op) {
                case 'a':
                    scanf("%s", tmp_name);
                    scanf("%s", tmp_phone);
                    addCall(map, tmp_name, tmp_phone, size);
                    break;
                case 'r':
                    scanf("%s", tmp_name);
                    removeCall(map, tmp_name, size);
                    break;
                case 'g':
                    scanf("%s", tmp_name);
                    char* num = getCall(map, tmp_name, size);
                    printf("%s\n", num ? num : "");
                    break;
            }
        }
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


