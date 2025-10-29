#include <stdio.h>

int main(){

    int num;
    scanf("%d", &num);

    printf("\n");

    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            if(i<10){
                printf("0%d ", i);
            }else{
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    printf("\n");

    
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            if (j == 1){
                printf("%02d", j);
            }
            else{
                printf(" %02d", j);
            }
        }
        printf("\n");
    } 


    return 0;
}