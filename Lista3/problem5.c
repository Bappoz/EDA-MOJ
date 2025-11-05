#include <stdio.h>


void inserction_sort(int *vetor, int n){

    for(int i = 1; i < n; i++){
        int tmp = vetor[i];
        int j = i - 1;

        for(; j >= 0 && vetor[j] > tmp; j--){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = tmp;
    }
}

int main(){
    int vetor[1000];
    int n;
    int contador = 0;
    while(scanf("%d", &n) != EOF){
        vetor[contador++] = n;
        if(contador == 1000) break;
    }

    inserction_sort(vetor, contador);

    for(int k = 0; k < contador; k++){
        printf("%d ", vetor[k]);
    }

    printf("\n");

    return 0;
}