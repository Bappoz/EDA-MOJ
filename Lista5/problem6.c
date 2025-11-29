#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    
    if (novo == NULL) {
        return NULL;
    }
    
    novo->dado = x;
    
    // Fila circular: f é o último elemento, f->prox é o sentinela (cabeça)
    // O sentinela é o nó com dado 0 que sempre está no início
    celula *sentinela = f->prox;  // Guarda referência ao sentinela
    
    novo->prox = sentinela;  // Novo aponta para o sentinela
    f->prox = novo;          // Antigo último aponta para o novo
    
    return novo;  // Novo é o novo último
}