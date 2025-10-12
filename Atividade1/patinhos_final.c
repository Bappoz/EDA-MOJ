#include <stdio.h>

int main() {
    int P;
    char mapa[1001][1001];
    int linhas = 0;
    
    scanf("%d", &P);
    
    // Lê mapa
    while (scanf("%s", mapa[linhas]) == 1) {
        linhas++;
    }
    
    int colunas = 0;
    while (mapa[0][colunas] != '\0') colunas++;
    
    // Encontra S e E
    int si = -1, sj = -1, ei = -1, ej = -1;
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 'S') { si = i; sj = j; }
            if (mapa[i][j] == 'E') { ei = i; ej = j; }
        }
    }
    
    if (si == -1 || ei == -1) {
        printf("Todos morreram :)\n");
        return 0;
    }
    
    // BFS
    static int dist[1001][1001];
    static int fila[2000000];
    int front = 0, back = 0;
    
    // Inicializa
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            dist[i][j] = -1;
        }
    }
    
    fila[back++] = si * 1001 + sj;
    dist[si][sj] = 0;
    
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    
    while (front < back) {
        int pos = fila[front++];
        int i = pos / 1001;
        int j = pos % 1001;
        
        if (i == ei && j == ej) break;
        
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            
            if (ni < 0 || ni >= linhas || nj < 0 || nj >= colunas) continue;
            if (mapa[ni][nj] == '#') continue;
            if (dist[ni][nj] != -1) continue;
            
            dist[ni][nj] = dist[i][j] + (mapa[ni][nj] == 'o' ? 1 : 0);
            fila[back++] = ni * 1001 + nj;
        }
    }
    
    if (dist[ei][ej] == -1) {
        printf("Todos morreram :)\n");
    } else {
        int sobreviventes = P - dist[ei][ej];
        if (sobreviventes <= 0) {
            printf("Todos morreram :)\n");
        } else if (sobreviventes == P) {
            printf("Nenhum morreu :(\n");
        } else {
            printf("%d encontraram o vovo\n", sobreviventes);
        }
    }
    
    return 0;
}