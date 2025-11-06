#include <stdio.h>
#include <stdlib.h>

typedef struct celula { 
    int dado;
    struct celula *prox;
} celula;


void divide_lista(celula *l, celula *l1, celula *l2){
    if( l == NULL ){
        return;
    }

    celula *atual = l->prox;
    celula *currentl1 = l1;
    celula *currentl2 = l2;

    while(atual != NULL){
        // Guarda o proximo de atual para nao perder ele de "vista"
        celula *proximo = atual->prox; 

        // PAR
        if(atual->dado % 2 == 0 ){
            currentl2->prox = atual;
            currentl2 = atual;
        }
        //IMPAR
        else{
            currentl1->prox = atual;
            currentl1 = atual;
        }
        atual->prox = NULL;
        atual = proximo;
    }

    currentl1->prox = NULL;
    currentl2->prox = NULL;
}