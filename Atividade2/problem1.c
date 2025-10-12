#include <stdio.h>
#include <string.h>

void recursao(int index, char word[81], char novaWord[81]);

int main(){
    

    char word[81];
    char novaWord[81] = "";
    int index = 0;

    scanf("%s", word );

    // Rascunho de ideia de resolução:
        // 1 - Criar uma função recursiva que analisa a primeira letra da palavra e ver se é 'x', 'y' ou qualquer outra
        // 2 - Caso seja 'x' trocar para y, caso seja 'y' trocar para 'x'
        // 3- Ao trocar o char ou não trocá-lo, deve-se armazenas em uma nova string para juntar as letras trocadas
        // 4- Chamar essa função até a string estiver vazia

    recursao(index, word, novaWord);
    printf("%s", novaWord);
    
    return 0;
} 

void recursao(int index, char word[81], char novaWord[81]){
    if(word[index] == '\0'){
        novaWord[index] = '\0';
        return;
    }

    if(word[index] == 'x'){
        word[index] = 'y';
        novaWord[index] = word[index];
    }
    else{
        novaWord[index] = word[index];
    }
    
    recursao(index+1, word, novaWord);
}