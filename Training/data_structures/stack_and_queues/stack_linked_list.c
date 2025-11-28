// Explicação Geral: Uma pilha (stack) é uma estrutura de dados LIFO (Last In, First Out) implementada com uma lista ligada.
// Operações principais: push (insere no topo), pop (remove do topo), peek (visualiza o topo) e is_empty (verifica se vazia).
// A lista ligada permite inserção e remoção eficientes no topo sem necessidade de deslocar elementos.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Pilha {
    Node *topNode;
} Pilha;

// Cria uma nova pilha vazia, alocando memória para a struct Pilha e inicializando o topo como NULL.
Pilha* criarStack() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) return NULL;

    p->topNode = NULL;
    return p;
}

// Insere um novo elemento no topo da pilha, criando um novo nó e ajustando os ponteiros.
void push(Pilha* p, int newData) {
    if(p == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = newData;
    newNode->next = p->topNode;
    p->topNode = newNode;
    // topNode -> newNode(Ex: 10) -> NULL
    // topNode -> newNode(Ex: 20) -> ExNewNode(Ex: 10) -> NULL
}

// Verifica se a pilha está vazia, retornando true se o topo for NULL.
bool is_empty(Pilha* p) {
    if(p == NULL) return true;
    return (p->topNode == NULL);
}

// Remove o elemento do topo da pilha, liberando a memória do nó removido e retornando true se bem-sucedido.
bool pop(Pilha* p) {

    if (is_empty(p) || p == NULL) return false;
    Node* tmp = p->topNode;

    p->topNode = p->topNode->next;
    free(tmp);
    return true;
}

// Visualiza o elemento do topo sem removê-lo, armazenando o valor em *val e retornando true se bem-sucedido.
bool peek(Pilha* p, int *val) {
    if (is_empty(p) || p == NULL) return false;

    *val = p->topNode->data;
    return true;
}

// Imprime todos os elementos da pilha do topo para a base, sem modificá-la.
void printStack(Pilha* p) {
    if (is_empty(p) || p == NULL) return;

    Node* curr = p->topNode;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

// Destrói a pilha inteira, liberando a memória de todos os nós e da struct Pilha.
void destruiPilha(Pilha *p) {
    if(p == NULL) return;

    Node* curr = p->topNode;
    Node* proximo;
    while (curr != NULL) {
        proximo = curr->next;
        free(curr);
        curr = proximo;
    }
    free(p);
    printf("Pilha Destruida");
}

// Função principal que demonstra o uso da pilha: cria, insere, remove, visualiza e destrói.
int main() {
    Pilha* pilhateste = criarStack();
    
    if (pilhateste == NULL) return 1;

    if (is_empty(pilhateste)) {
        printf("Is empty");
    } else {
        printf("Not empty");
    }
    printf("\n");
    
    push(pilhateste, 10);
    push(pilhateste, 20);
    
    printf("\n");
    
    pop(pilhateste);
    printf("\n");
    
    int val = 0;
    peek(pilhateste, &val);
    printf("Peek: %d", val);
    printf("\n");

    destruiPilha(pilhateste);

    return 0;
}