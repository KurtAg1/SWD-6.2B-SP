#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Persons{
    char id[10];
    short yob;
    char* name;
};

int main()
{
    // create 2 instances of Persons on the stack
    struct Persons p1;
    struct Persons p2;

    // Fill first one with hardcoded values
    strcpy(p1.id, "0456902L");
    p1.yob = 2002;
    p1.name = (char*) malloc(5);
    strcpy(p1.name, "Kurt");

    // Fill second one with user input
    printf("Enter ID: ");
    scanf("%9s", p2.id);
    printf("Enter YOB: ");
    scanf("%hd", &(p2.yob));
    printf("Enter Name: ");
    scanf("%s", p2.name);

    if(p1.yob < p2.yob){
        // print p1 details
        printf("ID: %s | YOB: %d | Name: %s\n", p1.id, p1.yob, p1.name);
    }
    else{
        // print p2 details
        printf("ID: %s | YOB: %d | Name: %s\n", p2.id, p2.yob, p2.name);
    }
    
    return 0;
}