#ifndef REVISION_LO2_STACK_LIST_INCLUDED
#define REVISION_LO2_STACK_LIST_INCLUDED

#include <stdbool.h>

/* Stack (linked list) item */
struct item
{
    int value;
    struct item* next;
};

/* Returns true if value exists in the linked list (or false if it doesn't) */
bool exists(struct item *head, int value)
{
    struct item *current = head;
    while(current != NULL){
        if(current->value == value){
            return true;
        }
        current = current->next;
    }
    return false;
}

/* Prints out all the items in a linked list */
void print_stack(struct item *item)
{
    bool first = true;
    while(item != NULL){
        printf("%s%d", first ? "" : "->", item->value);
        first = false;
        item = item->next;
    }
    printf("\n");
}

/* Add an item at the begining of a linked list */
void push_item(struct item** head_ref, int new_value)
{
    if(exists(*head_ref, new_value))
        return;
    
    struct item* new_node = (struct item*) malloc(sizeof(struct item));
    new_node->value = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Remove an item at the begining of a linked list */
void pop_item(struct item** head_ref)
{
    struct item* old_head = (*head_ref);

    (*head_ref) = (*head_ref)->next;

    free(old_head);
}

void free_list(struct item *head)
{
    struct item *to_free, *temp = head;

    while(temp != NULL){
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
}

#endif // REVISION_LO2_STACK_LIST_INCLUDED