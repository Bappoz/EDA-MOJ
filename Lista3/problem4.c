#include <stdio.h>
#include <string.h>

#define MAX_POKEMON 1000

typedef struct {
    char id[8];
    int nivel;
    int status;
} Pokemon;

int comparaPokemon(Pokemon a, Pokemon b) {
    // Primeiro critério: nível (decrescente)
    if (a.nivel != b.nivel) {
        return b.nivel - a.nivel; // > 0 se b tem nível maior
    }
    
    // Segundo critério: status (decrescente)  
    if (a.status != b.status) {
        return b.status - a.status; // > 0 se b tem status maior
    }
    
    // Se nível e status são iguais, mantém ordem original (estável)
    return 0;
}

// Função merge do Merge Sort
void merge(Pokemon arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pokemon L[n1];
    Pokemon R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (comparaPokemon(L[i], R[j]) <= 0) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++]; 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Função recursiva do Merge Sort
void mergeSort(Pokemon arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    Pokemon pokemons[MAX_POKEMON];

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", pokemons[i].id, &pokemons[i].nivel, &pokemons[i].status);
    }

    mergeSort(pokemons, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s | %d | %d", pokemons[i].id, pokemons[i].nivel, pokemons[i].status);
        if (i < n - 1) printf("\n");
    }
    if (n > 0) printf("\n");

    return 0;
}
