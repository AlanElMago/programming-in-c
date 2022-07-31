/* Exercise 05 from chapter 11.
 * A doubly linked list is a list in which each entry contains a pointer to
 * the preceding entry in the list as well as a pointer to the next entry in
 * the list. Define the appropriate structure definition for a doubly linked
 * list entry and then write a small program that implements a small doubly
 * linked list and prints out the elements of the list.
 */

#include <stdio.h>

struct entry {
    int value;
    struct entry *next;
    struct entry *prev;
};

struct doubly_linked_list {
    struct entry *head;
    struct entry *tail;
};

void print_doubly_linked_list(const struct doubly_linked_list *dll)
{
    struct entry *current_entry = dll->head;

    printf("null <-> ");

    while (current_entry) {
        printf("%i <-> ", current_entry->value);
        current_entry = current_entry->next;
    }

    printf("null");
}

void print_doubly_linked_list_reverse(const struct doubly_linked_list *dll)
{
    struct entry *current_entry = dll->tail;

    printf("null <-> ");

    while (current_entry) {
        printf("%i <-> ", current_entry->value);
        current_entry = current_entry->prev;
    }

    printf("null");
}

int main(void)
{
    struct entry e1, e2, e3, e4, e5, e6, e7;
    struct doubly_linked_list dll;

    e1 = (struct entry) { 50, 0, 0};
    e2 = (struct entry) {100, 0, 0};
    e3 = (struct entry) {150, 0, 0};
    e4 = (struct entry) {200, 0, 0};
    e5 = (struct entry) {250, 0, 0};
    e6 = (struct entry) {300, 0, 0};
    e7 = (struct entry) {350, 0, 0};

    e1.next = &e2;
    e2.next = &e3;
    e3.next = &e4;
    e4.next = &e5;
    e5.next = &e6;
    e6.next = &e7;

    e7.prev = &e6;
    e6.prev = &e5;
    e5.prev = &e4;
    e4.prev = &e3;
    e3.prev = &e2;
    e2.prev = &e1;

    dll.head = &e1;
    dll.tail = &e7;

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&dll);
    
    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&dll);
    printf("\n\n");

    return 0;
}
