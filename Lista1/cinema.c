#include <stdio.h>
#include <string.h>

int main() {
    int qtdFileiras, qtdLugares;
    char sala[20][25][3]; 
    char bilhete[10];

    // Leitura inicial: quantidade de fileiras e lugares
    scanf("%d %d", &qtdFileiras, &qtdLugares);

    // Inicializar todos os lugares como vazios ("--")
    for (int i = 0; i < qtdFileiras; i++) {
        for (int j = 0; j < qtdLugares; j++) {
            strcpy(sala[i][j], "--");
        }
    }

    // Ler os bilhetes até EOF
    while (scanf("%s", bilhete) != EOF) {
        char letraFileira = bilhete[0];  
        int numeroLugar = atoi(&bilhete[1]); 

        int indiceFileira = letraFileira - 'A';   
        int indiceLugar = numeroLugar - 1;       

        if (indiceFileira >= 0 && indiceFileira < qtdFileiras &&
            indiceLugar >= 0 && indiceLugar < qtdLugares) {
            strcpy(sala[indiceFileira][indiceLugar], "XX");
        }
    }

    // Imprimir cabeçalho com números dos lugares
    printf("  ");
    for (int j = 0; j < qtdLugares; j++) {
        printf(" %02d", j + 1);
    }
    printf("\n");

    // Imprimir da última fileira para a primeira (de baixo para cima)
    for (int i = qtdFileiras - 1; i >= 0; i--) {
        printf("%c", 'A' + i);
        for (int j = 0; j < qtdLugares; j++) {
            printf(" %s", sala[i][j]);
        }
        printf("\n");
    }

    return 0;
}
