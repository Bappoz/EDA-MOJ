#include <stdio.h>

#define MAX_REGIOES 8
#define MAX_TAMANHO 100000

int main() {
    int quantidadeSubmissoes[MAX_REGIOES];
    int submissao[MAX_REGIOES][MAX_TAMANHO];
    int indiceAtual[MAX_REGIOES];
    int totalSubmissoes = 0;
    int totalRegioes = MAX_REGIOES;

    for (int i = 0; i < totalRegioes; i++) {
        if (scanf("%d", &quantidadeSubmissoes[i]) != 1)
            quantidadeSubmissoes[i] = 0;

        for (int j = 0; j < quantidadeSubmissoes[i]; j++) {
            scanf("%d", &submissao[i][j]);
        }

        indiceAtual[i] = 0;
        totalSubmissoes += quantidadeSubmissoes[i];
    }

    for (int k = 0; k < totalSubmissoes; k++) {
        int menorTempo = 1000001;
        int regiaoDoMenor = -1;

        for (int r = 0; r < totalRegioes; r++) {
            if (indiceAtual[r] < quantidadeSubmissoes[r]) {
                int tempo = submissao[r][indiceAtual[r]];
                if (tempo < menorTempo) {
                    menorTempo = tempo;
                    regiaoDoMenor = r;
                }
            }
        }

        if (k > 0) printf(" ");
        printf("%d", menorTempo);
        indiceAtual[regiaoDoMenor]++;
    }

    printf("\n");
    return 0;
}
