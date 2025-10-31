#include <stdio.h>
#include <stdlib.h>


/*
inicializar ambas as listas;
fazer um loop percorra as duas listas;
verifiar qual das valoras das duas listas é menor;
add em l3 e passar para o prox tanto em l3 como a lista que retirou o valor
*/

typedef struct celula{
    int dado; 
    struct celula *prox;
} celula;


void mescla_listas(celula *l1, celula *l2, celula *l3){
    celula *currentl1 = l1->prox;
    celula *currentl2 = l2->prox;
    celula *currentl3 = l3;

    
    while(currentl1 != NULL && currentl2 != NULL){
        if(currentl1->dado <= currentl2->dado){
            currentl3->prox = currentl1;
            currentl1 = currentl1->prox;
        }
        else{
            currentl3->prox = currentl2;
            currentl2 = currentl2->prox;
        }
        currentl3 = currentl3->prox;
    }
    
    if(currentl1 != NULL){
        currentl3->prox = currentl1;
    }
    if(currentl2 != NULL){
        currentl3->prox = currentl2;
    }

    l1->prox = NULL;
    l2->prox = NULL;

}