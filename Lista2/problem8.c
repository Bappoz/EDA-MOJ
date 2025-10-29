/*
 * Rascunho da Ideia:
 * A função de Fibonacci recursiva tradicional é muito lenta (exponencial)
 * porque recalcula os mesmos valores várias vezes (ex: fib(5) chama fib(3),
 * e fib(4) também chama fib(3)).
 * A solução eficiente (programação dinâmica com memoization) usa um array
 * global (chamado 'memo') para guardar os resultados já calculados.
 * Antes de calcular fib(n), a função verifica se o resultado já está no
 * array 'memo'. Se estiver, retorna o valor salvo. Se não, calcula
 * recursivamente, salva o novo resultado no array e então o retorna.
 * Isso garante que cada valor de Fibonacci seja calculado apenas uma vez.
 * Usamos 'unsigned long long' para armazenar resultados grandes (até n=80).
 */

#include <stdio.h>

unsigned long long v[81] = {0};

unsigned long long fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }

    if (v[n] != 0) {
        return v[n];    
    }

    unsigned long long resultado = fibonacci(n - 1) + fibonacci(n - 2);
    
    v[n] = resultado;
    
    return resultado;
}

