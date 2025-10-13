#include <stdio.h>
#include <string.h>

void moverXsRecursivamente(const char* word, int index) {
    if (word[index] == '\0') {
        return;
    }

    char caractereAtual = word[index];

    if (caractereAtual != 'x') {
        printf("%c", caractereAtual);
    }

    moverXsRecursivamente(word, index + 1);

    if (caractereAtual == 'x') {
        printf("%c", caractereAtual);
    }
}

int main() {
    char word[101] = "";
    scanf("%s", word);

    moverXsRecursivamente(word, 0);
    
    printf("\n");

    return 0;
}