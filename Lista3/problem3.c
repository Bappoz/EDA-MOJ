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
            v[k++] = esq[i++];
        } else {
            v[k++] = dir[j++];
        }
    }
    while (i < n1) v[k++] = esq[i++];
    while (j < n2) v[k++] = dir[j++];

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

int busca_binaria(int v[], int n, int chave) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == chave) return meio;
        if (v[meio] < chave)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main() {
    int n, chave;
    scanf("%d %d", &n, &chave);

    int *senhas = malloc(n * sizeof(int));
    int *ordenado = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &senhas[i]);
        ordenado[i] = senhas[i];
    }

    merge_sort(ordenado, 0, n - 1);

    int indice = busca_binaria(ordenado, n, chave);
    printf("%d\n", indice);

    for (int i = indice; i < n; i++) printf("%d ", senhas[i]);
    for (int i = 0; i < indice; i++) printf("%d ", senhas[i]);
    printf("\n");

    free(senhas);
    free(ordenado);
    return 0;
}
