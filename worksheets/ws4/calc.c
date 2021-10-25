#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h>  /* isdigit */
#include <stdlib.h> /* atoi, rand, srand */

#define TRUE 1
#define FALSE 0
#define BOOL int

BOOL check_if_number(char *string)
{
    if(strlen(string) == 0){
        printf("Error: Missing Number\n");
        return FALSE;
    }

    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]) && string[i] != '-' && string[i] != '.')
        {
            printf("Error: Invalid Number\n");
            return FALSE;
        }
    }

    return TRUE;
}

BOOL check_if_operator(char* string){
    if(strlen(string) != 1){
        printf("Error: Invalid Operator\n");
        return FALSE;
    }

    if(string[0] == '+'){
        return TRUE;
    }

    if(string[0] == '-' || string[0] == '*' || string[0] == '/'){
        #ifndef DEMO
            return TRUE;
        #endif
        printf("Error: Demo only supports additions.\n");
        return FALSE;
    }

    printf("Error: Invalid Operator\n");
    return FALSE;
}

int main(int argc, char *argv[])
{
    if (argc == 4)
    {

        if (check_if_number(argv[1]) && check_if_operator(argv[2]) && check_if_number(argv[3]))
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
                printf("%.2f %c %.2f = %.2f\n", num1, symbol, num2, result);
            }
        }
    }
    else
    {
        printf("Error: Only 3 Arguments Accepted\n");
    }

    return 0;
}