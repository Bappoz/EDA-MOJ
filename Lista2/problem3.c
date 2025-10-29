#include <stdio.h>

void desenhar_regua(int n);

int main(){
    int n;
    scanf("%d", &n);

    /*
    Rascunho solução:
        - entra um valor n inteiro
        - Preciso criar uma função recursiva que print 2^n - 1 linhas
        - Cada linha tem um padrão que corresponde a entrada n
            - faça uma recursão em cima e embaixo da principal que printa a regua de tamanho n
            - essa recursão recebe n - 1, e repete o processo
            - ele faz a recusão até atingir n = 0, que ai para
    */

    desenhar_regua(n);

    return 0;
}

void desenhar_regua(int n){

        if( n == 0){
            return;
        }

        desenhar_regua(n-1);

        printf(".");
        for(int i = 0; i < n; i++){
            printf("-");
        }
        printf("\n");
        
        desenhar_regua(n-1);
    
}
