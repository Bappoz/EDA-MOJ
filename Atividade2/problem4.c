#include <stdio.h>
#include <string.h>

void swap(char *a, char *b);
void change(char *word, int inicio, int fim);

int main(){
    // Objetivo: Ler uma string e à imprimir ao contrário
    // Sem usar laços e loops

    char word[501];
    scanf("%s", word);
    
    int inicio = 0;
    int fim = strlen(word) - 1;


    change(word, inicio, fim);
    printf("%s\n", word);

    return 0;
}

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void change(char *word, int inicio, int fim){
    if(inicio >= fim ){
        return;
    }

    swap(&word[inicio], &word[fim]);

    change(word, inicio+1, fim-1);

}