#include <stdio.h>
#include <stdlib.h>

int main(){
    //Calloc:
    //Aloca memoria para uma array de elementos e incializa com zero

    
    int num = 0;
    printf("Enter the number of players: ");
    scanf("%d", &num);

    int *scores = calloc(num, sizeof(int));

    if(scores == NULL){
        return 1;
    }

    for(int i = 0; i < num; i++){
        printf("Enter a score #%d: ", i + 1);
        scanf(" %d", &scores[i]);
    }

    for(int i = 0; i < num; i++){
        printf("%d ", scores[i]);
    }

    free(scores);
    scores = NULL;

    return 0;
}