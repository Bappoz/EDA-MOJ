#include <stdio.h>
#include <stdlib.h>

int main(void){

    char *grades = malloc(10 * sizeof(char));

    if(grades == NULL){
        printf("Memory allocation failed");
        return 1;    
    }


    for(int i = 0; i < 10; i++ ){
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", *(grades + i));

    }

    for(int i =0; i < 10; i++){
        printf("%c ", (grades + i));
    }


    free(grades);
    grades = NULL;

    return 0;
}