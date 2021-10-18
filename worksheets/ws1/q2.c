#include <stdio.h>

struct Person{
    char name[20];
    char gender;
    int age;
    int favouriteNumber;
};

int main(void){

    struct Person user;

    printf("Name: ");
    scanf("%s", user.name);

    printf("Gender (M/F): ");
    scanf(" %c", &user.gender);

    printf("Age: ");
    scanf("%d", &user.age);

    printf("Favourite Number: ");
    scanf("%d", &user.favouriteNumber);
    
    printf("\n\n");
    printf("Name: %s | Gender: %c\n", user.name, user.gender);
    printf("Age: %d | Favourite Number: %d\n\n", user.age, user.favouriteNumber);

    return 0;   
}