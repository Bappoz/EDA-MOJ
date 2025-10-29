#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vetor, int n, int x){
    int inicio = 0;
    int fim = n - 1;

    int meio;

    while(inicio <= fim){
        meio = (inicio + fim)/2;

        if(x <= vetor[meio]){
            fim = meio-1;
        }
        else{
            inicio = meio+1;
        }
    }
    return inicio;
}

int main(){
    int N; int M;
    scanf("%d %d", &N,&M);
    int *vetor = malloc(N*sizeof(int));
    if(vetor == NULL){
        return 1;
    }
    int valores_ordenados;

    for(int i = 0; i < N; i++){
        scanf("%d", &valores_ordenados); 
        vetor[i] = valores_ordenados;
    }
    printf("\n");
    
    int val_busca;
    int *vetor_busca = malloc(M*sizeof(int)); 
    if(vetor_busca == NULL){
        return 1;
    }
    for(int j = 0; j < M; j++){
        scanf("%d", &val_busca);
        vetor_busca[j] = val_busca;
    }
    
    printf("\n");

    for(int i = 0; i < M; i++){
        int x = vetor_busca[i];
        int resultado = buscaBinaria(vetor, N, x);

        printf("%d\n", resultado);
    }

    free(vetor);

    return 0;
}