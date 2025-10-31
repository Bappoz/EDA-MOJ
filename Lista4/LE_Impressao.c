#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void imprime(celula *le){
    celula *i;
    for(i = le->prox; i != NULL; i= i->prox){
        printf("%d -> ", i->dado);
    }
    printf("NULL\n");
}
void imprime_rec_aux(celula *no){
    if(no != NULL){
        printf("%d -> ", no->dado);
        imprime_rec_aux(no->prox);
    }else{
        printf("NULL\n");
    }
}

void imprime_rec(celula *le){
    imprime_rec_aux(le->prox);
}

celula* inseri_inicio(celula *le, int dado){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL){
        return NULL;
    }

    novo->dado = dado;
    novo->prox = le;

    return novo;
}


int main(){
    celula *le = NULL;
    
    le = inseri_inicio(le, 5);
    le = inseri_inicio(le, 4);
    le = inseri_inicio(le, 1);
    le = inseri_inicio(le, 3);
    le = inseri_inicio(le, 2);

    printf("\n");
    imprime(le);
    
    printf("\n");
    imprime_rec(le);


    return 0;
}