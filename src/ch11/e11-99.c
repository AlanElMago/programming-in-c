/* Exercise 99 from chapter 11.
 * I got confused by exercise 07 and ended up making a function that sorts a
 * doubly linked list...
 */

#define ARRAY_SIZE 10

#include <stdio.h>
#include <stdbool.h>

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

int compare_entries(const struct entry *e1, const struct entry *e2)
{
    if (e1->value > e2->value)
        return 1;
    else if (e1->value < e2->value)
        return -1;
    else
        return 0;
}

int list_size(const struct doubly_linked_list *dll)
{
    int size = 0;
    struct entry *current_entry = dll->head;
    
    while (current_entry) {
        current_entry = current_entry->next;
        size++;
    }

    return size;
}

int sort(struct doubly_linked_list *dll)
{
    int size = list_size(dll);
    bool is_sorted = false;
    struct entry *current_entry, *lowest_entry, *entry_flag;

    current_entry = lowest_entry = entry_flag = dll->head;

    for ( ; current_entry != 0; current_entry = current_entry->next)
        if ( compare_entries(current_entry, lowest_entry) == -1 )
            lowest_entry = current_entry;

    if (lowest_entry != dll->head) {
        remove_entry(dll, lowest_entry);
        insert_entry(dll, lowest_entry, dll->head);
        entry_flag = dll->head;
    }

    // selection sort
    while (entry_flag != dll->tail) {

        for ( current_entry = lowest_entry = entry_flag->next;
                current_entry != 0; current_entry = current_entry->next )
            if ( compare_entries(current_entry, lowest_entry) == -1 )
                lowest_entry = current_entry;

        if (lowest_entry != entry_flag->next) {
            remove_entry(dll, lowest_entry);
            insert_entry(dll, entry_flag, lowest_entry);
        }

        entry_flag = entry_flag->next;
    }
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
    struct doubly_linked_list entry_list;

    struct entry entry_array[ARRAY_SIZE] = {
        (struct entry) {.value = 20},
        (struct entry) {.value = 100},
        (struct entry) {.value = 50},
        (struct entry) {.value = 40},
        (struct entry) {.value = 90},
        (struct entry) {.value = 70},
        (struct entry) {.value = 80},
        (struct entry) {.value = 30},
        (struct entry) {.value = 60},
        (struct entry) {.value = 10}
    };

    for ( int i = 0; i < ARRAY_SIZE - 1; i++ )
        entry_array[i].next = &entry_array[i + 1];

    for ( int i = ARRAY_SIZE - 1; i > 0; i-- )
        entry_array[i].prev = &entry_array[i - 1];

    entry_list.head = &entry_array[0];
    entry_list.tail = &entry_array[ARRAY_SIZE - 1];

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&entry_list);
    
    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&entry_list);

    printf("\n\nSorting list...\n\n");
    sort(&entry_list);

    printf("Doubly linked list normal order:\n");
    print_doubly_linked_list(&entry_list);
    
    printf("\n\nDoubly linked list reversed order:\n");
    print_doubly_linked_list_reverse(&entry_list);
    printf("\n\n");

    return 0;
}
