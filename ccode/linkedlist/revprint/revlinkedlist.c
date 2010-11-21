#include <stdio.h>

struct node {
    int value;
    struct node* next;
};

int main(int argc, const char *argv[])
{
    struct node a, b, c, d;
    a.value = 2;
    b.value = 3;
    c.value = 5;
    d.value = 7;
    a.next = &b; 
    b.next = &c; 
    c.next = &d; 
    d.next = NULL;
    struct node *p = &a;
    printf ("print linked list: \n");
    while ( p != NULL ) {
        printf ("the value is: %d", p->value);
        p = p->next;
        printf ("\n");
    }
    struct node *head= &a;
    struct node *k= &a;
    p = head->next;
    while ( p != NULL ) {
        head = p;
// p must point to next node before the linked list be divided into two
// sections
        p = p->next; 
        head->next = k;
        k = head;
    }
    a.next = NULL;
       
    printf ("print linked list in reverse order:\n");
    while ( head != NULL ) {
        printf ("the value is: %d", head->value);
        head = head->next;
        printf ("\n");
    }
    return 0;
}
