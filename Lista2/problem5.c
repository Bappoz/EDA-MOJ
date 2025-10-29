#include <stdio.h>

int qtd_vogais(char *word, int i);
int main(){

    /*
    OBS: 
        - Não pode usar laços e loops
        - Limite de 100 caracteres    
        - Não contém espaços
        - é composto só por letras maisculas a entrada
    
    Rascunho para a solução:
        - lê uma string
        - cria uma função recursiva que percorre a string
        - verfica a ocorrência de vogais e acrescenta à um contador 
    */

    int i = 0;
    char word[100];
    scanf("%s", word);

    int resultado = qtd_vogais(word, i);
    printf("%d", resultado);

    return 0;

}


int qtd_vogais(char *word, int i){
    if(word[i] == '\0'){
        return 0;
    }

    return (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') 
            ? 1 + qtd_vogais(word, i+1)
            :qtd_vogais(word, i+1);
}