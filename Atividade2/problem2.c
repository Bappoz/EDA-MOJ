#include <stdio.h>

void buscandoPares(int index, char *word, int *result);

int main(){

    char word[201];
    int index = 0;
    int result = 0;

    scanf("%s", word);

    // Rascunho de ideias para a solução:
        // 1 - Criar uma função recursiva onde, começando pelo index 0, checaremos se o index+2 são iguais
        // 2 - Se for igual acrescenta +1 à um contador
        // OBS: se a string tiver menos que 3 letras automaticamente não terá par
        // 4 - Critério de parada: Se tal o index+2 de um index qualquer for NULL (ou seja, vazio), para e retorna a quantidade

    buscandoPares(index, word, &result);
    printf("%d\n", result);
    
    return 0;
}

void buscandoPares(int index, char *word, int *result){
    if(word[index] == '\0' || word[index+1] == '\0' || word[index+2] == '\0'){
        return;
    }

    if(word[index] == word[index+2]){
        (*result)++;
    }
    
    buscandoPares(index+1, word, result);

}