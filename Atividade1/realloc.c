#include <stdio.h>
#include <stdlib.h>

int main(){

    // Realloc() = Reallocation -> Resize previosly allocated memory
    // realloc(ptr, bytes)

    int num = 0;
    printf("Enter the number of players: ");
    scanf("%d", &num);

    float *prices = malloc(num * sizeof(float));
    if(prices == NULL){
        return 1;
    }

    for( int i = 0; i < num; i++){
        printf("Enter price number #%d:", i + 1);
        scanf("%f", &prices[i]);
    }

    int newNumber = 0;
    printf("Enter a new Number of prices:");
    scanf("%d", &newNumber);

    float *temp = realloc(prices, newNumber * sizeof(float) );

    if( temp == NULL ){
        return 1;
    }else{
        prices = temp;
        temp = NULL;

        for( int i = num; i < newNumber; i++){
        printf("Enter price number #%d:", i + 1);
        scanf("%f", &prices[i]);
    }
    
        for( int i = 0; i < newNumber; i++){
            printf("$%.2f ", prices[i]);
        }
    }


    free(prices);
    prices = NULL;

    return 0;
}