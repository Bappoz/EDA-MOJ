#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int passos;
} Posicao;

int resolver_com_fila(char *origem, char *destino) {
    if (strcmp(origem, destino) == 0) return 0;

    int inicio_x = origem[0] - 'a';
    int inicio_y = origem[1] - '1';
    int fim_x = destino[0] - 'a';
    int fim_y = destino[1] - '1';

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int visitado[8][8];
    memset(visitado, 0, sizeof(visitado));

    Posicao fila[1000];
    int frente = 0;
    int tras = 0;

    fila[tras].x = inicio_x;
    fila[tras].y = inicio_y;
    fila[tras].passos = 0;
    tras++;
    visitado[inicio_x][inicio_y] = 1;

    while (frente < tras) {
        Posicao atual = fila[frente];
        frente++;

        if (atual.x == fim_x && atual.y == fim_y) {
            return atual.passos;
        }

        for (int i = 0; i < 8; i++) {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && visitado[nx][ny] == 0) {
                visitado[nx][ny] = 1;
                
                fila[tras].x = nx;
                fila[tras].y = ny;
                fila[tras].passos = atual.passos + 1;
                tras++;
            }
        }
    }
    return 0;
}

int main() {
    char s1[5], s2[5];

    while (scanf("%s %s", s1, s2) != EOF) {
        int resultado = resolver_com_fila(s1, s2);
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, resultado);
    }

    return 0;
}