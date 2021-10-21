#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h>  /* isdigit */
#include <stdlib.h> /* atoi, rand, srand */

#define TRUE 1
#define FALSE 0
#define BOOL int

BOOL check_if_number(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]) && string[i] != '-' && string[i] != '.')
        {
            return FALSE;
        }
    }

    return TRUE;
}

BOOL check_if_calculation(char* string){
    if(strlen(string) != 1){
        return FALSE;
    }

    if(string[0] == '+' || string[0] == '-' || string[0] == '*' || string[0] == '/'){
        return TRUE;
    }

    return FALSE;
}

int main(int argc, char *argv[])
{
    BOOL showAcceptedArguments = TRUE;
    if (argc == 4)
    {

        if (check_if_number(argv[1]) && check_if_calculation(argv[2]) && check_if_number(argv[3]))
        {
            float num1 = atof(argv[1]);
            float num2 = atof(argv[3]);
            char symbol = argv[2][0];

            float result;

            BOOL showResult = TRUE;

            if (symbol == '+')
            {
                // Addition
                result = num1 + num2;
            }
            else if (symbol == '-')
            {
                // Subtraction
                result = num1 - num2;
            }
            else if (symbol == '/')
            {
                // Division
                result = num1 / num2;
            }
            else
            {
                // Multiplication
                result = num1 * num2;
            }

            if (showResult)
            {
                printf("%.2f %c %.2f = %.2f", num1, symbol, num2, result);
                showAcceptedArguments = FALSE;
            }
        }
        else
        {
            printf("Invalid Calculation!\n");
        }
    }
    else
    {
        printf("Invalid Arguments!\n");
    }

    if(showAcceptedArguments){
        printf("Accepted Arguments: \n");
        printf("ARG 1: INTEGER | FLOAT\n");
        printf("ARG 2: + | - | * | /\n");
        printf("ARG 3: INTEGER | FLOAT\n");
    }

    printf("\n\n");
}