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

   if( argc == 3 ) {
       // 2 arguments passed
       if(check_if_number(argv[1]) && check_if_number(argv[2])){
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        if(a < b){
            printf("%d is smaller!\n", a);
        }
        else{
            printf("%d is smaller!\n", b);
        }
       }
       else{
           printf("Error: Only numbers are allowed!\n");
       }   
   }
   else if( argc > 3 ) {
      printf("Too many arguments supplied.\n");
   }
   else {
      printf("Two arguments expected.\n");
   }
}