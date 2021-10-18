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
        if (!isdigit(string[i]) && string[i] != '-')
        {
            return FALSE;
        }
    }

    return TRUE;
}

BOOL check_if_symbol(char *string){
    if(strlen(string) != 1){
        return FALSE;
    }

    if(strcmp(string, "+") == 0){
        // Addition
    }
    else if(strcmp(string, "-") == 0){
        // Subtraction
    }
    else if(strcmp(string, "/") == 0){
        // Division
    }
    else if(strcmp(string, "*") == 0){
        // Multiplication
    }

    switch(*string){
        case '+':
        break;
    }
}

int main(int argc, char *argv[])
{

    if (argv == 4)
    {
    }
    else
    {
        printf("Only 3 arguments expected!\n");
    }

    if (argc == 4)
    {

        if (check_if_number(argv[1]) && check_if_number(argv[3]))
        {

        }

        int sum = 0;
        int total = 0;

        for (int i = 1; i < argc; i++)
        {
            if (check_if_number(argv[i]))
            {
                sum += atoi(argv[i]);
                total++;
            }
            else
            {
                printf("Non-numeric input entered (%s)! This will be ignored.\n", argv[i]);
            }
        }

        if (sum != 0 && total != 0)
        {
            printf("The final average is: %d\n", (sum / total));
        }
        else
        {
            printf("No average could be calculated. Please try again.\n");
        }
    }
    else
    {
        printf("At least one argument expected.\n");
    }
}