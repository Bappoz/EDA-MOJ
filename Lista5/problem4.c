#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
    char linha[MAX];

    while (fgets(linha, sizeof(linha), stdin)) {

        int pilha[MAX];  // 0 = boa, 1 = estragada
        int topo = -1;
        int count = 0;

        for (int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++) {

            char c = linha[i];

            if (c == '[') {
                // Nova caixa começa como "boa" (0 = sem x)
                pilha[++topo] = 0;
            } 
            else if (c == 'x') {
                // Marca a caixa atual como estragada
                if (topo >= 0)
                    pilha[topo] = 1;
            } 
            else if (c == ']') {
                if (topo >= 0) {
                    int estragada = pilha[topo--];

                    // Se essa caixa for BOA e válida (tem abertura e fechamento), conta
                    if (estragada == 0)
                        count++;

                    // Se ela for estragada, estraga a caixa de fora também
                    if (estragada == 1 && topo >= 0)
                        pilha[topo] = 1;
                }
            }
            // Ignora outros caracteres ('.')
        }

        printf("%d\n", count);
    }

    return 0;
}
