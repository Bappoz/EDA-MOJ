#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    // Ponteiro duplo - Array de strings (nomes de jogadores)
    int numJogadores = 0;
    printf("Quantos jogadores: ");
    scanf("%d", &numJogadores);
    
    // Aloca array de ponteiros para strings
    char **nomes = malloc(numJogadores * sizeof(char*));
    if(nomes == NULL){
        return 1;
    }
    
    // Preenche cada nome
    for(int i = 0; i < numJogadores; i++){
        nomes[i] = malloc(50 * sizeof(char)); // 50 chars por nome
        printf("Digite nome do jogador #%d: ", i + 1);
        scanf("%s", nomes[i]);
    }
    
    // Exibe todos os nomes
    printf("\nJogadores cadastrados:\n");
    for(int i = 0; i < numJogadores; i++){
        printf("%d. %s\n", i + 1, nomes[i]);
    }
    
    // Libera memória
    for(int i = 0; i < numJogadores; i++){
        free(nomes[i]); // Libera cada string
    }
    free(nomes); // Libera array de ponteiros
    
    return 0;
}