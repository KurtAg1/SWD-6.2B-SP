#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    const char *sentence = "The best teacher is your last mistake";
    /* more code here */

    char *heapBuffer = (char *)malloc(50);
    char stackBuffer[50];

    strcpy(heapBuffer, sentence);
    strcpy(stackBuffer, sentence);

    printf("Heap Buffer: %s\nStack Buffer: %s\n", heapBuffer, stackBuffer);

    free(heapBuffer);

    return 0;
}