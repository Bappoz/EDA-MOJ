#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula* prox;
} celula;


int main()
{
    celula* fila = cria_fila();
    fila = enfileirar(fila, 12);
    fila = enfileirar(fila, 15);
    fila = enfileirar(fila, 13);

    desenfileirar(fila);
    
    return 0;
}

celula* cria_fila()
{
    celula* F = malloc(sizeof(celula));
    F->prox = F;
    return F;
}

celula* enfileirar(celula* f, int x)
{
    celula* novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = f->prox;
    f->prox = novo;
    return novo;
}

int desenfileirar(celula* f)
{
    if (check_vazio(f)) return -1;
    
    // Precisa encontrar o elemento ANTES do primeiro (para ajustar o ponteiro)
    celula* anterior = f;
    while(anterior->prox->prox != f) {
        anterior = anterior->prox;
    }
    
    // anterior->prox é o primeiro elemento (head)
    celula* lixo = anterior->prox;
    int y = lixo->dado;
    anterior->prox = lixo->prox;
    free(lixo);
    
    return y;

}

int check_vazio(celula* f)
{
    return (f->prox == f);
}

