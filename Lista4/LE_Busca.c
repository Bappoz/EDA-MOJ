#include <stdio.h>
#include <stdlib.h>


typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    celula *i;
    for(i = le->prox; i != NULL; i = i->prox){
        printf("%d -> ", le->dado);
    }
    printf("NULL");
}

void *inserir_posicao(celula *le, int dado, int pos){

    if(pos < 0){
        return;
    }

    celula *atual = le; 
    int i = 0;

    while(i < pos && atual != NULL){
        atual = atual->prox;    
        i++;
    }

    if(atual == NULL){
        return;
    }

    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return;
    }
    // vagão solto criado com o valor dado que queremos
    novo->dado = dado;

    // novo aponta para o mesmo vagão que o Atual
    // Os dois aponto para o mesmo prox
    novo->prox = atual->prox;

    // Atual agora aponta para o novo, fazendo: Atual -> Novo -> proximo ...
    // Lembrando que atual é um vagão antes da posição que queremos adicionar!
    atual->prox = novo;
}

celula *busca(celula *le, int x){
    celula *current;
    
    for(current = le->prox; current != NULL; current = current->prox ){
        if(current->dado == x){
            return current;
        }
    }   
    return NULL;
}

celula *busca_rec_aux(celula *no, int x){
    if(no == NULL){
        return NULL;
    }
    if(no->dado == x){
        return no;
    }
    return busca_rec_aux(no->prox, x);
}

celula *busca_rec(celula *le, int x){
    return busca_rec_aux(le->prox, x);
}