#include <stdio.h>

int main(void){

    int num1, num2;

    printf("Input number 1: ");
    scanf("%d", &num1);

    printf("Input number 2: ");
    scanf("%d", &num2);

    if(num1 > num2){
        printf("Number 1 is greater: %d\n", num1);
    }
    else{
        printf("Number 2 is greater: %d\n", num2);
    }
    return 0;
}