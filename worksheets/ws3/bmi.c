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

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Only Weight (in kg) and Height (in m) arguments expected!");
    }
    else
    {

        if (check_if_number(argv[1]) && check_if_number(argv[2]))
        {
            float weight = atof(argv[1]);
            float height = atof(argv[2]);

            float bmi = weight / (height * height);

            printf("Weight: %.2f kg | Height: %.2f m\n", weight, height);
            printf("Your bmi is %.2f\n", bmi);

            if (bmi < 18.5)
            {
                printf("You are Underweight");
            }
            else if (bmi < 25)
            {
                printf("Your weight is Normal");
            }
            else if (bmi < 30)
            {
                printf("You are Overweight");
            }
            else
            {
                printf("You are Obese");
            }
        }
        else
        {
            printf("Only numbers are allowed!");
        }
    }
    printf("\n\n");
}