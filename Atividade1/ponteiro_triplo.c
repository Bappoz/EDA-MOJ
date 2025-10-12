#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int numTimes = 0;
    printf("Quantos times: ");
    scanf("%d", &numTimes);
    
    char ***times = malloc(numTimes * sizeof(char**));
    int *jogadoresPorTime = malloc(numTimes * sizeof(int)); // ← NOVO: armazena qtd jogadores
    
    if(times == NULL || jogadoresPorTime == NULL){
        return 1;
    }
    
    // Criação dos times
    for(int t = 0; t < numTimes; t++){
        printf("\nQuantos jogadores no time %d: ", t + 1);
        scanf("%d", &jogadoresPorTime[t]); // ← SALVA a quantidade
        
        times[t] = malloc(jogadoresPorTime[t] * sizeof(char*));
        
        for(int j = 0; j < jogadoresPorTime[t]; j++){ // ← USA a quantidade salva
            times[t][j] = malloc(50 * sizeof(char));
            printf("Nome do jogador %d do time %d: ", j + 1, t + 1);
            scanf("%s", times[t][j]);
        }
    }
    
    // Exibição corrigida
    printf("\n=== TIMES E JOGADORES ===\n");
    for(int t = 0; t < numTimes; t++){
        printf("\nTime %d:\n", t + 1);
        for(int j = 0; j < jogadoresPorTime[t]; j++){ // ← USA a quantidade real
            printf("  - %s\n", times[t][j]);
        }
    }
    
    // Liberação corrigida
    for(int t = 0; t < numTimes; t++){
        for(int j = 0; j < jogadoresPorTime[t]; j++){ // ← USA a quantidade real
            free(times[t][j]);
        }
        free(times[t]);
    }
    free(times);
    free(jogadoresPorTime); // ← Libera array auxiliar
    
    return 0;
}