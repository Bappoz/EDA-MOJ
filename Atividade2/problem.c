#include <stdio.h>
#include <string.h>

int contarPares(char *str) {
    if (strlen(str) < 3) {
        return 0;
    }

    int paresNestaPosicao = (str[0] == str[2]);
    return paresNestaPosicao + contarPares(str + 1);
}

int main() {
    char inputString[201];
    scanf("%s", inputString);

    // Chama a função recursiva para iniciar a contagem.
    int resultado = contarPares(inputString);

    // Imprime o resultado final.
    printf("%d\n", resultado);

    return 0;
}