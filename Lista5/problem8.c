#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char cidade[30];
    struct Node *prox;
} Node;

typedef struct Fila {
    Node *head;
    Node *tail;
} Fila;

// Cria uma fila vazia
Fila* criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) return NULL;
    f->head = NULL;
    f->tail = NULL;
    return f;
}

// Verifica se a fila está vazia
int is_empty(Fila *f) {
    return f->head == NULL;
}

// Enfileira uma cidade no final da fila
void enfileira(Fila *f, char *cidade) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) return;
    
    strcpy(novo->cidade, cidade);
    novo->prox = NULL;
    
    if (is_empty(f)) {
        f->head = novo;
        f->tail = novo;
    } else {
        f->tail->prox = novo;
        f->tail = novo;
    }
}

// Desenfileira e retorna a cidade do início da fila
Node* desenfileira(Fila *f) {
    if (is_empty(f)) return NULL;
    
    Node *removido = f->head;
    f->head = f->head->prox;
    
    if (f->head == NULL) {
        f->tail = NULL;
    }
    
    removido->prox = NULL;
    return removido;
}

// Retorna a última letra (minúscula) de uma string
char ultimaLetra(char *str) {
    int len = strlen(str);
    return tolower(str[len - 1]);
}

// Retorna a primeira letra (minúscula) de uma string
char primeiraLetra(char *str) {
    return tolower(str[0]);
}

// Libera a memória da fila
void destruirFila(Fila *f) {
    while (!is_empty(f)) {
        Node *temp = desenfileira(f);
        free(temp);
    }
    free(f);
}

int main() {
    Fila *fila = criarFila();
    char cidade[30];
    
    // Lê todas as cidades da entrada
    while (scanf("%s", cidade) != EOF) {
        enfileira(fila, cidade);
    }
    
    char ultimaLetraShow = '\0';  // Última letra da cidade do último show
    
    while (!is_empty(fila)) {
        Node *atual = desenfileira(fila);
        
        // Verifica se a cidade começa com a mesma letra que terminou o último show
        if (ultimaLetraShow != '\0' && primeiraLetra(atual->cidade) == ultimaLetraShow) {
            // Move para o final da fila
            enfileira(fila, atual->cidade);
            free(atual);
            
            // Pega a próxima cidade (mesmo que comece com a mesma letra)
            if (!is_empty(fila)) {
                atual = desenfileira(fila);
                printf("%s\n", atual->cidade);
                ultimaLetraShow = ultimaLetra(atual->cidade);
                free(atual);
            }
        } else {
            // Faz o show nesta cidade
            printf("%s\n", atual->cidade);
            ultimaLetraShow = ultimaLetra(atual->cidade);
            free(atual);
        }
    }
    
    destruirFila(fila);
    return 0;
}
