#include <stdio.h>

int main() {
    char nomeAeroporto[100005];
    char sigla[4];

    scanf("%s", nomeAeroporto);
    scanf("%s", sigla);

    int indiceNome = 0;
    int indiceSigla = 0;
    int tamanhoNome = 0;

    while (nomeAeroporto[tamanhoNome] != '\0') {
        tamanhoNome++;
    }

    int limiteSigla = 3;
    if (sigla[2] == 'X') {
        limiteSigla = 2;
    }

    while (indiceNome < tamanhoNome && indiceSigla < limiteSigla) {
        char letraNome = nomeAeroporto[indiceNome];
        char letraSigla = sigla[indiceSigla];

        // Converter letra do nome para maiúscula se estiver minúscula
        if (letraNome >= 'a' && letraNome <= 'z') {
            letraNome = letraNome - 'a' + 'A';
        }

        if (letraNome == letraSigla) {
            indiceSigla++;
        }

        indiceNome++;
    }

    if (indiceSigla == limiteSigla) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
