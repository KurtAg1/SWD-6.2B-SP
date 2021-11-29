#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char* fileName;
    int mark = 0;
    int passed = 0;
    int total = 0;
    FILE* input;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: count_marks <textfile>\n");
        return -1;
    }
    // args were passed
    fileName = argv[1];
    input = fopen(fileName, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Failed to open %s!\n", fileName);
        return 1;
    }

    while (!feof(input))
    {
        if (fscanf(input, "%d", &mark) == 1)
        {
            if(mark >= 50){
                passed++;
            }
            total++;
        }
    }

    fclose(input);

    float percentage = (float)passed/total * 100.0;
    printf("Pass rate is %d of %d (%.2f%%)\n", passed, total, percentage);

    return 0;
}