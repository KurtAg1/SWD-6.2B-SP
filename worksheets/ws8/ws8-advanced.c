#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Persons
{
    char name[50];
    char surname[50];
    char address[100];
    int yob;
    struct Persons *next;
} person;

/* Head of the list. NULL means empty list */
person* list_head = NULL;

/* Retrieves the list head record or NULL if list is empty */
person* get_list_head()
{
    return list_head;
}

/* Set first element of the list */
void set_list_head(person* new_head)
{
    list_head = new_head;
}

//     _               _
//    | |__   __ _ ___(_) ___
//    | '_ \ / _` / __| |/ __|
//    | |_) | (_| \__ \ | (__
//    |_.__/ \__,_|___/_|\___|

/* Finds the last allocation entry in list, or returns NULL if list is empty */
person* find_last()
{
    person* currentPerson = get_list_head();
    if (currentPerson == NULL)
    {
        return NULL;
    }

    while (true)
    {
        if (currentPerson->next == NULL)
        {
            return currentPerson;
        }
        currentPerson = currentPerson->next;
    }
}

/* Add a person to the end of the list */
void add_person_at_end(person* new_person)
{
    person* lastPerson = find_last();
    if (lastPerson == NULL)
    {
        set_list_head(new_person);
    }
    else
    {
        lastPerson->next = new_person;
    }
}

/* Prints a string representation of a person */
void print_person(person* p)
{
    printf("Name: %s | Surname: %s | YOB: %d\n", p->name, p->surname, p->yob);
    printf("Address: %s\n", p->address);
}

/* Returns a pointer to the person at the specified index or NULL if nothing is there */
person* get_person_at_index(int index)
{
    person* currentPerson = get_list_head();
    if (currentPerson == NULL || index < 0)
    {
        return NULL;
    }

    int count = 0;
    while (count < index)
    {
        if (currentPerson->next == NULL)
        {
            return NULL;
        }
        currentPerson = currentPerson->next;
        count++;
    }
    return currentPerson;
}

/* Remove a person from list and free memory. Return true if successful */
bool remove_person(person* p)
{
    person* currentPerson = get_list_head();
    while (currentPerson != NULL)
    {
        if (currentPerson->next == p)
        {
            currentPerson->next = p->next;
            break;
        }
        else
        {
            currentPerson = currentPerson->next;
        }
    }
    free(p);

    return true;
}

/* Remove the person at index from list and free memory. Return true if successful */
bool remove_person_at_index(int index)
{
    // check if user wishes to remove head
    if (index == 0)
    {
        // get person after the head
        person* personAfterHead = get_person_at_index(1);
        // free the head
        set_list_head(NULL);
        free(get_person_at_index(0));
        if (personAfterHead != NULL)
        {
            // replace head if necessary
            set_list_head(personAfterHead);
        }
        return true;
    }

    person* previousPerson = get_person_at_index(index - 1);
    if (previousPerson == NULL || previousPerson->next == NULL)
    {
        return false;
    }

    person* personToDelete = previousPerson->next;
    previousPerson->next = personToDelete->next;

    free(personToDelete);

    return true;
}

/* Calculate the total number of persons in the list */
int count_list_size()
{
    person* currentPerson = get_list_head();
    int total = 0;
    while (currentPerson != NULL)
    {
        currentPerson = currentPerson->next;
        total++;
    }
    return total;
}

/* Frees all the persons in the list */
void free_list()
{
    for (int i = count_list_size() - 1; i >= 0; i--)
    {
        remove_person_at_index(i);
    }
}

//               _                               _
//      __ _  __| |_   ____ _ _ __   ___ ___  __| |
//     / _` |/ _` \ \ / / _` | '_ \ / __/ _ \/ _` |
//    | (_| | (_| |\ V / (_| | | | | (_|  __/ (_| |
//     \__,_|\__,_| \_/ \__,_|_| |_|\___\___|\__,_|

/* Add a person to the list at a specific index */
void add_person_at_index(person* new_person, int index)
{
    person* previousPerson = get_person_at_index(index - 1);
    new_person->next = previousPerson->next;
    previousPerson->next = new_person;
}

/* Search the list for a particular name, return NULL if not found */
person* search_by_name(const char *name)
{
    person* currentPerson;
    for (int i = 0; i < count_list_size(); i++)
    {
        currentPerson = get_person_at_index(i);
        if (strcmp(currentPerson->name, name) == 0)
        {
            return currentPerson;
        }
    }
    return NULL;
}

//     _            _   _
//    | |_ ___  ___| |_(_)_ __   __ _
//    | __/ _ \/ __| __| | '_ \ / _` |
//    | ||  __/\__ \ |_| | | | | (_| |
//     \__\___||___/\__|_|_| |_|\__, |
//                              |___/

/* Generate an amount of identical persons - for testing purposes */
void generate_persons(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        person* p = (person*)malloc(sizeof(person));
        sprintf(p->name, "John %d", i);
        strcpy(p->surname, "Doe");
        strcpy(p->address, "unknown");
        p->yob = 2000 + i;
        add_person_at_end(p);
    }
}

int main(int argc, char *argv[])
{
    // Basic Testing

    //confirm that the list is empty when we start
    assert(count_list_size() == 0);
    //generate 10 persons and check that the count is 10
    generate_persons(10);
    assert(count_list_size() == 10);
    //confirm that there is a person at index 0 and 9
    assert(get_person_at_index(0) != NULL);
    assert(get_person_at_index(9) != NULL);
    //get the last person (index 9) and confirm yob
    person* last = get_person_at_index(9);
    assert(last->yob == 2009);
    //remove last person and confirm it was successful
    assert(remove_person_at_index(9) == true);
    assert(count_list_size() == 9);
    //free list and confirm count is zero
    free_list();
    assert(count_list_size() == 0);

    // Advanced Testing

    //confirm that the list is empty when we start
    assert(count_list_size() == 0);
    //generate 5 persons and check that the count is 5
    generate_persons(5);
    assert(count_list_size() == 5);

    person* p = (person*)malloc(sizeof(person));
    strcpy(p->name, "John 5");
    strcpy(p->surname, "Doe");
    strcpy(p->address, "unknown");
    p->yob = 2021;

    add_person_at_index(p, 3);
    // make sure that person was added
    assert(count_list_size() == 6);

    // make sure that the person was added at the correct index
    person* personAtIndex = get_person_at_index(3);
    assert(strcmp(personAtIndex->name, p->name) == 0);

    // check that search by name function works
    person* search = search_by_name(p->name);
    assert(search->yob == p->yob);

    //free list and confirm count is zero
    free_list();
    assert(count_list_size() == 0);


    return 0;
}