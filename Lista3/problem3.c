#include <stdio.h> 
#include <stdlib.h>

void merge(int *leftArray, int *rightArray, int *vetor, int n){
    int middle = n / 2;

    int left_size = middle;
    int right_size = n - middle;

    int i = 0;
    int l = 0;
    int r = 0;

    while(l < left_size && r < right_size){
        if(leftArray[l] < rightArray[r]){
            vetor[i] = leftArray[l];
            l++;
            i++;
        }
        else{
            vetor[i] = rightArray[r];
            r++;
            i++;
        }
    }
    while( l < left_size){
        vetor[i] = leftArray[l];
        l++;
        i++;
    }
    while(r < right_size){
        vetor[i] = rightArray[r];
        r++;
        i++;
    }
    
    free(leftArray);
    free(rightArray);
    return;
}


void mergeSort(int *vetor, int n){
    if( n <= 1) return;
    
    int inicio = 0;
    int fim = n;
    int m = (fim + inicio)/2;

    int left_size = m - inicio;
    int right_size = fim - m;

    int *leftArray = malloc(left_size * sizeof(int));
    int *rightArray = malloc(right_size*sizeof(int));


    if(!leftArray || !rightArray){
        free(leftArray);
        free(rightArray);
        return;
    }

    int i = 0; int j = 0;

    for(; i < fim; i++){
        if(i < m){
            leftArray[i] = vetor[i];
        }
        else{
            rightArray[j] = vetor[i];
            j++;
        }
    }

    mergeSort(leftArray, left_size);
    mergeSort(rightArray, right_size);
    merge(leftArray, rightArray, vetor, n);
}


int buscaBinaria(){

}

int novaOrdenacao(){

}

int main(){
    int n; int c;
    scanf("%d %d", &n, &c);

    int *vetor = malloc(n*sizeof(int));
    int n_entradas;

    for(int i = 0; i < n; i++){
        scanf("%d", &n_entradas);
        vetor[i] = n_entradas;
    }

    mergeSort(vetor, n);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    
    free(vetor);

    return 0;
}