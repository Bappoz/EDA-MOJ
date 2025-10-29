#include <stdio.h>

int x_recursao(char *word, int index, char *resultado, int pos_resultado);


int main(){

    char word[101];
    char resultado[101];
    scanf("%s", word);

    /*
    Rascunho da Solução:
        - OBJ: Entra uma string onde devo jogar todas as ocorrências da letra x para o final
        Solução 1:
            - fazer uma função recursiva onde avalia se tal indice da string é um x
            - Se for um x, ele armazena em uma váriavel temporária
            - E por meio da recursão avaliamos o restante da string
    */

    int total_pos = x_recursao(word, 0, resultado, 0);
    resultado[total_pos] = '\0';
    printf("%s", resultado);


    return 0;
}


int x_recursao(char *word, int index, char *resultado, int pos_resultado){

    if(word[index] == '\0'){
        return pos_resultado;
    }

    if(word[index] != 'x'){
        resultado[pos_resultado] = word[index];
        pos_resultado++;
    }

    int pos_final = x_recursao(word, index+1, resultado, pos_resultado);

    if(word[index] == 'x'){
        resultado[pos_final] = 'x';
        pos_final++;
    }
    return pos_final;
}