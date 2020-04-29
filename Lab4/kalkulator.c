//
//  kalkulator.c
//
//
//  Created by Sophie Popow on 02/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int maxSize;
} stack;

void push(stack* s, int el){
    s->top++;
    s->elements[s->top] = el;
}
char pop(stack* s){
//    if(isEmpty(s)){
//        printf("err stack is empty");
//        return 0;
//    }
        s->top--;
        return s->elements[s->top+1];

}
//bool isEmpty(stack* s){
//    if(s->top == -1) return true;
//    return false;
//}

stack* newStack(int size){
    stack* s = malloc(sizeof(size));
    s->maxSize = size;
    s->elements = malloc(size*sizeof(int));
    s->top = -1;
    return s;
}
void deleteStack(stack* s){
    free(s -> elements);
    free(s);
}
bool action(char el,stack* s,int k){
    int a,b;
    if(el == '+'){
        a = pop(s);
        b = pop(s);
        push(s,a+b);
        return true;
    }
    else if(el == '-'){
        a = pop(s);
        b = pop(s);
        push(s,b-a);
         return true;
    }
    else if(el == '*'){
        a = pop(s);
        b = pop(s);
        push(s,a*b);
        return true;
    }
    else if(el == '/'){
        a = pop(s);
        b = pop(s);
        push(s,b/a);
        return true;
    }
    else{
        return false;
    }
    
}
bool isNumber(char* exp){
    if(exp[0] < '0' && exp[1] == 0)
        return false;
    return true;
}

void func(stack* s, int size, int k){
    char* expression = malloc((k+1)*sizeof(char));

    for (int i = 0; i < 2*size-1; i++) {
        scanf("%s", expression);
        if(!isNumber(expression)){
            action(expression[0],s,k);
        }
        else{
            push(s,atoi(expression));
        }
    }
    printf("%d\n", pop(s));

    free(expression);
}
int main() {
    int size;
    scanf("%d", &size);
    stack* s = newStack(size);
    int k;
    scanf("%d", &k);
    func(s,size,k);
    deleteStack(s);
}

