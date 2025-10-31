#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;


void insere_inicio(celula *le, int x){
    if(le == NULL){
        return;
    }

    celula *novo = (celula* )malloc(sizeof(celula));
    if(novo == NULL) return;

    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y){

    if(le == NULL){
        return;
    }
    celula *atual = le;
    while(atual->prox != NULL && atual->prox->dado != y){ // Cobre automaticamente antes do y e antes do NULL (final da lista)
        atual=atual->prox;
    }
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return;
    }
    novo->dado = x;
    novo->prox = atual->prox;
    atual->prox = novo;
    
}