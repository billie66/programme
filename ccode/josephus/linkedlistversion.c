/*
 * Circular list for josephus problem
 * Copyright 2010 Billie Zhang
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    struct node {
        int num;
        struct node *next;
    };
    int n, m;
    printf("Please input number of soldiers n and a step m:\n");
    scanf("%d%d", &n, &m);
    struct node *head, *p1, *p2;
    head = NULL;
    p1 = malloc(sizeof(struct node *));
    head = p2 = p1;
    int i = 1;
    while (i < n) {
        p1->num = i;
        p1 = malloc(sizeof(struct node ));
        p2->next = p1;
        p2 = p1;
        i++;
    }
    p1->num = n;
    p1->next = head;
    p1 = head;
    struct node *p = head;
    int k = 1, count = 1, j = 1;
    printf("Soldiers will be executed as following order: \n");
    while (1) {
        if (k % m == 0){
            printf("%4d:%4d out ", count, p->num);
            p1->next = p->next;
            p = p->next;
            count++;
            k = 1;
            if (j % 6 == 0)
                printf("\n");
            j++;
        }
        p1 = p; 
        p = p->next;
        k++;
        if (count == n + 1)
            break;
    }
    printf("\n");
    return 0;
}
