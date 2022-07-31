/* Exercise 06 from chapter 11.
 * Develop insert_entry and remove_entry functions for a doubly linked list
 * that are similar in function to those developed in the previous exercises
 * for a singly linked list.
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

void insert_entry(struct doubly_linked_list *dll,
        struct entry *precedent, struct entry *e)
{
    // check if the precedent has a next entry
    if ( precedent->next ) {
        e->next = precedent->next;
        precedent->next->prev = e;
    }

    precedent->next = e;
    e->prev = precedent;

    // check if the entry to be inserted is the head of the doubly linked list
    if ( e == dll->head )
        dll->head = precedent;

    // check if the precedent is the tail of the doubly linked list
    if ( precedent == dll->tail)
        dll->tail = e;
}

void remove_entry(struct doubly_linked_list *dll, struct entry *e)
{
    // check if the entry to be removed has a next entry
    if ( e == dll->tail )
        dll->tail = e->prev;
    else
        e->next->prev = e->prev;

    // check if the entry to be removed has a previous entry
    if ( e == dll->head )
        dll->head = e->next;
    else
        e->prev->next = e->next;

    e->next = 0;
    e->prev = 0;
}

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
    
    e1 = (struct entry) {100, 0, 0};
    e2 = (struct entry) {200, 0, 0};
    e3 = (struct entry) {300, 0, 0};

    e4 = (struct entry) { 50, 0, 0};
    e5 = (struct entry) {150, 0, 0};
    e6 = (struct entry) {250, 0, 0};
    e7 = (struct entry) {350, 0, 0};

    e1.next = &e2;
    e2.next = &e3;

    e3.prev = &e2;
    e2.prev = &e1;

    dll.head = &e1;
    dll.tail = &e3;

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&dll);

    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&dll);

    printf("\n\nInserting four entries...\n\n");

    insert_entry(&dll, &e4, &e1);
    insert_entry(&dll, &e1, &e5);
    insert_entry(&dll, &e2, &e6);
    insert_entry(&dll, &e3, &e7);

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&dll);

    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&dll);

    printf("\n\nRemoving four entries...\n\n");

    remove_entry(&dll, &e4);
    remove_entry(&dll, &e5);
    remove_entry(&dll, &e6);
    remove_entry(&dll, &e7);

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&dll);

    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&dll);

    printf("\n\nInserting four entries...\n\n");

    insert_entry(&dll, &e4, &e1);
    insert_entry(&dll, &e1, &e5);
    insert_entry(&dll, &e2, &e6);
    insert_entry(&dll, &e3, &e7);

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&dll);

    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&dll);

    printf("\n\n");

    return 0;
}
