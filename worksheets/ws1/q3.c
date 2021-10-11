#include <stdio.h>

int main(void){

    int numbers[10];
    int largest;

    printf("Please enter 10 numbers\n");
    for(int i = 0; i < 10; i++){
        printf("Enter Number #%d: ", (i+1));
        scanf("%d", &numbers[i]);
        if(i == 0 || largest < numbers[i]){
            largest = numbers[i];
        }
    }
    printf("The largest number was: %d\n", largest);

    return 0;
}