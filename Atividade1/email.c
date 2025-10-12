#include <stdio.h>

int main() {
    char nome[101];   // até 100 caracteres
    char primeiro[101];
    char ultimo[101];
    int i = 0, j = 0, k = 0;

    // Ler linha inteira (nome completo com espaços)
    fgets(nome, 101, stdin);

    // Remover \n caso exista
    while (nome[i] != '\0') {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
        i++;
    }

    // Voltar índice para início
    i = 0;

    // Converter tudo para minúsculo
    while (nome[i] != '\0') {
        if (nome[i] >= 'A' && nome[i] <= 'Z') {
            nome[i] = nome[i] - 'A' + 'a';
        }
        i++;
    }

    // Pegar primeiro nome (até o espaço)
    i = 0;
    while (nome[i] != ' ' && nome[i] != '\0') {
        primeiro[j++] = nome[i++];
    }
    primeiro[j] = '\0';


    int ultimoInicio = 0;
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == ' ' && nome[i+1] != '\0') {
            ultimoInicio = i + 1;
        }
    }

    // Copiar do último espaço até o fim
    j = 0;
    while (nome[ultimoInicio] != '\0') {
        ultimo[j++] = nome[ultimoInicio++];
    }
    ultimo[j] = '\0';

    // Imprimir no formato pedido
    printf("%s.%s@unb.br\n", primeiro, ultimo);

    return 0;
}
