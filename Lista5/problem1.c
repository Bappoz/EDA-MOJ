#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack{
    char *collection;
    int size;
    int capacity;
} Stack;

Stack* create_stack(int capacity){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->collection = (char*)malloc(sizeof(char) * capacity);
    if(stack->collection == NULL){
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
} 

void push(Stack* stack, char c){
    if(stack->size == stack->capacity){
        return; // evita overflow
    }
    stack->collection[stack->size++] = c;
}

char pop(Stack* stack){
    if(stack->size == 0) return '\0';
    stack->size--;
    return stack->collection[stack->size];
}

bool isValid(char* s) {
    int char_size = strlen(s);

    Stack* stack = create_stack(char_size);
    if(stack == NULL) return false;
    
    for(int i = 0; i < char_size; i++){
        char c = s[i];

        // Se for abertura → empilha
        if(c == '(' || c == '{' || c == '['){
            push(stack, c);
        }

        // Se for fechamento → desempilha e confere
        else if(c == ')' || c == '}' || c == ']'){

            if(stack->size == 0){
                free(stack->collection);
                free(stack);
                return false;
            }

            char top_char = pop(stack);

            if((c == ')' && top_char != '(') || 
               (c == '}' && top_char != '{') || 
               (c == ']' && top_char != '[')){
                free(stack->collection);
                free(stack);
                return false;
            }
        }
    }

    bool valid = (stack->size == 0);

    free(stack->collection);
    free(stack);

    return valid;
}

int main(){
    char expressao[501];

    fgets(expressao, 501, stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // remove o '\n'

    if(isValid(expressao)){
        printf("sim\n");
    }else{
        printf("nao\n");
    }

    return 0;
}
