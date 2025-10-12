#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void permutacao(char str[], int inicio, int fim);
void swap(char *a, char *b);

int main(){

    int tamanho = 0;

    printf("Entre o numero do tamanho da array: ");
    scanf("%d", &tamanho);

    char *letras = malloc((tamanho + 1) * sizeof(char));

    if(letras == NULL){
        return 1;
    }

    for(int i = 0; i < tamanho; i++){
        printf("Digite o caractere #%d:  ", i + 1);
        scanf(" %c", &letras[i]);
    }
    letras[tamanho] = '\0';

    printf("Permutacoes: \n");
    permutacao(letras, 0, tamanho - 1);

    free(letras);
    letras = NULL;
    return 0;
}

void permutacao(char str[], int inicio, int fim){

    if ( inicio == fim ){
        printf("%s\n", str);
    }   
    else{
        for(int i = inicio; i <= fim; i++){
            swap(&str[inicio], &str[i]);
            permutacao(str, inicio + 1, fim);
            swap(&str[inicio], &str[i]);
        }
    }
    
} 
 

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}