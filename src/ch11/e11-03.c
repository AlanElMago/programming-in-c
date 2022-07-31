/* Exercise 02 from chapter 11.
 * Write a function called insert_entry to insert a new entry into a linked
 * list. Hace the procedure take as arguments a pointer to the list entry to
 * be inserted (of type struct entry as defined in this chapter), and a
 * pointer to an element in the list after which the new entry is to be
 * inserted.
 */

#include <stdio.h>

struct entry {
    int value;
    struct entry *next;
};

struct entry_list
{
    struct entry *head;
};

void insert_entry(struct entry *e, struct entry *precedent)
{
    if ( e->next == (struct entry *) 0 )
        e->next = precedent->next;

    precedent->next = e;
}

void print_entry_list(struct entry *list)
{
    struct entry *current_entry = list;

    while ( current_entry != (struct entry *) 0 ) {
        printf("%i -> ", current_entry->value);
        current_entry = current_entry->next;
    }

    printf("null");
}

int main(void)
{
    struct entry e1, e2, e3, e4, e5, e6, e7;
    struct entry *first_entry;
    struct entry_list el;
    
    e1 = (struct entry) {100, 0};
    e2 = (struct entry) {200, 0};
    e3 = (struct entry) {300, 0};

    e4 = (struct entry) {150, 0};
    e5 = (struct entry) {250, 0};
    e6 = (struct entry) {350, 0};

    e7 = (struct entry) { 50, 0};

    first_entry = &e1;
    e1.next = &e2;
    e2.next = &e3;

    el.head = first_entry;

    print_entry_list(el.head);
    printf("\n\nInserting three more entries...\n\n");

    insert_entry(&e4, &e1);
    insert_entry(&e5, &e2);
    insert_entry(&e6, &e3);

    print_entry_list(el.head);
    printf("\n\nInserting an entry at the beginning of the list...\n\n");

    insert_entry(el.head, &e7);
    el.head = &e7;

    print_entry_list(el.head);
    printf("\n\n");

    return 0;
}
