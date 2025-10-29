#include <stdio.h>

int busca_sete(unsigned long long n, int *contador);

int main(){

    unsigned long long n;
    int contador = 0;
    scanf("%llu", &n);

    /*
    OBJETIVO: Contar a ocorrencia de 7's em um inteiro
    Porblema principal: Como contrar casa por casa do inteiro para checar a ocorrência do número 7:
        - Transformar em vetor. Como?
        - Manipular por divisões. Como?
        - Função que busca direto a ocorrência do 7 no inteiro. Qual:

        MELHOR SOLUÇÃO:
        - checar o ultimo digito => EX: 717 % 10 = 7 , logo +1
        - Dividir por 10 faz olhar pros outros digitos => EX: 717 / 10 = 71
        - fazer a recursão novamente
    */


    int resultado = busca_sete(n, &contador);
    printf("%d\n", resultado);

    return 0;
}

int busca_sete(unsigned long long n, int *contador){
    
    if( n == 0){
        return *contador;
    }
    if( n%10 == 7){
        (*contador)++;
    }

    return busca_sete(n/10, contador);
}