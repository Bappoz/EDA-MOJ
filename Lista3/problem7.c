#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int ini, int meio, int fim) {
    int n1 = meio - ini + 1;
    int n2 = fim - meio;

    int *esq = malloc(n1 * sizeof(int));
    int *dir = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) esq[i] = v[ini + i];
    for (int j = 0; j < n2; j++) dir[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            v[k] = esq[i];
            i++;
        } else {
            v[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = esq[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = dir[j];
        j++;
        k++;
    }

    free(esq);
    free(dir);
}

void merge_sort(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        merge_sort(v, ini, meio);
        merge_sort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

int busca_binaria(int v[], int n, int alvo) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == alvo) return 1;
        if (v[meio] < alvo)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *proibidos = malloc(n * sizeof(int));
    if (!proibidos) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &proibidos[i]);
    }

    merge_sort(proibidos, 0, n - 1);

    int valor;
    while (scanf("%d", &valor) != EOF) {
        if (busca_binaria(proibidos, n, valor))
            printf("sim\n");
        else
            printf("nao\n");
    }

    free(proibidos);
    return 0;
}
