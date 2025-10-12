#include <stdio.h>
#include <string.h>

struct tipoBanda {
    char nome[80];
    int ano;
};

struct tipoShow {
    char nome[80];
    int qtd;
    struct tipoBanda bandas[100];
};

void pesquisarNomeBanda(char pesquisa[80], struct tipoShow shows[50], int n) {
    int encontrada = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < shows[i].qtd; j++) {
            if (strcmp(pesquisa, shows[i].bandas[j].nome) == 0) {
                printf("%s : ano %d\n", shows[i].nome, shows[i].bandas[j].ano);
                encontrada = 1;
            }
        }
    }

    if (!encontrada) {
        printf("Banda nao cadastrada\n");
    }
}
