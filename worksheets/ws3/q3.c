#include <stdio.h>
#include <string.h> /* strlen */
#include <ctype.h>  /* isdigit */
#include <stdlib.h> /* atoi, rand, srand */

#define TRUE 1
#define FALSE 0
#define BOOL int

BOOL check_if_number(char *string)
{
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i]) && string[i] != '-') {
            return FALSE;
        }
    }

    return TRUE;
}

int main( int argc, char *argv[] )  {

   if( argc > 1 ) {
       int sum = 0;
       int total = 0;

       for(int i = 1; i < argc; i++){
           if(check_if_number(argv[i])){
               sum += atoi(argv[i]);
               total++;
           }
           else{
               printf("Non-numeric input entered (%s)! This will be ignored.\n", argv[i]);
           }
       }

        if(sum != 0 && total != 0){
            printf("The final average is: %d\n", (sum / total));
        }
        else{
            printf("No average could be calculated. Please try again.\n");
        }
       
   }
   else {
      printf("At least one argument expected.\n");
   }
}