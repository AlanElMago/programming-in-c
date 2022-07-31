/* Exercise 03 from chapter 11.
 * Write a function called remove_entry to remove an entry from a linked list.
 * The sole argument to the procedure should be a pointer to the list. Have
 * the function remove the entry after the one ppinted to by the argument.
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

void remove_entry(struct entry *precedent)
{
    precedent->next = precedent->next->next;
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
    
    e1 = (struct entry) { 50, 0};
    e2 = (struct entry) {100, 0};
    e3 = (struct entry) {150, 0};
    e4 = (struct entry) {200, 0};
    e5 = (struct entry) {250, 0};
    e6 = (struct entry) {300, 0};
    e7 = (struct entry) {350, 0};

    first_entry = &e1;
    e1.next = &e2;
    e2.next = &e3;
    e3.next = &e4;
    e4.next = &e5;
    e5.next = &e6;
    e6.next = &e7;

    el.head = first_entry;

    print_entry_list(el.head);
    printf("\n\nRemoving three entries...\n\n");

    remove_entry(&e1);
    remove_entry(&e3);
    remove_entry(&e5);

    print_entry_list(el.head);
    printf("\n\n");

    return 0;
}
