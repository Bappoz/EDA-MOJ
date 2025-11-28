
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct Stack{
    struct ListNode* topNode;
} Stack;

Stack *create_stack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->topNode = NULL;
    return stack;
}

void push(Stack* stack, char c){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(newNode == NULL) return;

    newNode->val = c;
    newNode->next = stack->topNode;
    stack->topNode = newNode;
}

bool is_empty(Stack* stack){
    return stack->topNode == NULL;
}

char pop(Stack* stack){
    if(is_empty(stack)) return '\0';

    struct ListNode* tmp = stack->topNode;
    char c = tmp->val;

    stack->topNode = stack->topNode->next;
    free(tmp);
    return c;
}

void freeStack(Stack* stack){
    while(!is_empty(stack)){
        pop(stack);
    }
    free(stack);
}

int main(){
    int n;
    scanf("%d", &n);
    
    char str[101];
    scanf("%s", str);
    
    Stack* stack = create_stack();
    
    // Empilha todos os caracteres
    for(int i = 0; i < n; i++){
        push(stack, str[i]);
    }
    
    // Compara string original com string invertida (da pilha)
    for(int i = 0; i < n; i++){
        if(str[i] != pop(stack)){
            printf("0\n");
            freeStack(stack);
            return 0;
        }
    }
    
    printf("1\n");
    freeStack(stack);
    return 0;
}