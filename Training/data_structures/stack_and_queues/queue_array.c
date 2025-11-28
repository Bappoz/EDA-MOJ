#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Fila{
    int size;
    int *collection;
    int head, tail, capacity;
} Fila;

Fila* createFila(int capacity){
    Fila* fila = malloc(sizeof(Fila));
    if(fila == NULL)return NULL;

    fila->collection = malloc(sizeof(int) * capacity);
    if(fila->collection == NULL){
        free(fila->collection);
        free(fila);
        return NULL;
    }

    fila->size = 0;
    fila->capacity = capacity;
    fila->head = 0; fila->tail = 0;

    return fila;
}

bool is_empty(Fila* f){
    return f->size == 0;
}

bool is_full(Fila* f){
    return f->size == f->capacity;
}

void enfileirar(Fila* f, int val){
    if(is_full(f)) return;
    f->collection[f->tail] = val;
    f->tail = (f->tail + 1) % f->capacity;
    f->size++;
}

void desinfileirar(Fila* f){
    if(is_empty(f)) return;
    f->head = (f->head + 1) % f->capacity;
    f->size--;
}

void printFila(Fila* f){
    for(int i = 0; i < f->size; i++){
        int index = (f->head + i) % f->capacity;
        printf(" - %d", f->collection[index]);
    }
}

void destruir_fila(Fila* f){
    free(f->collection);
    free(f);
}

int main(){
    int capacidade = 10;
    Fila* f = createFila(capacidade);

    enfileirar(f, 10);
    enfileirar(f, 25);
    enfileirar(f, 30);

    printf("HEAD");
    printFila(f);
    
    desinfileirar(f);
    printf("\n\nHEAD");
    printFila(f);
    
    destruir_fila(f);
    return 0;
}