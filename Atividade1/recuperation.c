#include <stdio.h>

int main(){
    
    /* ENTRADA */
    // A primeira linha de cada bloco contém Ano, Semestre e M (quantidade de disciplinas) daquele semestre

    // Em seguida, as M quantidade de disciplinas cotém 3 números int:
        // Primeiro => Código da disciplinas.
        // Segundo  => Quantos alunos matriculados
        // Terceiro => Quantos alunos foram aprovados na disciplina

    // Entrada termina por EOF


    int quantidade_materias;
    int ano, semestre, quantidade_disciplinas;
    int codigo_disciplina, quantidade_matriculados, aprovados;

    int codigo_max_reprovados[100];
    
    scanf("%d", &quantidade_materias); // 0 a 9
    
    while(scanf("%d %d %d", &ano, &semestre, &quantidade_disciplinas) != EOF){
        int maior_reprovado = -1;
        int M = quantidade_disciplinas;
        int qtd_max = 0;

        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &codigo_disciplina, &quantidade_matriculados, &aprovados);
            
            if(codigo_disciplina < 0 || codigo_disciplina >= quantidade_materias){
                printf("Nao existe esse ccdigo de materia\n");
                continue;
            }

            int reprovados = quantidade_matriculados - aprovados;

            if(reprovados > maior_reprovado){
                maior_reprovado = reprovados;
                qtd_max = 0; // reseta o contador do vetor codigo_max_reprovados[]
                codigo_max_reprovados[qtd_max++] = codigo_disciplina;
            }
            else if(reprovados == maior_reprovado){
                codigo_max_reprovados[qtd_max++] = codigo_disciplina;
            }
        }

        // Ordenar em ordem crescente
        for(int i = 0; i < qtd_max-1; i++){
            for(int j = i+1; j < qtd_max; j++){
                if(codigo_max_reprovados[i] > codigo_max_reprovados[j]){
                    int temp = codigo_max_reprovados[i];
                    codigo_max_reprovados[i] = codigo_max_reprovados[j];
                    codigo_max_reprovados[j] = temp;
                }
            }
        }
        printf("\n\n");

        // Saída
        printf("%d/%d\n\n", ano, semestre);
        for(int i = 0; i < qtd_max; i++){
            printf("%d ", codigo_max_reprovados[i]);
        }

        printf("\n");
    }

    /* SAÍDA */
    // Para cada semestre imprimir 3 linhas:
        // 1 - "ANO/SEMESTRE"
        // 2 - Código da disciplina que mais reprovou 
        // 3 - print \n 

    return 0;
}
