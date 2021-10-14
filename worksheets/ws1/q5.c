#include <stdio.h>

int main(void){

    // input	user input -- hopefully a number
	// temp		used to collect garbage characters
	// status	did the user enter a number?
	int input, temp, status;

    printf("Enter a number between 1 and 100: ");
    status = scanf("%d", &input);
    while(status != 1 || input < 1 || input > 100){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Invalid input! Please enter a number: ");
        status = scanf("%d", &input);
    }

    printf("\nYour number is %d\n", input);

    return 0;
}