#include <stdio.h>

int main(void){

    int num1;
    int num2;

    printf("Please enter 2 numbers to calculate sum, average and sum of the squares of the numbers.\n");

    printf("Enter Number 1: ");
    scanf("%d", &num1);
    
    printf("Enter Number 2: ");
    scanf("%d", &num2);
    
    printf("Sum = %d\n", (num1 + num2));
    printf("Average = %d\n", ((num1 + num2) / 2));
    printf("Sum of square numbers = %d\n", ((num1 * num1) + (num2 * num2)));
    
    return 0;
}