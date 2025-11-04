#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main(){
    int n;
    scanf("%d", &n);
    
    int *vetor_probidos = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor_probidos[i]);
    }

    int val;
    int contador = 0;
    int vetor_armazem[1000];
    while(scanf("%d", &val) != EOF){
        vetor_armazem[contador++] = val;
        if (contador == 1000) break;
    }
    int find = 0;

    for(int j = 0; j < contador; j++){
        for(int i = 0; i < n; i++){
            if(vetor_armazem[j] == vetor_probidos[i]){
                printf("sim\n");
                find = 1;
                break;
            }
            find = 0;
        }
        if(find == 0){
            printf("nao\n");
        }
        
    }

    free(vetor_probidos);
    free(vetor_armazem);
    return 0;
}