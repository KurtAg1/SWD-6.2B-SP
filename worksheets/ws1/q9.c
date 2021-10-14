#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    srand(time(0));

    for(int i = 0; i < 5; i++){
        printf("Random Number #%d: %d\n", (i+1), rand());
    }
    return 0;
}