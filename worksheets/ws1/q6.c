#include <stdio.h>

int main(void){

    int input, hours, minutes, seconds;

    printf("Input a number of seconds: ");
    scanf("%d", &input);
    
    hours = input / 3600;
    input = input - (hours * 3600);

    minutes = input / 60;
    input = input - (minutes * 60);

    seconds = input;

    printf("%d:%d:%d", hours, minutes, seconds);

    return 0;
}