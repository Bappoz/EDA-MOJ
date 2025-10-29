#include <stdio.h>
#include <stdlib.h>


void insertion(long long *array, int n){
    
    for(int i = 1; i < n; i++){
        long long tmp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }    
}

int main(){

    long long *array = NULL; 
    // Inicializa como NULL para fazer um realloc depois ja que nao se passa o tamanho do vetor
    
    int i = 0;
    long long input;
    while(scanf("%lld", &input) != EOF){
        array = realloc(array, (i+1)*sizeof(long long));
        if(array == NULL){
            return 1;
        }
        array[i] = input;
        i++;
    }

    insertion(array, i);

    for(int j = 0; j < i; j++){
        printf("%lld ", array[j]);
    }

    free(array);

    return 0;
}