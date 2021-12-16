#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_if_number(char *string)
{
    if(strlen(string) == 0){
        return false;
    }

    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]) && string[i] != '-' && string[i] != '.')
        {
            return false;
        }
    }

    return true;
}

int random_int(int min, int max)
{
   return min + rand() % (max+1 - min);
}

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("No arguments passed!\n");
        return -1;
    }

    if(!check_if_number(argv[1])){
        printf("Invalid Number!\n");
        return -2;
    }

    int size = atoi(argv[1]);

    int stack[size];
    int* heap = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++){
        stack[i] = random_int(0, 1024);
        *(heap + i) = random_int(0, 1024);
    }

    printf("Stack Array:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", stack[i]);
    }

    printf("Heap Array:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", *(heap + i));
    }

    free(heap);

    return 0;
}