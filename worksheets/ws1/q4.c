#include <stdio.h>

int main(void){

    int i = 0;

    while(1){
        printf("%d\n", i);
        i += 100;
        if(i < 0){
            break;
        }
    }

    return 0;
}