#include <stdio.h>

void display(int var, int *ptr);
void update(int *p);

int main(void){

    int var = 15;
    int *ptr = &var;

    display(var, ptr);

    update(&var);

    display(var, ptr);

    return 0;

}

void display(int var, int *ptr){
    printf("\n\n");
    printf("Endereco de memoria: %p \n", &var);
    printf("Conteudo apontado pelo ptr: %d\n", *ptr);
    printf("Memoria apontada pelo ptr: %p\n", ptr);
    printf("Endereco de memoria do ptr: %p\n", &ptr);
}

void update(int *p){
    *p = *p+1;
}