#include <stdio.h>
#include <string.h>

void getGrade(char *grade, int mark)
{
    if (mark < 50)
    {
        strcpy(grade, "F");
    }
    else if (mark < 65)
    {
        strcpy(grade, "C");
    }
    else if (mark < 75)
    {
        strcpy(grade, "B");
    }
    else if (mark < 90)
    {
        strcpy(grade, "A");
    }
    else
    {
        strcpy(grade, "A+");
    }
}

int main(int argc, char *argv[])
{
    char name[64], grade[3];
    int mark;
    FILE* input;
    FILE* output;

    if (argc < 2)
    {
        fprintf(stderr, "No input file was given!\n");
        return -1;
    }
    // args were passed
    input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Failed to open file!\n");
        return -1;
    }

    // create output file buffer
    output = fopen("outputfile.csv", "w");

    if (output == NULL)
    {
        fprintf(stderr, "Failed to create output file!\n");
        return -1;
    }

    fprintf(stdout, "Processing rows ");

    while (!feof(input))
    {
        if (fscanf(input, "%s\t%d", name, &mark) == 2)
        {
            getGrade(grade, mark);
            fprintf(output, "%s,%d,%s\n", name, mark, grade);
            fprintf(stdout, "."); // show progress
        }
    }

    fclose(input);
    fclose(output);

    fprintf(stdout, "\nFinished. Results in 'outputfile.csv'\n");

    return 0;
}