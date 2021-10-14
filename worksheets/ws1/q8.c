#include <stdio.h>

int main(void){

    int num1, num2;

    printf("Input number 1: ");
    scanf("%d", &num1);

    printf("Input number 2: ");
    scanf("%d", &num2);

    printf("The largest number is %d\n", num1 > num2 ? num1 : num2);

    return 0;
}