#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado; 
    struct celula *prox;
} celula;

void remove_depois(celula *p){
    if(p == NULL){
        return;
    }
    if(p->prox == NULL){
        return;
    }

    celula *no_remover = p->prox;
    p->prox = no_remover->prox;
    free(no_remover);

}

void remove_elemento(celula *le, int x){
    if(le == NULL){
        return;
    }

    celula *atual = le;
    while(atual->prox != NULL && atual->prox->dado != x ){
        atual = atual->prox;
    }

    if(atual->prox == NULL){
        return;
    }

    celula *no_deletar = atual->prox;
    atual->prox = no_deletar->prox;
    free(no_deletar);
    
}
void remove_todos_elementos(celula *le, int x){
    if(le == NULL){
        return;
    }

    celula *atual = le;
    while(atual->prox != NULL ){
        if(atual->prox->dado == x){
            celula *no_deletar = atual->prox;
            atual->prox = no_deletar->prox;
            free(no_deletar);
        }
        else{
            atual = atual->prox;
        }
    }

    if(atual->prox == NULL){
        return;
    }
}