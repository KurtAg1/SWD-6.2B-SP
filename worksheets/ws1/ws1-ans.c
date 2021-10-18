#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h>  /* isdigit */
#include <stdlib.h> /* atoi, rand, srand */
#include <time.h>   /* time */

#define TRUE 1
#define FALSE 0
#define BOOL int

void consume_any_leftover_input() {
    int temp;
    while((temp=getchar()) != EOF && temp != '\n');
}

void q1() {
    int num1, num2;
    printf("Enter a number: ");
    if (scanf("%d", &num1) != 1)
        return; //invalid number, exit function
    printf("Enter another number: ");
    if (scanf("%d", &num2) != 1)
        return; //invalid number, exit function

    float average = (num1 + num2) / 2;
    printf("sum: %d\n", num1 + num2);
    printf("average: %f\n", average);
    printf("sum of squares: %d\n", (num1 * num1) + (num2 * num2));
}

struct Persons {
    char name[50];
    char surname[50];
    char address[100];
    int yob;
};

void q2() {
    struct Persons p;
    printf("Enter name: ");
    scanf("%s", p.name);
    printf("Enter surname: ");
    scanf("%s", p.surname);
    printf("Enter address: ");
    scanf("%s", p.address);
    int items_read = 0;
    while (items_read != 1) {
        consume_any_leftover_input();
        printf("Enter a Year of birth: ");
        items_read = scanf("%d", &p.yob);
    }

    printf("%s %s who lives at %s was born in %d\n",
           p.name, p.surname, p.address, p.yob);
}

void q3() {
    int numbers[10] = {0}; //set them all to zero
    int counter = 0, largest = 0;

    while (counter < 10) {
        consume_any_leftover_input();
        printf("%d. Enter a number: ", counter + 1);
        if (scanf("%d", &numbers[counter]) == 1) {
            // valid number input
            if (numbers[counter] > largest)
                largest = numbers[counter];
            counter++;
        }
    }

    printf("Largest: %d\n", largest);
}

void q4()
{
    int number = 0;
    do {
        number += 10000;
        printf("%d\n", number);
    } while (number >= 0);
}

BOOL check_if_number(char *string)
{
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i]) && string[i] != '-') {
            printf("Error: User Input is not numeric!\n");
            return FALSE;
        }
    }

    return TRUE;
}

void q5() {
    char user_input[100];
    BOOL valid = FALSE;

    while (!valid) {
        printf("Enter a number (1-100): ");
        scanf("%s", user_input);
        if (check_if_number(user_input)) {
            int num = atoi(user_input);
            if (num > 100)
                printf("Error: Number is too large!\n");
            else if (num < 1)
                printf("Error: Number is too small!\n");
            else
                valid = TRUE;
        }
    }
}

void q6() {
    int seconds;
    printf("Enter number of seconds: ");
    if (scanf("%d", &seconds) != 1)
        return;
    int days = seconds / (60 * 60 * 24);
    seconds -= days * (60 * 60 * 24);
    int hours = seconds / (60 * 60);
    seconds -= hours * (60 * 60);
    int minutes = seconds / 60;
    seconds -= minutes * 60;

    printf("%d days %d hr %d min %d sec\n", days, hours, minutes, seconds);
}

void q7() {
    char user_input[16];
    int n1, n2;

    printf("Enter a number: ");
    scanf("%s", user_input);
    n1 = atoi(user_input);

    printf("Enter another number: ");
    scanf("%s", user_input);
    n2 = atoi(user_input);

    if (n1 > n2)
        printf("Largest %d\n", n1);
    else
        printf("Largest %d\n", n2);
}

void q8() {
    char user_input[16];
    int n1, n2;

    printf("Enter a number: ");
    scanf("%s", user_input);
    n1 = atoi(user_input);

    printf("Enter another number: ");
    scanf("%s", user_input);
    n2 = atoi(user_input);

    printf("Largest %d\n", (n1 > n2) ? n1 : n2);
}

void q9() {
    time_t t;

    /* Intializes random number generator */
    srand((unsigned)time(&t));

    /* Print 5 random numbers from 0 to 50 */
    for (int i = 0; i < 5; i++)
        printf("%d\n", (rand() % 100) + 1);
}

int main(void) {
    q1();
    return 0;
}
