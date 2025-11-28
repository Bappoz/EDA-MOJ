#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f->p == f->u) return 0;
    
    // Remove o elemento do início da fila
    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;
    
    return 1;
}
