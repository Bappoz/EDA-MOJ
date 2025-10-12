#include <stdio.h>
/*
- Envia sem a main()
- Sem laços ou loops
- Na main do moj terá primeiro = 0 e ultimo = n-1
- int pa_recursiva (int *v, int primeiro, int ultimo)
*/

/*
Rascunho de ideias:
    - Entrada: vetor de inteiros, inicio e fim(tamanho do vetor - 1)
    - Eu devo compara o primeiro com o ultimo, segundo com penultimo
    - ou seja, aumentar o index do vetor pela esquerda e diminuir pela direita
    - Somar os valores e comparar com a proxima chamada*/
    

int pa_recursiva(int *v, int primeiro, int ultimo){
    
    // Parada função (vetor acabou) -> checou tudo e era uma PA
    if(primeiro >= ultimo - 1){
        return 1;
    }
    
    if((v[primeiro] + v[ultimo]) == (v[primeiro+1] + v[ultimo-1])){
        return pa_recursiva(v, primeiro+1, ultimo-1);
    }
    
    else{
        return 0;
    }
}


// função main só pra via de testes :

/*int main(){
    
    int n;
    scanf("%d", &n);

    int v[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int resultado = pa_recursiva(v, 0, n-1);

    return 0;
}
*/

